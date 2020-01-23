#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
    OpenGEODE - A tiny SDL Editor for TASTE

    This module generates textual SDL code (PR format)
    by parsing the graphical symbols.

    Copyright (c) 2012-2016 European Space Agency

    Designed and implemented by Maxime Perrotin

    Contact: maxime.perrotin@esa.int
"""


import logging
from collections import deque
from itertools import chain
from functools import singledispatch

from . import genericSymbols, sdlSymbols, Connectors

LOG = logging.getLogger(__name__)

__all__ = ['parse_scene', 'generate']


class Indent(deque):
    ''' Extension of the deque class to support automatic indenting '''
    indent = 0

    def append(self, string):
        ''' Redefinition of the append to insert the indent pattern '''
        super(Indent, self).append('    ' * Indent.indent + string)


def parse_scene(scene, full_model=False):
    ''' Return the PR string for a complete scene
        Optionally, also generate the SYSTEM structure, with channels, etc. '''
    pr_data = Indent()
    if full_model:
        # Generate a complete SDL system - to have everything in a single file
        # (1) get system name
        # (2) get signal directions from the connection of the process to env
        # (3) generate all the text
        processes = list(scene.processes)
        system_name = str(processes[0]) if processes else u'OpenGEODE'
        pr_data.append('system {};'.format(system_name))
        Indent.indent += 1
        channels, routes = Indent(), Indent()
        for each in scene.texts:
            # Parse text areas to retrieve signal names USELESS
           pr = generate(each)
           pr_data.extend(pr)
        if processes:
            to_env = processes[0].connection.out_sig
            from_env = processes[0].connection.in_sig
            if to_env or from_env:
                channels.append('channel c')
                Indent.indent += 1

                routes.append('signalroute r')
                if from_env:
                    from_txt = 'from env to {} with {};'\
                               .format(system_name, from_env)
                    channels.append(from_txt)
                    Indent.indent += 1
                    routes.append(from_txt)
                    Indent.indent -= 1
                if to_env:
                    to_txt = 'from {} to env with {};'\
                              .format(system_name, to_env)
                    channels.append(to_txt)
                    Indent.indent += 1
                    routes.append(to_txt)
                    Indent.indent -= 1
                Indent.indent -= 1
                channels.append('endchannel;')
                Indent.indent += 1
                routes.append('connect c and r;')
            Indent.indent -= 1

        pr_data.extend(channels)
        pr_data.append('block {};'.format(system_name))
        Indent.indent += 1
        pr_data.extend(routes)
        for each in processes:
            pr_data.extend(generate(each))
        Indent.indent -= 1
        pr_data.append('endblock;')
        Indent.indent -= 1
        pr_data.append('endsystem;')

    else:
        for each in scene.processes:
            if ":" in str(each):
                # ignore instances of process type
                continue
            #pr_data.extend(generate(each))
            # Only one process is supported - return now because
            # the text areas must not be parsed - some may have been
            # generated automatically to display the list of signals
            # and external procedures when interface was generated by TASTE
            return list(generate(each))

        for each in chain(scene.texts, scene.procs, scene.start):
            pr_data.extend(generate(each))
        for each in scene.floating_labels:
            pr_data.extend(generate(each))
        composite = set(scene.composite_states.keys())
        for each in scene.states:
            if each.is_composite():
                # Ignore via clause:
                statename = str(each).split()[0].lower()
                try:
                    composite.remove(statename)
                    sub_state = generate(each, composite=True, nextstate=False)
                    if sub_state:
                        sub_state.reverse()
                        pr_data.extendleft(sub_state)
                except KeyError:
                    pass
            pr_data.extend(generate(each, nextstate=False))
    return list(pr_data)


def cif_coord(name, symbol):
    ''' PR string for the CIF coordinates/size of a symbol '''
    return u'/* CIF {symb} ({x}, {y}), ({w}, {h}) */'.format(
            symb=name,
            x=int(symbol.scenePos().x()), y=int(symbol.scenePos().y()),
            w=int(symbol.boundingRect().width()),
            h=int(symbol.boundingRect().height()))


def hyperlink(symbol):
    ''' PR string for the optional hyperlink associated to a symbol '''
    return u"/* CIF Keep Specific Geode HyperLink '{}' */".format(
                                                         symbol.text.hyperlink)


def common(name, symbol):
    ''' PR string format that is shared by most symbols '''
    result = Indent()
    result.append(cif_coord(name, symbol))
    if symbol.text.hyperlink:
        result.append(hyperlink(symbol))
    result.append(u'{} {}{}'.format(name, str(symbol.text), ';'
                                if not symbol.comment else ''))
    if symbol.comment:
        result.extend(generate(symbol.comment))
    return result


def recursive_aligned(symbol):
    ''' Get the branch following symbol '''
    result = Indent()
    Indent.indent += 1
    next_symbol = symbol.next_aligned_symbol()
    while next_symbol:
        result.extend(generate(next_symbol))
        next_symbol = next_symbol.next_aligned_symbol()
    Indent.indent -= 1
    return result


@singledispatch
def generate(symbol, *args, **kwargs):
    ''' Generate text for a symbol, recursively or not - return a list of
        strings '''
    _ = symbol
    raise NotImplementedError('Unsupported AST construct: {}'
                              .format(type(symbol)))
    return Indent()


@generate.register(genericSymbols.Comment)
def _comment(symbol, **kwargs):
    ''' Optional comment linked to a symbol '''
    result = Indent()
    result.append(cif_coord('comment', symbol))
    if symbol.text.hyperlink:
        result.append(hyperlink(symbol))
    result.append(u'comment \'{}\';'.format(str(symbol.text)))
    return result


@generate.register(sdlSymbols.Input)
def _input(symbol, recursive=True, **kwargs):
    ''' Input symbol or branch if recursive is set '''
    result = common('input', symbol)
    if recursive:
        result.extend(recursive_aligned(symbol))
    return result


@generate.register(sdlSymbols.ContinuousSignal)
def _continuous_signal(symbol, recursive=True, **kwargs):
    ''' "Provided" symbol or branch if recursive is set '''
    result = common('provided', symbol)
    if recursive:
        result.extend(recursive_aligned(symbol))
    return result


@generate.register(sdlSymbols.Connect)
def _connect(symbol, recursive=True, **kwargs):
    ''' Connect symbol or branch if recursive is set '''
    result = common('connect', symbol)
    if recursive:
        result.extend(recursive_aligned(symbol))
    return result


@generate.register(sdlSymbols.Output)
def _output(symbol, **kwargs):
    ''' Output symbol '''
    return common('output', symbol)


@generate.register(sdlSymbols.Decision)
def _decision(symbol, recursive=True, **kwargs):
    ''' Decision symbol or branch if recursive is set '''
    result = common('decision', symbol)
    if recursive:
        else_branch = None
        Indent.indent += 1
        for answer in symbol.branches():
            if str(answer).lower().strip() == 'else':
                else_branch = generate(answer)
            else:
                result.extend(generate(answer))
        if else_branch:
            result.extend(else_branch)
        Indent.indent -= 1
    result.append(u'enddecision;')
    return result


@generate.register(sdlSymbols.DecisionAnswer)
def _decisionanswer(symbol, recursive=True, **kwargs):
    ''' Decision Answer symbol or branch if recursive is set '''
    result = Indent()
    result.append(cif_coord('ANSWER', symbol))
    ans = str(symbol)
    if ans.lower().strip() != u'else':
        ans = u'({})'.format(ans)
    if symbol.text.hyperlink:
        result.append(hyperlink(symbol))
    result.append(u'{}:'.format(ans))
    if recursive:
        result.extend(recursive_aligned(symbol))
    return result


@generate.register(sdlSymbols.Join)
def _join(symbol, **kwargs):
    ''' Join symbol '''
    return common('join', symbol)


@generate.register(sdlSymbols.ProcedureStop)
def _procedurestop(symbol, **kwargs):
    ''' Procedure Stop symbol '''
    return common('return', symbol)


@generate.register(sdlSymbols.Task)
def _task(symbol, **kwargs):
    ''' Task symbol '''
    return common('task', symbol)


@generate.register(sdlSymbols.ProcedureCall)
def _procedurecall(symbol, **kwargs):
    ''' Procedure call symbol '''
    result = Indent()
    result.append(cif_coord('PROCEDURECALL', symbol))
    if symbol.text.hyperlink:
        result.append(hyperlink(symbol))
    result.append(u'call {}{}'.format(str(symbol.text), ';'
                                      if not symbol.comment else ''))
    if symbol.comment:
        result.extend(generate(symbol.comment))
    return result


@generate.register(sdlSymbols.TextSymbol)
def _textsymbol(symbol, **kwargs):
    ''' Text Area symbol '''
    result = Indent()
    result.append(cif_coord('TEXT', symbol))
    if symbol.text.hyperlink:
        result.append(hyperlink(symbol))
    # Align nicely the text (parser will dedent it)
    for line in str(symbol.text).split('\n'):
        result.append(line)
    result.append(u'/* CIF ENDTEXT */')
    return result


@generate.register(sdlSymbols.Label)
def _label(symbol, recursive=True, **kwargs):
    ''' Label symbol or branch if recursive is set '''
    result = Indent()
    result.append(cif_coord('label', symbol))
    if symbol.text.hyperlink:
        result.append(hyperlink(symbol))
    if symbol.common_name == 'floating_label':
        result.append(u'connection {}:'.format(str(symbol)))
        if recursive:
            result.extend(recursive_aligned(symbol))
        result.append(u'/* CIF End Label */')
        result.append(u'endconnection;')
    else:
        result.append(u'{}:'.format(str(symbol)))
    return result


@generate.register(sdlSymbols.State)
def _state(symbol, recursive=True, nextstate=True, composite=False, cpy=False,
           **kwargs):
    ''' State/Nextstate symbol or branch if recursive is set '''
    if nextstate and symbol.hasParent:
        result = common('NEXTSTATE', symbol)
    elif not composite and symbol.hasParent and not cpy \
            and not [each for each in symbol.childSymbols()
            if not isinstance(each, genericSymbols.Comment)]:
        # If nextstate has no child, don't generate anything
        result = []
    elif not composite:
        result = common('state', symbol)
        if recursive:
            Indent.indent += 1
            # Generate code for INPUT and CONNECT symbols
            for each in (symb for symb in symbol.childSymbols()
                         if isinstance(symb, (sdlSymbols.Input,
                                              sdlSymbols.ContinuousSignal))):
                result.extend(generate(each))
            Indent.indent -= 1
        result.append(u'endstate;')
    else:
        # Generate code for a nested state
        result = Indent()
        agg = ' aggregation' if symbol.nested_scene.is_aggregation() else ''#if not list(symbol.nested_scene.start) else ''
        result.append('state{} {};'.format(agg, str(symbol).split()[0]))
        result.append('substructure')
        Indent.indent += 1
        entry_points, exit_points = [], []
        for each in symbol.nested_scene.start:
            if str(each):
                entry_points.append(str(each))
        for each in symbol.nested_scene.returns:
            if str(each) != u'no_name':
                exit_points.append(str(each))
        if entry_points:
            result.append(u'in ({});'.format(','.join(entry_points)))
        if exit_points:
            result.append(u'out ({});'.format(','.join(exit_points)))
        Indent.indent += 1
        result.extend(parse_scene(symbol.nested_scene))
        Indent.indent -= 1
        Indent.indent -= 1
        result.append(u'endsubstructure;')
    return result


@generate.register(sdlSymbols.Process)
@generate.register(sdlSymbols.ProcessType)
def _process(symbol, recursive=True, **kwargs):
    ''' Process symbol and inner content if recursive is set '''
    name = "process type" if isinstance(symbol, sdlSymbols.ProcessType) \
            else "process"
    #result = common(name, symbol)
    result = Indent()
    result.append(cif_coord('PROCESS', symbol))
    result.append(u"{} {}{}".format(name, str(symbol.text), ";" if
        not symbol.comment else ""))
    if symbol.comment:
        result.extend(generate(symbol.comment))

    if recursive and symbol.nested_scene:
        Indent.indent += 1
        result.extend(parse_scene(symbol.nested_scene))
        Indent.indent -= 1
    if ":" not in str(symbol):
        result.append(u'endprocess {}{};'
                .format("type " if isinstance(symbol, sdlSymbols.ProcessType)
                                else "",
                        str(symbol)))
    return result


@generate.register(sdlSymbols.Procedure)
def _procedure(symbol, recursive=True, **kwargs):
    ''' Procedure symbol or branch if recursive is set '''
    result = common('procedure', symbol)
    if recursive and symbol.nested_scene:
        Indent.indent += 1
        result.extend(parse_scene(symbol.nested_scene))
        Indent.indent -= 1
    result.append('endprocedure;')
    return result


@generate.register(sdlSymbols.Start)
def _start(symbol, recursive=True, **kwargs):
    ''' START symbol or branch if recursive is set '''
    result = Indent()
    result.append(cif_coord('START', symbol))
    result.append(u'START{via}{comment}'
                  .format(via=(' ' + str(symbol) + ' ')
                          if str(symbol).replace('START', '') else '',
                          comment=';' if not symbol.comment else ''))
    if symbol.comment:
        result.extend(generate(symbol.comment))
    if recursive:
        result.extend(recursive_aligned(symbol))
    return result


@generate.register(Connectors.Signalroute)
def _channel(symbol, recursive=True, **kwargs):
    ''' Signalroute at block level '''
    result = Indent()
    result.append('signalroute c')
    Indent.indent += 1
    if symbol.out_sig:
        result.append('from {} to env with {};'.format(str(symbol.parent),
                                                       symbol.out_sig))
    if symbol.in_sig:
        result.append('from env to {} with {};'.format(str(symbol.parent),
                                                       symbol.in_sig))
    Indent.indent -= 1
    return result



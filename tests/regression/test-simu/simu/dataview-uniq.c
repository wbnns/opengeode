/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>
#include "dataview-uniq.h"

#if !defined(_MSC_VER) || _MSC_VER >= 1800
void T_UInt32_Initialize(T_UInt32* pVal)
{
    *pVal = (T_UInt32) 0;
}
#endif

 
flag T_UInt32_IsConstraintValid(const T_UInt32* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (*pVal <= 4294967295LL);
	*pErrCode = ret ? 0 : ERR_T_UInt32;

	return ret;
}

flag T_UInt32_Equal(const T_UInt32* pVal1, const T_UInt32* pVal2)
{
	flag ret=TRUE;
	
	ret = (*pVal1 == *pVal2);

	return ret;
}

flag T_UInt32_Encode(const T_UInt32* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? T_UInt32_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 4294967295LL);
    }

	return ret;
}

flag T_UInt32_Decode(T_UInt32* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : 268435457;

	return ret;
}

flag T_UInt32_ACN_Encode(const T_UInt32* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? T_UInt32_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 4294967295LL);
    }

	return ret;
}

flag T_UInt32_ACN_Decode(T_UInt32* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
    *pErrCode = ret ? 0 : 268435458;
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void TASTE_Peek_id_Initialize(TASTE_Peek_id* pVal)
{
    *pVal = (TASTE_Peek_id) 0;
}
#endif

 
flag TASTE_Peek_id_IsConstraintValid(const TASTE_Peek_id* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (*pVal <= 4294967295LL);
	*pErrCode = ret ? 0 : ERR_TASTE_Peek_id;

	return ret;
}

flag TASTE_Peek_id_Equal(const TASTE_Peek_id* pVal1, const TASTE_Peek_id* pVal2)
{
	flag ret=TRUE;
	
	ret = (*pVal1 == *pVal2);

	return ret;
}

flag TASTE_Peek_id_Encode(const TASTE_Peek_id* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? TASTE_Peek_id_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 4294967295LL);
    }

	return ret;
}

flag TASTE_Peek_id_Decode(TASTE_Peek_id* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : 268435459;

	return ret;
}

flag TASTE_Peek_id_ACN_Encode(const TASTE_Peek_id* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? TASTE_Peek_id_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 4294967295LL);
    }

	return ret;
}

flag TASTE_Peek_id_ACN_Decode(TASTE_Peek_id* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
    *pErrCode = ret ? 0 : 268435460;
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void TASTE_Peek_id_list_Initialize(TASTE_Peek_id_list* pVal)
{
    *pVal = (TASTE_Peek_id_list) {    .nCount = 1,    .arr = 
    {
        0        
    }
};
}
#endif

 
flag TASTE_Peek_id_list_IsConstraintValid(const TASTE_Peek_id_list* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 10);
	*pErrCode = ret ? 0 : ERR_TASTE_Peek_id_list;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = TASTE_Peek_id_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag TASTE_Peek_id_list_Equal(const TASTE_Peek_id_list* pVal1, const TASTE_Peek_id_list* pVal2)
{
	flag ret=TRUE;
	int i1=0;
	
	ret = (pVal1->nCount == pVal2->nCount);
	for(i1 = 0; ret && i1<pVal1->nCount; i1++) 
	{
		ret = TASTE_Peek_id_Equal(&pVal1->arr[i1], &pVal2->arr[i1]);
	}

	return ret;
}

flag TASTE_Peek_id_list_Encode(const TASTE_Peek_id_list* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? TASTE_Peek_id_list_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 10);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = TASTE_Peek_id_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag TASTE_Peek_id_list_Decode(TASTE_Peek_id_list* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 10);
	*pErrCode = ret ? 0 : 268435461;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = TASTE_Peek_id_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}

flag TASTE_Peek_id_list_ACN_Encode(const TASTE_Peek_id_list* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    int i1=0;

    ret = bCheckConstraints ? TASTE_Peek_id_list_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 10);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = TASTE_Peek_id_ACN_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag TASTE_Peek_id_list_ACN_Decode(TASTE_Peek_id_list* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    int i1=0;
    asn1SccSint nCount;
    ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 10);
    *pErrCode = ret ? 0 : 268435462;
    pVal->nCount = (long)nCount;
    	
    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
    {
    	ret = TASTE_Peek_id_ACN_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void FixedIntList_Initialize(FixedIntList* pVal)
{
    *pVal = (FixedIntList) {    .arr = 
    {
        0        
    }
};
}
#endif

 
flag FixedIntList_IsConstraintValid(const FixedIntList* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = TRUE; *pErrCode = 0;
	i1 = 0;
	while (ret && (i1< 3)) {
	    ret = TASTE_Peek_id_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag FixedIntList_Equal(const FixedIntList* pVal1, const FixedIntList* pVal2)
{
	flag ret=TRUE;
	int i1=0;
	
	for(i1 = 0; ret && i1<3; i1++) 
	{
		ret = TASTE_Peek_id_Equal(&pVal1->arr[i1], &pVal2->arr[i1]);
	}

	return ret;
}

flag FixedIntList_Encode(const FixedIntList* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? FixedIntList_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    	
	    for(i1=0; (i1 < (int)3) && ret; i1++) 
	    {
	    	ret = TASTE_Peek_id_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag FixedIntList_Decode(FixedIntList* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	int i1=0;

		
	for(i1=0; (i1 < (int)3) && ret; i1++) 
	{
		ret = TASTE_Peek_id_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}

flag FixedIntList_ACN_Encode(const FixedIntList* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    int i1=0;

    ret = bCheckConstraints ? FixedIntList_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    	
	    for(i1=0; (i1 < (int)3) && ret; i1++) 
	    {
	    	ret = TASTE_Peek_id_ACN_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag FixedIntList_ACN_Decode(FixedIntList* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    int i1=0;
    	
    for(i1=0; (i1 < (int)3) && ret; i1++) 
    {
    	ret = TASTE_Peek_id_ACN_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MyEnum_Initialize(MyEnum* pVal)
{
    *pVal = (MyEnum) one;
}
#endif

 
flag MyEnum_IsConstraintValid(const MyEnum* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (((((*pVal == one) || (*pVal == two)) || (*pVal == three)) || (*pVal == four)) || (*pVal == five));
	*pErrCode = ret ? 0 : ERR_MyEnum;

	return ret;
}

flag MyEnum_Equal(const MyEnum* pVal1, const MyEnum* pVal2)
{
	flag ret=TRUE;
	
	ret = (*pVal1 == *pVal2);

	return ret;
}

flag MyEnum_Encode(const MyEnum* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? MyEnum_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) 
	    {
	        case one:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 4);
	        	break;
	        case two:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 4);
	        	break;
	        case three:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 2, 0, 4);
	        	break;
	        case four:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 3, 0, 4);
	        	break;
	        case five:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 4, 0, 4);
	        	break;
	        default:
	    	    *pErrCode = 1073741825; //COVERAGE_IGNORE
	    	    ret = FALSE;            //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag MyEnum_Decode(MyEnum* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint enumIndex;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &enumIndex, 0, 4);
	*pErrCode = ret ? 0 : 268435463;
	if (ret) {
	    switch(enumIndex) 
	    {
	        case 0: 
	            *pVal = one;
	            break;
	        case 1: 
	            *pVal = two;
	            break;
	        case 2: 
	            *pVal = three;
	            break;
	        case 3: 
	            *pVal = four;
	            break;
	        case 4: 
	            *pVal = five;
	            break;
	        default:
		        *pErrCode = 1073741826;     //COVERAGE_IGNORE
		        ret = FALSE;                //COVERAGE_IGNORE
	    }
	}

	return ret;
}

flag MyEnum_ACN_Encode(const MyEnum* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    asn1SccUint intVal = 0;

    ret = bCheckConstraints ? MyEnum_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) { 
	        case one:
	            intVal = 0;
	            break;
	        case two:
	            intVal = 1;
	            break;
	        case three:
	            intVal = 2;
	            break;
	        case four:
	            intVal = 3;
	            break;
	        case five:
	            intVal = 4;
	            break;
	        default:
	            ret = FALSE;                            //COVERAGE_IGNORE
	            *pErrCode = 1073741827;      //COVERAGE_IGNORE
	    }
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, intVal, 0, 4);
    }

	return ret;
}

flag MyEnum_ACN_Decode(MyEnum* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    asn1SccUint intVal = 0;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, &intVal, 0, 4);
    *pErrCode = ret ? 0 : 268435464;
    if (ret) {
        switch (intVal) {
            case 0:
                *pVal = one;
                break;
            case 1:
                *pVal = two;
                break;
            case 2:
                *pVal = three;
                break;
            case 3:
                *pVal = four;
                break;
            case 4:
                *pVal = five;
                break;
        default:
            ret = FALSE;                            //COVERAGE_IGNORE
            *pErrCode = 1073741828;      //COVERAGE_IGNORE
        };
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MySimpleSeq_a_Initialize(MySimpleSeq_a* pVal)
{
    *pVal = (MySimpleSeq_a) 0;
}
#endif

 
flag MySimpleSeq_a_IsConstraintValid(const MySimpleSeq_a* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (*pVal <= 255);
	*pErrCode = ret ? 0 : ERR_MySimpleSeq_a;

	return ret;
}

flag MySimpleSeq_a_Equal(const MySimpleSeq_a* pVal1, const MySimpleSeq_a* pVal2)
{
	flag ret=TRUE;
	
	ret = (*pVal1 == *pVal2);

	return ret;
}

flag MySimpleSeq_a_Encode(const MySimpleSeq_a* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? MySimpleSeq_a_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 255);
    }

	return ret;
}

flag MySimpleSeq_a_Decode(MySimpleSeq_a* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 255);
	*pErrCode = ret ? 0 : 268435465;

	return ret;
}

flag MySimpleSeq_a_ACN_Encode(const MySimpleSeq_a* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? MySimpleSeq_a_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 255);
    }

	return ret;
}

flag MySimpleSeq_a_ACN_Decode(MySimpleSeq_a* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 255);
    *pErrCode = ret ? 0 : 268435466;
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MySimpleSeq_Initialize(MySimpleSeq* pVal)
{
    *pVal = (MySimpleSeq) {
    .a = 0,
    .b = FALSE,
    .c = one
};
}
#endif

 
flag MySimpleSeq_IsConstraintValid(const MySimpleSeq* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = MySimpleSeq_a_IsConstraintValid(&pVal->a, pErrCode);
	if (ret) {
	    ret = TRUE; *pErrCode = 0;
	    if (ret) {
	        ret = MyEnum_IsConstraintValid(&pVal->c, pErrCode);
	    
	    }
	}

	return ret;
}

flag MySimpleSeq_Equal(const MySimpleSeq* pVal1, const MySimpleSeq* pVal2)
{
	flag ret=TRUE;
	
	ret = MySimpleSeq_a_Equal(&pVal1->a, &pVal2->a);
	if (ret) {
	    ret = ( (pVal1->b && pVal2->b) || (!pVal1->b && !pVal2->b));
	    if (ret) {
	        ret = MyEnum_Equal(&pVal1->c, &pVal2->c);
	    
	    }
	}

	return ret;
}

flag MySimpleSeq_Encode(const MySimpleSeq* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? MySimpleSeq_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode a */
	    ret = MySimpleSeq_a_Encode(&pVal->a, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode b */
	        BitStream_AppendBit(pBitStrm,pVal->b);
	        if (ret) {
	            /*Encode c */
	            ret = MyEnum_Encode(&pVal->c, pBitStrm, pErrCode, FALSE);
	        
	        }
	    }
    }

	return ret;
}

flag MySimpleSeq_Decode(MySimpleSeq* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode a */
	ret = MySimpleSeq_a_Decode(&pVal->a, pBitStrm, pErrCode);
	if (ret) {
	    /*Decode b */
	    ret = BitStream_ReadBit(pBitStrm, &pVal->b);
	    *pErrCode = ret ? 0 : 268435467;
	    if (ret) {
	        /*Decode c */
	        ret = MyEnum_Decode(&pVal->c, pBitStrm, pErrCode);
	    
	    }
	}


	return ret;
}

flag MySimpleSeq_ACN_Encode(const MySimpleSeq* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? MySimpleSeq_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode a */
	    ret = MySimpleSeq_a_ACN_Encode(&pVal->a, pBitStrm, pErrCode, FALSE);
	    if (ret) {
	        /*Encode b */
	        {
	        	static byte true_data[] = {0x80};
	        	static byte false_data[] = {0x7F};
	            byte* tmp = pVal->b ? true_data : false_data; 
	            BitStream_AppendBits(pBitStrm, tmp, 1);
	        }
	        if (ret) {
	            /*Encode c */
	            ret = MyEnum_ACN_Encode(&pVal->c, pBitStrm, pErrCode, FALSE);

	        }

	    }

    }

	return ret;
}

flag MySimpleSeq_ACN_Decode(MySimpleSeq* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    *pErrCode = 0;
    /*Decode a */
    ret = MySimpleSeq_a_ACN_Decode(&pVal->a, pBitStrm, pErrCode);
    if (ret) {
        /*Decode b */
        {
        	static byte tmp[] = {0x80};
        	ret = BitStream_ReadBitPattern(pBitStrm, tmp, 1, &pVal->b);
            *pErrCode = ret ? 0 : 268435468;
        }
        if (ret) {
            /*Decode c */
            ret = MyEnum_ACN_Decode(&pVal->c, pBitStrm, pErrCode);

        }

    }


    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MySeqOf_elm_Initialize(MySeqOf_elm* pVal)
{
    *pVal = (MySeqOf_elm) 0;
}
#endif

 
flag MySeqOf_elm_IsConstraintValid(const MySeqOf_elm* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (*pVal <= 10);
	*pErrCode = ret ? 0 : ERR_MySeqOf_elm;

	return ret;
}

flag MySeqOf_elm_Equal(const MySeqOf_elm* pVal1, const MySeqOf_elm* pVal2)
{
	flag ret=TRUE;
	
	ret = (*pVal1 == *pVal2);

	return ret;
}

flag MySeqOf_elm_Encode(const MySeqOf_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? MySeqOf_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 10);
    }

	return ret;
}

flag MySeqOf_elm_Decode(MySeqOf_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 10);
	*pErrCode = ret ? 0 : 268435469;

	return ret;
}

flag MySeqOf_elm_ACN_Encode(const MySeqOf_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? MySeqOf_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 10);
    }

	return ret;
}

flag MySeqOf_elm_ACN_Decode(MySeqOf_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 10);
    *pErrCode = ret ? 0 : 268435470;
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MySeqOf_Initialize(MySeqOf* pVal)
{
    *pVal = (MySeqOf) {    .nCount = 1,    .arr = 
    {
        0        
    }
};
}
#endif

 
flag MySeqOf_IsConstraintValid(const MySeqOf* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 3);
	*pErrCode = ret ? 0 : ERR_MySeqOf;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = MySeqOf_elm_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag MySeqOf_Equal(const MySeqOf* pVal1, const MySeqOf* pVal2)
{
	flag ret=TRUE;
	int i1=0;
	
	ret = (pVal1->nCount == pVal2->nCount);
	for(i1 = 0; ret && i1<pVal1->nCount; i1++) 
	{
		ret = MySeqOf_elm_Equal(&pVal1->arr[i1], &pVal2->arr[i1]);
	}

	return ret;
}

flag MySeqOf_Encode(const MySeqOf* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? MySeqOf_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 3);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = MySeqOf_elm_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag MySeqOf_Decode(MySeqOf* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 3);
	*pErrCode = ret ? 0 : 268435471;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = MySeqOf_elm_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}

flag MySeqOf_ACN_Encode(const MySeqOf* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    int i1=0;

    ret = bCheckConstraints ? MySeqOf_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 3);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = MySeqOf_elm_ACN_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag MySeqOf_ACN_Decode(MySeqOf* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    int i1=0;
    asn1SccSint nCount;
    ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 3);
    *pErrCode = ret ? 0 : 268435472;
    pVal->nCount = (long)nCount;
    	
    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
    {
    	ret = MySeqOf_elm_ACN_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MySetOf_elm_Initialize(MySetOf_elm* pVal)
{
    *pVal = (MySetOf_elm) 0;
}
#endif

 
flag MySetOf_elm_IsConstraintValid(const MySetOf_elm* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = (*pVal <= 10);
	*pErrCode = ret ? 0 : ERR_MySetOf_elm;

	return ret;
}

flag MySetOf_elm_Equal(const MySetOf_elm* pVal1, const MySetOf_elm* pVal2)
{
	flag ret=TRUE;
	
	ret = (*pVal1 == *pVal2);

	return ret;
}

flag MySetOf_elm_Encode(const MySetOf_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? MySetOf_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 10);
    }

	return ret;
}

flag MySetOf_elm_Decode(MySetOf_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 10);
	*pErrCode = ret ? 0 : 268435473;

	return ret;
}

flag MySetOf_elm_ACN_Encode(const MySetOf_elm* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? MySetOf_elm_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, *pVal, 0, 10);
    }

	return ret;
}

flag MySetOf_elm_ACN_Decode(MySetOf_elm* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 10);
    *pErrCode = ret ? 0 : 268435474;
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MySetOf_Initialize(MySetOf* pVal)
{
    *pVal = (MySetOf) {    .nCount = 1,    .arr = 
    {
        0        
    }
};
}
#endif

 
flag MySetOf_IsConstraintValid(const MySetOf* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	int i1=0;
	*pErrCode=0;

	(void)pVal;

	ret = (1 <= pVal->nCount && pVal->nCount <= 3);
	*pErrCode = ret ? 0 : ERR_MySetOf;
	i1 = 0;
	while (ret && (i1< pVal->nCount)) {
	    ret = MySetOf_elm_IsConstraintValid(&pVal->arr[i1], pErrCode);
	    i1 = i1+1;
	}

	return ret;
}

flag MySetOf_Equal(const MySetOf* pVal1, const MySetOf* pVal2)
{
	flag ret=TRUE;
	int i1=0;
	
	ret = (pVal1->nCount == pVal2->nCount);
	for(i1 = 0; ret && i1<pVal1->nCount; i1++) 
	{
		ret = MySetOf_elm_Equal(&pVal1->arr[i1], &pVal2->arr[i1]);
	}

	return ret;
}

flag MySetOf_Encode(const MySetOf* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	int i1=0;
    
	ret = bCheckConstraints ? MySetOf_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 3);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = MySetOf_elm_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag MySetOf_Decode(MySetOf* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nCount;
	int i1=0;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 3);
	*pErrCode = ret ? 0 : 268435475;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = MySetOf_elm_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
	}

	return ret;
}

flag MySetOf_ACN_Encode(const MySetOf* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    int i1=0;

    ret = bCheckConstraints ? MySetOf_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 1, 3);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	ret = MySetOf_elm_ACN_Encode(&pVal->arr[i1], pBitStrm, pErrCode, FALSE);
	    }
    }

	return ret;
}

flag MySetOf_ACN_Decode(MySetOf* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    int i1=0;
    asn1SccSint nCount;
    ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 3);
    *pErrCode = ret ? 0 : 268435476;
    pVal->nCount = (long)nCount;
    	
    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
    {
    	ret = MySetOf_elm_ACN_Decode(&pVal->arr[i1], pBitStrm, pErrCode);
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MyChoice_b_Initialize(MyChoice_b* pVal)
{
    *pVal = (MyChoice_b) aa;
}
#endif

 
flag MyChoice_b_IsConstraintValid(const MyChoice_b* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = ((*pVal == aa) || (*pVal == bb));
	*pErrCode = ret ? 0 : ERR_MyChoice_b;

	return ret;
}

flag MyChoice_b_Equal(const MyChoice_b* pVal1, const MyChoice_b* pVal2)
{
	flag ret=TRUE;
	
	ret = (*pVal1 == *pVal2);

	return ret;
}

flag MyChoice_b_Encode(const MyChoice_b* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? MyChoice_b_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) 
	    {
	        case aa:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 1);
	        	break;
	        case bb:   
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 1);
	        	break;
	        default:
	    	    *pErrCode = 1073741829; //COVERAGE_IGNORE
	    	    ret = FALSE;            //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag MyChoice_b_Decode(MyChoice_b* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint enumIndex;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &enumIndex, 0, 1);
	*pErrCode = ret ? 0 : 268435477;
	if (ret) {
	    switch(enumIndex) 
	    {
	        case 0: 
	            *pVal = aa;
	            break;
	        case 1: 
	            *pVal = bb;
	            break;
	        default:
		        *pErrCode = 1073741830;     //COVERAGE_IGNORE
		        ret = FALSE;                //COVERAGE_IGNORE
	    }
	}

	return ret;
}

flag MyChoice_b_ACN_Encode(const MyChoice_b* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    asn1SccUint intVal = 0;

    ret = bCheckConstraints ? MyChoice_b_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(*pVal) { 
	        case aa:
	            intVal = 0;
	            break;
	        case bb:
	            intVal = 1;
	            break;
	        default:
	            ret = FALSE;                            //COVERAGE_IGNORE
	            *pErrCode = 1073741831;      //COVERAGE_IGNORE
	    }
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, intVal, 0, 1);
    }

	return ret;
}

flag MyChoice_b_ACN_Decode(MyChoice_b* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    asn1SccUint intVal = 0;
    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, &intVal, 0, 1);
    *pErrCode = ret ? 0 : 268435478;
    if (ret) {
        switch (intVal) {
            case 0:
                *pVal = aa;
                break;
            case 1:
                *pVal = bb;
                break;
        default:
            ret = FALSE;                            //COVERAGE_IGNORE
            *pErrCode = 1073741832;      //COVERAGE_IGNORE
        };
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MyChoice_Initialize(MyChoice* pVal)
{
    *pVal = (MyChoice) {
    .kind = a_PRESENT,
    .u = { .a = FALSE}
};
}
#endif

 
flag MyChoice_IsConstraintValid(const MyChoice* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	switch (pVal->kind) {
	    case a_PRESENT :
	        ret = TRUE; *pErrCode = 0;
	        break;
	    case b_PRESENT :
	        ret = MyChoice_b_IsConstraintValid(&pVal->u.b, pErrCode);
	        break;
	    default:
		    *pErrCode = 805306369;   //COVERAGE_IGNORE
		    ret = FALSE;                    //COVERAGE_IGNORE
	}

	return ret;
}

flag MyChoice_Equal(const MyChoice* pVal1, const MyChoice* pVal2)
{
	flag ret=TRUE;
	
	ret = (pVal1->kind == pVal2->kind);
	if (ret) {
		switch(pVal1->kind) 
		{
		case a_PRESENT:
			ret = ( (pVal1->u.a && pVal2->u.a) || (!pVal1->u.a && !pVal2->u.a));
			break;
		case b_PRESENT:
			ret = MyChoice_b_Equal(&pVal1->u.b, &pVal2->u.b);
			break;
		default:
			ret = FALSE;    //COVERAGE_IGNORE
		}
	}

	return ret;
}

flag MyChoice_Encode(const MyChoice* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? MyChoice_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(pVal->kind) 
	    {
	    case a_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 1);
	    	BitStream_AppendBit(pBitStrm,pVal->u.a);
	    	break;
	    case b_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 1);
	    	ret = MyChoice_b_Encode(&pVal->u.b, pBitStrm, pErrCode, FALSE);
	    	break;
	    default:
	        *pErrCode = 805306370;         //COVERAGE_IGNORE
	        ret = FALSE;                    //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag MyChoice_Decode(MyChoice* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	asn1SccSint nChoiceIndex;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nChoiceIndex, 0, 1);
	*pErrCode = ret ? 0 : 268435479;
	if (ret) {
	    switch(nChoiceIndex) 
	    {
	    case 0:
	    	pVal->kind = a_PRESENT;
	    	ret = BitStream_ReadBit(pBitStrm, &pVal->u.a);
	    	*pErrCode = ret ? 0 : 268435480;
	    	break;
	    case 1:
	    	pVal->kind = b_PRESENT;
	    	ret = MyChoice_b_Decode(&pVal->u.b, pBitStrm, pErrCode);
	    	break;
	    default:
	        *pErrCode = 805306371;     //COVERAGE_IGNORE
	        ret = FALSE;                //COVERAGE_IGNORE
	    }
	}

	return ret;
}

flag MyChoice_ACN_Encode(const MyChoice* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? MyChoice_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(pVal->kind) 
	    {
	    case a_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 1);
	    	{
	    		static byte true_data[] = {0x80};
	    		static byte false_data[] = {0x7F};
	    	    byte* tmp = pVal->u.a ? true_data : false_data; 
	    	    BitStream_AppendBits(pBitStrm, tmp, 1);
	    	}
	    	break;
	    case b_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 1);
	    	ret = MyChoice_b_ACN_Encode(&pVal->u.b, pBitStrm, pErrCode, FALSE);
	    	break;
	    default:
	        *pErrCode = 805306372;         //COVERAGE_IGNORE
	        ret = FALSE;                    //COVERAGE_IGNORE
	    }
    }

	return ret;
}

flag MyChoice_ACN_Decode(MyChoice* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    asn1SccSint nChoiceIndex;
    ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nChoiceIndex, 0, 1);
    *pErrCode = ret ? 0 : 268435481;
    if (ret) {
        switch(nChoiceIndex) 
        {
        case 0:
        	pVal->kind = a_PRESENT;
        	{
        		static byte tmp[] = {0x80};
        		ret = BitStream_ReadBitPattern(pBitStrm, tmp, 1, &pVal->u.a);
        	    *pErrCode = ret ? 0 : 268435482;
        	}
        	break;
        case 1:
        	pVal->kind = b_PRESENT;
        	ret = MyChoice_b_ACN_Decode(&pVal->u.b, pBitStrm, pErrCode);
        	break;
        default:
            *pErrCode = 805306373;     //COVERAGE_IGNORE
            ret = FALSE;                //COVERAGE_IGNORE
        }
    }
    return ret;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1800
void MySeq_Initialize(MySeq* pVal)
{
    *pVal = (MySeq) {
    .a = FALSE,
    .b = {
        .kind = a_PRESENT,
        .u = { .a = FALSE}
    }
};
}
#endif

 
flag MySeq_IsConstraintValid(const MySeq* pVal, int* pErrCode)
{
    
    flag ret = TRUE;
	*pErrCode=0;

	(void)pVal;

	ret = TRUE; *pErrCode = 0;
	if (ret) {
	    ret = MyChoice_IsConstraintValid(&pVal->b, pErrCode);
	
	}

	return ret;
}

flag MySeq_Equal(const MySeq* pVal1, const MySeq* pVal2)
{
	flag ret=TRUE;
	
	ret = ( (pVal1->a && pVal2->a) || (!pVal1->a && !pVal2->a));
	if (ret) {
	    ret = MyChoice_Equal(&pVal1->b, &pVal2->b);
	
	}

	return ret;
}

flag MySeq_Encode(const MySeq* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
    
	ret = bCheckConstraints ? MySeq_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode a */
	    BitStream_AppendBit(pBitStrm,pVal->a);
	    if (ret) {
	        /*Encode b */
	        ret = MyChoice_Encode(&pVal->b, pBitStrm, pErrCode, FALSE);
	    
	    }
    }

	return ret;
}

flag MySeq_Decode(MySeq* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;

	/*Decode a */
	ret = BitStream_ReadBit(pBitStrm, &pVal->a);
	*pErrCode = ret ? 0 : 268435483;
	if (ret) {
	    /*Decode b */
	    ret = MyChoice_Decode(&pVal->b, pBitStrm, pErrCode);
	
	}


	return ret;
}

flag MySeq_ACN_Encode(const MySeq* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    ret = bCheckConstraints ? MySeq_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode a */
	    {
	    	static byte true_data[] = {0x80};
	    	static byte false_data[] = {0x7F};
	        byte* tmp = pVal->a ? true_data : false_data; 
	        BitStream_AppendBits(pBitStrm, tmp, 1);
	    }
	    if (ret) {
	        /*Encode b */
	        ret = MyChoice_ACN_Encode(&pVal->b, pBitStrm, pErrCode, FALSE);

	    }

    }

	return ret;
}

flag MySeq_ACN_Decode(MySeq* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
    *pErrCode = 0;
    /*Decode a */
    {
    	static byte tmp[] = {0x80};
    	ret = BitStream_ReadBitPattern(pBitStrm, tmp, 1, &pVal->a);
        *pErrCode = ret ? 0 : 268435484;
    }
    if (ret) {
        /*Decode b */
        ret = MyChoice_ACN_Decode(&pVal->b, pBitStrm, pErrCode);

    }


    return ret;
}


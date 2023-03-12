#include "EaCore/EaUtilities.h"
#include <string.h>

EaVoidPointer eaMemSet(EaVoidPointer pDestination, EaS32 nValue, EaSize nLength)
{
    return memset(pDestination, nValue, nLength);
}

EaVoidPointer eaMemCopy(EaVoidPointer pDestination, EaConstVoidPointer pSource, EaSize nLength)
{
    return memcpy(pDestination, pSource, nLength);
}

EaBool dtsSwap(EaVoidPointer pValue, EaSize nValueSize)
{
    EaBool bResult = FALSE;

    if(pValue != NULL && nValueSize > 0)
    {
        EaBytePointer pValueAsByte = (EaBytePointer)pValue;
        EaSize nHalfValueSize = nValueSize / 2;
        EaSize nValueIndex = 0;
        for(nValueIndex = 0; nValueIndex < nHalfValueSize; nValueIndex++)
        {
            EaByte temp = pValueAsByte[nValueIndex];
            pValueAsByte[nValueIndex] = pValueAsByte[nValueSize - nValueIndex - 1];
            pValueAsByte[nValueSize - nValueIndex - 1] = temp;
        }
        bResult = TRUE;
    }
    else
    {
        bResult = FALSE;
    }

    return bResult;
}
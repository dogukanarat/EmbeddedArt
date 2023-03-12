#ifndef INCLUDED_DTSUTILITIES_H
#define INCLUDED_DTSUTILITIES_H

#include "EaCore/EaCommon.h"

/// @brief 
/// @param destination 
/// @param value 
/// @param length 
/// @return 
EaVoidPointer eaMemSet(EaVoidPointer pDestination, EaS32 nValue, EaSize nLength);

/// @brief
/// @param destination
/// @param source
/// @param length
/// @return
EaVoidPointer eaMemCopy(EaVoidPointer pDestination, EaConstVoidPointer pSource, EaSize nLength);

/// @brief
/// @param pValue
/// @param nValueSize
/// @return
EaBool eaSwap(EaVoidPointer pValue, EaSize nValueSize);

#endif // INCLUDED_DTSUTILITIES_H

#ifndef INCLUDED_EACIRCULARBUFFER_H
#define INCLUDED_EACIRCULARBUFFER_H

#include "EaCore/EaCommon.h"

/// @brief
typedef enum
{
    EA_CIRCULAR_BUFFER_NO_ERROR = 0,
    EA_CIRCULAR_BUFFER_ERROR_INVALID_ARGUMENT = -1,
    EA_CIRCULAR_BUFFER_ERROR_BUFFER_SIZE = -2,
    EA_CIRCULAR_BUFFER_ERROR_TIMEOUT = -3,
} EaCircularBufferError;

/// @brief
typedef struct
{
    EaMutexInterface iMutex;
    EaBytePointer pBuffer;
    EaSize nBufferSize;
    EaSize nChunkSize;
} EaCircularBufferInit;

/// @brief 
typedef struct
{
    EaCircularBufferInit init;
    EaSize nBufferHead;
    EaSize nBufferTail;
} EaCircularBuffer;

/// @brief 
/// @param self 
/// @return 
EaResult eaCircularBufferInitialize(EaCircularBuffer *self, EaCircularBufferInit init);

/// @brief 
/// @param self 
/// @return 
EaResult eaCircularBufferClear(EaCircularBuffer *self);

/// @brief 
/// @param self 
/// @param pSource 
/// @param nSourceSize 
/// @return 
EaResult eaCircularBufferPush(EaCircularBuffer *self, EaConstBytePointer pSource, EaSize nSourceSize);

/// @brief 
/// @param self 
/// @param pDestination 
/// @param nDestinationSize 
/// @return 
EaResult eaCircularBufferPop(EaCircularBuffer *self, EaBytePointer pDestination, EaSize nDestinationSize);

#endif // INCLUDED_EACIRCULARBUFFER_H
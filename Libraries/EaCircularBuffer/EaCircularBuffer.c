#include "EaCircularBuffer/EaCircularBuffer.h"
#include "EaCore/EaUtilities.h"

EaResult eaCircularBufferInitialize(EaCircularBuffer *self, EaCircularBufferInit init)
{
    EaResult result = EA_CIRCULAR_BUFFER_NO_ERROR;

    if (self == NULL)
    {
        result = EA_CIRCULAR_BUFFER_ERROR_INVALID_ARGUMENT;
        return result;
    }

    if (init.nBufferSize == 0 && init.iMutex.pOpen == NULL && init.iMutex.pClose == NULL && init.iMutex.pLock == NULL && init.iMutex.pMutex == NULL)
    {
        result = EA_CIRCULAR_BUFFER_ERROR_INVALID_ARGUMENT;
    }

    if (result == EA_CIRCULAR_BUFFER_NO_ERROR)
    {
        self->init = init;
        self->nBufferHead = 0;
        self->nBufferTail = 0;

        if (init.iMutex.pOpen != NULL)
        {
            result = init.iMutex.pOpen(&init.iMutex.pMutex);
        }
    }

    return result;
}

EaResult eaCircularBufferClear(EaCircularBuffer *self)
{
    EaResult result = EA_CIRCULAR_BUFFER_NO_ERROR;

    if (self->init.pBuffer == NULL)
    {
        result = EA_CIRCULAR_BUFFER_ERROR_INVALID_ARGUMENT;
    }
    else
    {
        self->nBufferHead = 0;
        self->nBufferTail = 0;
    }

    return result;
}

EaResult eaCircularBufferPush(
    EaCircularBuffer *self,
    EaConstBytePointer pSource,
    EaSize nSourceSize)
{
    EaResult result = FALSE;

    if (self->init.pBuffer == NULL && nSourceSize > self->init.nBufferSize)
    {
        result = EA_CIRCULAR_BUFFER_ERROR_INVALID_ARGUMENT;
    }

    if (result == EA_CIRCULAR_BUFFER_NO_ERROR)
    {
        EaSize nFirstCopySize = 0;
        EaSize nSecondCopySize = 0;

        if (self->init.iMutex.pLock != NULL)
        {
            result = self->init.iMutex.pLock(&self->init.iMutex.pMutex);
        }

        if (result == EA_CIRCULAR_BUFFER_NO_ERROR)
        {
            if ((self->nBufferTail + nSourceSize) > self->init.nBufferSize)
            {
                nFirstCopySize = self->init.nBufferSize - self->nBufferTail;
                nSecondCopySize = nSourceSize - nFirstCopySize;
            }
            else
            {
                nFirstCopySize = nSourceSize;
                nSecondCopySize = 0;
            }

            eaMemCopy(
                (EaVoidPointer)(self->init.pBuffer + self->nBufferTail),
                (EaConstVoidPointer)(pSource),
                nFirstCopySize);

            self->nBufferTail += nFirstCopySize;

            if (self->nBufferTail >= self->init.nBufferSize)
            {
                self->nBufferTail = 0;
            }

            if (nSecondCopySize > 0)
            {
                eaMemCopy(
                    (EaVoidPointer)(self->init.pBuffer + self->nBufferTail),
                    (EaConstVoidPointer)(pSource + nFirstCopySize),
                    nSecondCopySize);

                self->nBufferTail += nSecondCopySize;
            }

            if (self->init.iMutex.pUnlock != NULL)
            {
                result = self->init.iMutex.pUnlock(&self->init.iMutex.pMutex);
            }
        }
    }

    return result;
}

EaResult eaCircularBufferPop(
    EaCircularBuffer *self,
    EaBytePointer pDestination,
    EaSize nDestinationSize)
{
    EaResult result = EA_CIRCULAR_BUFFER_NO_ERROR;

    if (self->init.pBuffer == NULL && nDestinationSize > self->init.nBufferSize)
    {
        result = EA_CIRCULAR_BUFFER_ERROR_INVALID_ARGUMENT;
    }

    if (result == EA_CIRCULAR_BUFFER_NO_ERROR)
    {
        EaSize nFirstCopySize = 0;
        EaSize nSecondCopySize = 0;

        if (self->init.iMutex.pLock != NULL)
        {
            result = self->init.iMutex.pLock(&self->init.iMutex.pMutex);
        }

        if (result == EA_CIRCULAR_BUFFER_NO_ERROR)
        {
            if ((self->nBufferHead + nDestinationSize) > self->init.nBufferSize)
            {
                nFirstCopySize = self->init.nBufferSize - self->nBufferHead;
                nSecondCopySize = nDestinationSize - nFirstCopySize;
            }
            else
            {
                nFirstCopySize = nDestinationSize;
                nSecondCopySize = 0;
            }

            eaMemCopy(
                (EaVoidPointer)(pDestination),
                (EaConstVoidPointer)(self->init.pBuffer + self->nBufferHead),
                nFirstCopySize);

            self->nBufferHead += nFirstCopySize;
            if (self->nBufferHead >= self->init.nBufferSize)
            {
                self->nBufferHead = 0;
            }

            if (nSecondCopySize > 0)
            {
                eaMemCopy(
                    (EaVoidPointer)(pDestination + nFirstCopySize),
                    (EaConstVoidPointer)(self->init.pBuffer + self->nBufferHead),
                    nSecondCopySize);

                self->nBufferHead += nSecondCopySize;
            }

            if (self->init.iMutex.pUnlock != NULL)
            {
                self->init.iMutex.pUnlock(&self->init.iMutex.pMutex);
            }
        }
    }

    return result;
}
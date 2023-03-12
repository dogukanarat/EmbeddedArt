//
// Created by DFA on 25.02.2023.
//
#include <stdio.h>
#include <semaphore.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include "Osal.h"
#include "EaCircularBuffer/EaCircularBuffer.h"

static struct
{
    uint8_t pBuffer[100];
    EaCircularBuffer circularBuffer;
} self;

int main(int argc, char *argv[])
{
    EaCircularBufferInit init = {0};
    init.iMutex.pOpen = callbackMutexOpen;
    init.iMutex.pClose = callbackMutexClose;
    init.iMutex.pLock = callbackMutexLock;
    init.iMutex.pUnlock = callbackMutexUnlock;
    init.pBuffer = self.pBuffer;
    init.nBufferSize = sizeof(self.pBuffer);

    eaCircularBufferInitialize(&self.circularBuffer, init);

    char* pString = "Hello World";

    eaCircularBufferPush(
            &self.circularBuffer,
            (EaConstBytePointer)pString,
            (EaSize)strlen(pString)
            );


   char buffer[100];

   eaCircularBufferPop(&self.circularBuffer, (EaBytePointer)buffer, 11);

   printf("%s", buffer);

    return 0;
}
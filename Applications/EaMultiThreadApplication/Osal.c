//
// Created by DFA on 25.02.2023.
//
#include <semaphore.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "Osal.h"

EaResult callbackMutexOpen(EaVoidPointer *ppMutex)
{
    static uint16_t nSemaphoreCount = 0;
    char pSemName[50];

    sprintf(pSemName, "SemCircularBuffer%d", nSemaphoreCount++);

    // initialize the pSemaphore
    *ppMutex = sem_open(pSemName, O_CREAT, 0644, 1);

    return 0;
}

EaResult callbackMutexClose(EaVoidPointer *ppMutex)
{
    sem_close(*ppMutex);

    return 0;
}

EaResult callbackMutexLock(EaVoidPointer *ppMutex)
{
    sem_wait(*ppMutex);

    return 0;
}

EaResult callbackMutexUnlock(EaVoidPointer *ppMutex)
{
    sem_post(*ppMutex);

    return 0;
}


//
// Created by DFA on 25.02.2023.
//

#ifndef EMBEDDEDART_OSAL_H
#define EMBEDDEDART_OSAL_H

#include "EaCore/EaCommon.h"

EaResult callbackMutexOpen(EaVoidPointer *mutex);
EaResult callbackMutexClose(EaVoidPointer *mutex);
EaResult callbackMutexLock(EaVoidPointer *mutex);
EaResult callbackMutexUnlock(EaVoidPointer *mutex);

#endif //EMBEDDEDART_OSAL_H

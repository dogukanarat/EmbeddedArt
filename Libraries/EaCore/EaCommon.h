#ifndef INCLUDED_EACOMMON_H
#define INCLUDED_EACOMMON_H

#include "stdint.h"

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef EA_EXPECT
#include <assert.h>
#define EA_EXPECT(A) assert(A);
#endif

#ifndef EA_NO_IMPLEMENTATION
#define EA_NO_IMPLEMENTATION
#endif

#ifndef EA_UNUSED_PARAMETER
#define EA_UNUSED_PARAMETER(A) (void)(A);
#endif

#ifndef EA_RESULT
#define EA_RESULT(libraryCode, errorCode) (libraryCode << 7 & errorCode)
#endif

#ifndef EA_TYPE_DEFINITION
#define EA_TYPE_DEFINITION
typedef uint8_t EaU8;
typedef uint16_t EaU16;
typedef uint32_t EaU32;
typedef uint64_t EaU64;
typedef int8_t EaS8;
typedef int16_t EaS16;
typedef int32_t EaS32;
typedef int64_t EaS64;
typedef float EaF32;
typedef double EaF64;
typedef EaU8 EaBool;
typedef void EaVoid;
typedef EaVoid *EaVoidPointer;
typedef const EaVoidPointer EaConstVoidPointer;
typedef EaU8 EaByte;
typedef EaByte *EaBytePointer;
typedef const EaBytePointer EaConstBytePointer;
typedef EaU32 EaSize;
typedef EaS16 EaResult;
#endif

#ifndef EA_ENDIAN_DEFINITION
#define EA_ENDIAN_DEFINITION
typedef enum
{
    EA_ENDIAN_LITTLE = 0,
    EA_ENDIAN_BIG
} EaEndian;
#endif

#ifndef EA_MUTEX_INTERFACE
#define EA_MUTEX_INTERFACE
typedef struct
{
    EaVoidPointer pMutex;
    EaResult (*pOpen)(EaVoidPointer *pMutex);
    EaResult (*pClose)(EaVoidPointer *pMutex);
    EaResult (*pLock)(EaVoidPointer *pMutex);
    EaResult (*pUnlock)(EaVoidPointer *pMutex);
} EaMutexInterface;
#endif

#endif // INCLUDED_EACOMMON_H

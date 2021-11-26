#ifndef HEAP_H
#define HEAP_H

#include "inttypes.h"

typedef struct CHeapBlock {
    /* 0x00 */ struct CHeapBlock* freeLast; // "pFreeLast"
    /* 0x04 */ struct CHeapBlock* freeNext; // "pFreeNext"
    /* 0x08 */ struct CHeapBlock* usedLast; // "pUsedLast"
    /* 0x0C */ struct CHeapBlock* usedNext; // "pUsedNext"
    /* 0x10 */ uint32_t used; // "Used"
    /* 0x14 */ uint32_t free; // "Free"
} CHeapBlock; /* sizeof = 0x18 */

typedef struct {
    /* 0x00 */ uint32_t start; // "MemStart"
    /* 0x04 */ uint32_t end; // "MemEnd"
    /* 0x08 */ struct CHeapBlock* freeHead; // "pFreeHead"
    /* 0x0C */ struct CHeapBlock* freeTail; // "pFreeTail"
    /* 0x10 */ struct CHeapBlock* usedHead; // "pUsedHead"
} CHeap; /* sizeof = 0x14 */

extern CHeap gHeap;

#define Malloc(SIZE) (CHeap__Alloc(&gHeap, SIZE))

extern void CHeap__Construct(CHeap* thisx, void* start, uint32_t length);
extern void* CHeap__Alloc(CHeap* thisx, SIZE_TYPE size);

#endif


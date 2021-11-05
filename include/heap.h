#ifndef HEAP_H
#define HEAP_H

#include "inttypes.h"

typedef struct CHeapBlock {
    /* 0x00 */ struct CHeapBlock* pFreeLast;
    /* 0x04 */ struct CHeapBlock* pFreeNext;
    /* 0x08 */ struct CHeapBlock* pUsedLast;
    /* 0x0C */ struct CHeapBlock* pUsedNext;
    /* 0x10 */ uint32_t used;
    /* 0x14 */ uint32_t free;
} CHeapBlock; /* sizeof = 0x18 */

typedef struct {
    /* 0x00 */ uint32_t start;
    /* 0x04 */ uint32_t end;
    /* 0x08 */ struct CHeapBlock* pFreeHead;
    /* 0x0C */ struct CHeapBlock* pFreeTail;
    /* 0x10 */ struct CHeapBlock* pUsedHead;
} CHeap; /* sizeof = 0x14 */

extern void CHeap__Construct(CHeap* thisx, void* start, uint32_t length);

#endif


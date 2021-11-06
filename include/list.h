#ifndef LIST_H
#define LIST_H

#include "inttypes.h"

typedef struct {
    /* 0x00 */ void* head; // "pHead"
    /* 0x04 */ void* tail; // "pTail"
    /* 0x08 */ uint32_t lastOffset; // "LastOffset"
    /* 0x0C */ uint32_t nextOffset; // "NextOffset"
    /* 0x10 */ uint32_t size; // "Size"
} CList; /* sizeof = 0x14 */

extern void CList__Construct(CList* thisx, uint32_t lastOffset, uint32_t nextOffset);
extern void CList__AddTail(CList* thisx, void* entry);

#endif


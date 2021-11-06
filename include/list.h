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

#define CList__GetLast(THIS, ENTRY) (*((void**)(((SIZE_TYPE)(ENTRY)) + (THIS)->lastOffset)))
#define CList__GetNext(THIS, ENTRY) (*((void**)(((SIZE_TYPE)(ENTRY)) + (THIS)->nextOffset)))

extern void CList__Construct(CList* thisx, uint32_t lastOffset, uint32_t nextOffset);
extern void CList__AddHead(CList* thisx, void* entry);
extern void CList__AddTail(CList* thisx, void* entry);
extern void CList__Remove(CList* thisx, void* entry);

#endif


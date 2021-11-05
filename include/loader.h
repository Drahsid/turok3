#ifndef LOADER_H
#define LOADER_H

#include "inttypes.h"
#include "list.h"
#include <ultra64.h>

#define LOADER_QUEUE_SIZE   512
#define LOADER_ENTRY_COUNT  (LOADER_QUEUE_SIZE + 16)

typedef struct CLoaderEntry {
    /* 0x00 */ void* address;
    /* 0x04 */ void* dest;
    /* 0x08 */ int32_t length;
    /* 0x0C */ OSMesgQueue* pReplyQueue;
    /* 0x10 */ void* pReplyMessage;
    /* 0x14 */ uint32_t flags;
    /* 0x18 */ struct CLoaderEntry* pLast;
    /* 0x1C */ struct CLoaderEntry* pNext;
} CLoaderEntry; /* sizeof = 0x20 */

typedef struct {
    /* 0x0000 */ OSThread thread;
    /* 0x01C0 */ OSMesgQueue queue;
    /* 0x01DC */ OSMesg messages[512];
    /* 0x09DC */ OSMesgQueue piReplyQueue;
    /* 0x09F8 */ OSMesg piReplyMessage;
    /* 0x09FC */ uint8_t stack[0x400];
    /* 0x0DFC */ CLoaderEntry entries[LOADER_ENTRY_COUNT];
    /* 0x4FFC */ CList freeList;
    /* 0x5010 */ CList usedList;
} CLoader; /* sizeof = 0x5024 */

extern void CLoader__Construct(CLoader* thisx, OSId threadId);

#endif


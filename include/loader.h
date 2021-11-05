#ifndef LOADER_H
#define LOADER_H

#include "inttypes.h"
#include "list.h"
#include <ultra64.h>

#define LOADER_QUEUE_SIZE   512
#define LOADER_ENTRY_COUNT  (LOADER_QUEUE_SIZE + 16)
#define LOADER_DMA_COMPLETE_MESSAGE 2001

enum {
    LOADERFLAGS_UNALLOCATED = 0,
    LOADERFLAGS_ALLOCATED = (1 << 0)
};

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
    /* 0x01C0 */ uint8_t unk_0x1C0[0x80];
    /* 0x0240 */ OSMesgQueue queue;
    /* 0x025C */ OSMesg messages[LOADER_QUEUE_SIZE];
    /* 0x0A5C */ OSMesgQueue piReplyQueue;
    /* 0x0A78 */ OSMesg piReplyMessage;
    /* 0x0A7C */ uint32_t _pad; // stack is typed as u64[] in the source, which causes this alignment
    /* 0x0A80 */ uint8_t stack[0x400];
    /* 0x0E80 */ CLoaderEntry entries[LOADER_ENTRY_COUNT];
    /* 0x5080 */ CList freeList;
    /* 0x5094 */ CList usedList;
} CLoader; /* sizeof = 0x50A8 */

extern void CLoader__Construct(CLoader* thisx, OSId threadId);
extern void CLoader__Main(CLoader* thisx);

#endif


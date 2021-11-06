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
    /* 0x00 */ void* address; // "pAddress"
    /* 0x04 */ void* dest; // "pDest"
    /* 0x08 */ int32_t length; // "Length"
    /* 0x0C */ OSMesgQueue* replyQueue; // "pReplyQueue"
    /* 0x10 */ void* replyMessage; // "pReplyMessage"
    /* 0x14 */ uint32_t flags; // "dwFlags"
    /* 0x18 */ struct CLoaderEntry* prev; // "pLast"
    /* 0x1C */ struct CLoaderEntry* next; // "pNext"
} CLoaderEntry; /* sizeof = 0x20 */

typedef struct {
    /* 0x0000 */ OSThread thread; // "Thread"
    /* 0x01C0 */ uint8_t unk_0x1C0[0x80];
    /* 0x0240 */ OSMesgQueue queue; // "Queue"
    /* 0x025C */ OSMesg messages[LOADER_QUEUE_SIZE]; // "Msgs"
    /* 0x0A5C */ OSMesgQueue piReplyQueue; // "PiReplyQueue"
    /* 0x0A78 */ OSMesg piReplyMessage; // "PiReplyMsg"
    /* 0x0A7C */ uint32_t _pad; // stack is typed as u64[] in the source, which causes this alignment
    /* 0x0A80 */ uint8_t stack[0x400]; // "Stack"
    /* 0x0E80 */ CLoaderEntry entries[LOADER_ENTRY_COUNT]; // "Entries"
    /* 0x5080 */ CList freeList; // "FreeList"
    /* 0x5094 */ CList usedList; // "UsedList"
} CLoader; /* sizeof = 0x50A8 */

extern void CLoader__Construct(CLoader* thisx, OSId threadId);
extern void CLoader__Main(CLoader* thisx);
extern void CLoader__DeallocLoaderEntry(CLoader* thisx, CLoaderEntry* entry);

#endif


#include "common.h"
#include "loader.h"
#include "defs.h"
#include "list.h"

void CLoader__Construct(CLoader* thisx, OSId threadId) {
    int32_t index;
    CLoaderEntry* entry;

    osCreateMesgQueue(&thisx->queue, thisx->messages, LOADER_QUEUE_SIZE);
    osCreateMesgQueue(&thisx->piReplyQueue, &thisx->piReplyMessage, 1);

    osSetEventMesg(OS_EVENT_PI, &thisx->piReplyQueue, LOADER_DMA_COMPLETE_MESSAGE);

    CList__Construct(&thisx->freeList, OFFSETOF(CLoaderEntry, pLast), OFFSETOF(CLoaderEntry, pNext));
    CList__Construct(&thisx->usedList, OFFSETOF(CLoaderEntry, pLast), OFFSETOF(CLoaderEntry, pNext));

    for (index = 0; index < LOADER_ENTRY_COUNT; index++) {
        entry = &thisx->entries[index];
        entry->flags = LOADERFLAGS_UNALLOCATED;
        CList__AddTail(&thisx->freeList, entry);
    }

    memset(thisx->stack, threadId, sizeof(thisx->stack));
    osCreateThread(&thisx->thread, threadId, CLoader__Main, thisx, (SIZE_TYPE)&thisx->stack + sizeof(thisx->stack), gThreadPriorityLoader);
    osStartThread(&thisx->thread);
}

INCLUDE_ASM(s32, "loader", func_24351C);

INCLUDE_ASM(s32, "loader", func_2435F4);

INCLUDE_ASM(s32, "loader", CLoader__Main);

INCLUDE_ASM(s32, "loader", func_24383C);

INCLUDE_ASM(s32, "loader", func_2438A8);

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

    CList__Construct(&thisx->freeList, OFFSETOF(CLoaderEntry, prev), OFFSETOF(CLoaderEntry, next));
    CList__Construct(&thisx->usedList, OFFSETOF(CLoaderEntry, prev), OFFSETOF(CLoaderEntry, next));

    for (index = 0; index < LOADER_ENTRY_COUNT; index++) {
        entry = &thisx->entries[index];
        entry->flags = LOADERFLAGS_UNALLOCATED;
        CList__AddTail(&thisx->freeList, entry);
    }

    memset(thisx->stack, threadId, sizeof(thisx->stack));
    osCreateThread(&thisx->thread, threadId, CLoader__Main, thisx, (SIZE_TYPE)&thisx->stack + sizeof(thisx->stack), gThreadPriorityLoader);
    osStartThread(&thisx->thread);
}

INCLUDE_ASM("asm/nonmatchings/loader/", func_24351C);

INCLUDE_ASM("asm/nonmatchings/loader/", func_2435F4);

// OK except for delay slot optimization and flipped register loads (regalloc is the same, behavior is flipped)
#ifdef NON_MATCHING
void CLoader__Main(CLoader* thisx) {
    CLoaderEntry* entry;
    OSMesg* dummy;
    OSTimer timer;
    int32_t dmaRet; // used for an assert in debug builds

    while (1) {
        osRecvMesg(&thisx->queue, &entry, OS_MESG_BLOCK);
        if ((uint32_t)entry == 0xBEEFDEAD) {
            osSetTimer(&timer, 0, OS_USEC_TO_CYCLES(80000), &thisx->queue, (OSMesg)0xDEADBEEF);
        }
        else if ((uint32_t)entry == 0xDEADBEEF) {
            if (CTexModSet__IsActive() != 0) {
                SCSI_PollHost(&thisx->queue);
            }
        }
        else {
            osWritebackDCache(entry->dest, entry->length);
            dmaRet = osPiRawStartDma(OS_READ, (uint32_t)entry->address, entry->dest, entry->length);
            osRecvMesg(&thisx->piReplyQueue, &dummy, OS_MESG_BLOCK);
            osInvalDCache(entry->dest, entry->length);

            if (entry->replyQueue != NULLPTR) {
                osSendMesg(entry->replyQueue, entry->replyMessage, OS_MESG_BLOCK);
            }

            CLoader__DeallocLoaderEntry(thisx, entry);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/loader/", CLoader__Main);
#endif

INCLUDE_ASM("asm/nonmatchings/loader/", func_24383C);

void CLoader__DeallocLoaderEntry(CLoader* thisx, CLoaderEntry* entry) {
    OSIntMask mask;

    mask = __osDisableInt();
    CList__Remove(&thisx->usedList, entry);
    entry->flags = LOADERFLAGS_UNALLOCATED;
    CList__AddHead(&thisx->freeList, entry);
    __osRestoreInt(mask);
}


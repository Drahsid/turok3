#include "decompressor.h"
#include "cache.h"
#include "common.h"

void CDecompressor__Construct(CDecompressor* thisx, OSId threadId) {
    osCreateMesgQueue(&thisx->queue, thisx->messages, DECOMPRESSOR_QUEUE_SIZE);

    memset(thisx->stack, threadId, STACKSIZE_DECOMPRESSOR);

    osCreateThread(&thisx->thread, threadId, CDecompressor__Main, thisx, thisx->stack + STACKSIZE_DECOMPRESSOR, gThreadPriorityDecompressorLow);
    osStartThread(&thisx->thread);
}

INCLUDE_ASM("asm/nonmatchings/decompressor", func_2423E0);

INCLUDE_ASM("asm/nonmatchings/decompressor", func_242474);

INCLUDE_ASM("asm/nonmatchings/decompressor", func_2424B0);

void CDecompressor__Main(CDecompressor* thisx) {
    CCacheEntry* entry;

    while(1) {
        osRecvMesg(&thisx->queue, (OSMesg*)&entry, OS_MESG_BLOCK);

        thisx->lastDecompression = gFrameCount;
        entry->decompressCallback(entry->notifyId, entry);

        func_241BD8(); // decrements gCache.lowRamCount
        osSendMesg(entry->decompressReplyQueue, (OSMesg)entry, OS_MESG_BLOCK);
    }
}

#include "cache.h"
#include "defs.h"
#include "heap.h"
#include "hash.h"

INCLUDE_ASM("asm/nonmatchings/cache", func_23D490);

INCLUDE_ASM("asm/nonmatchings/cache", func_23D8E0);

INCLUDE_ASM("asm/nonmatchings/cache", func_23DC88);

INCLUDE_ASM("asm/nonmatchings/cache", func_23DE08);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E08C);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E18C);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E3BC);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E584);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E5F4);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E678);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E6A0);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E6B0);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E6E8);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E73C);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E888);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E8D4);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E9B0);

INCLUDE_ASM("asm/nonmatchings/cache", func_23E9EC);

INCLUDE_ASM("asm/nonmatchings/cache", func_23EA78);

INCLUDE_ASM("asm/nonmatchings/cache", func_23EB08);

INCLUDE_ASM("asm/nonmatchings/cache", func_23EBAC);

INCLUDE_ASM("asm/nonmatchings/cache", func_23EC68);

INCLUDE_ASM("asm/nonmatchings/cache", func_23EC9C);

void CCache__Construct(OSId threadId) {
    int32_t index;
    CMemEntry* mem_entry;
    CCacheEntry* cache_entry;

    CMutex__Construct(&gCache.mutex);
    CMutex__Begin(&gCache.mutex);

    gCacheEntryCount = CACHE_ENTRIES;

    if (GetMemSize() > 0x400000) {
        gCacheEntryCount *= 2;
    }

    gCache.memEntries = Malloc(gCacheEntryCount * sizeof(CMemEntry));
    gCache.memEntriesFree = Malloc(gCacheEntryCount * sizeof(CMemEntry*));
    gCache.cacheEntries = Malloc(gCacheEntryCount * sizeof(CCacheEntry));

    CBlocker__Construct(&gCache.blocker);
    gCache.dlistBlocking[0] = gCache.dlistBlocking[1] = 0;

    CList__Construct(&gCache.memAgeList, OFFSETOF(CMemEntry, last), OFFSETOF(CMemEntry, next));

    gCache.freeEntryCount = 0;
    for (index = 0; index < gCacheEntryCount; index++) {
        mem_entry = &gCache.memEntries[index];
        mem_entry->flags = MEMENTRY_FLAG_UNALLOCATED;

        gCache.memEntriesFree[index] = mem_entry;
        gCache.freeEntryCount++;
    }

    gCache.dlistValid[0] = gCache.dlistValid[1] = 1;
    gCache.currentDlist = -1;
    gCache.dlistCount[0] = 0;
    gCache.dlistCount[1] = 0;
    gCache.currentCompressPos = NULLPTR;
    gCache.synchronous = 0;
    gCache.ageCount = 0;
    gCache.unk_0xC0C = 0;
    gCache.lowRamCount = 0;

    CList__Construct(&gCache.cacheFreeList, OFFSETOF(CCacheEntry, last), OFFSETOF(CCacheEntry, next));
    CList__Construct(&gCache.cacheUsedList, OFFSETOF(CCacheEntry, last), OFFSETOF(CCacheEntry, next));
    CList__Construct(&gCache.cachePendingList, OFFSETOF(CCacheEntry, last), OFFSETOF(CCacheEntry, next));

    for (index = 0; index < gCacheEntryCount; index++) {
        cache_entry = &gCache.cacheEntries[index];
        cache_entry->flags = CACHEENTRY_FLAG_UNALLOCATED;
        CList__AddTail(&gCache.cacheFreeList, cache_entry);
    }

    CHashTable__Construct(gCacheEntryCount);
    osCreateMesgQueue(&gCache.queue, gCache.messages, CACHE_QUEUE_SIZE);

    CMutex__End(&gCache.mutex);

    memset(gCache.stack, threadId, STACKSIZE_CACHE);
    osCreateThread(&gCache.thread, threadId, CCache__Main, NULLPTR, gCache.stack + STACKSIZE_CACHE, gThreadPriorityCache);
    osStartThread(&gCache.thread);
}

INCLUDE_ASM("asm/nonmatchings/cache", func_23F024);

INCLUDE_ASM("asm/nonmatchings/cache", func_23F190);

INCLUDE_ASM("asm/nonmatchings/cache", func_23F2D8);

INCLUDE_ASM("asm/nonmatchings/cache", func_23F3EC);

INCLUDE_ASM("asm/nonmatchings/cache", func_23F5C8);

INCLUDE_ASM("asm/nonmatchings/cache", func_23F734);

INCLUDE_ASM("asm/nonmatchings/cache", func_23FD18);

INCLUDE_ASM("asm/nonmatchings/cache", func_240218);

INCLUDE_ASM("asm/nonmatchings/cache", CCache__Main);

INCLUDE_ASM("asm/nonmatchings/cache", func_240608);

INCLUDE_ASM("asm/nonmatchings/cache", func_240908);

INCLUDE_ASM("asm/nonmatchings/cache", func_240B94);

INCLUDE_ASM("asm/nonmatchings/cache", CCache__Advance);

INCLUDE_ASM("asm/nonmatchings/cache", func_240C98);

INCLUDE_ASM("asm/nonmatchings/cache", func_240D88);

INCLUDE_ASM("asm/nonmatchings/cache", func_240EBC);

INCLUDE_ASM("asm/nonmatchings/cache", func_240FC8);

INCLUDE_ASM("asm/nonmatchings/cache", func_2410B0);

INCLUDE_ASM("asm/nonmatchings/cache", func_241198);

INCLUDE_ASM("asm/nonmatchings/cache", func_2411C0);

INCLUDE_ASM("asm/nonmatchings/cache", func_24128C);

INCLUDE_ASM("asm/nonmatchings/cache", func_24136C);

INCLUDE_ASM("asm/nonmatchings/cache", func_24146C);

INCLUDE_ASM("asm/nonmatchings/cache", func_24156C);

INCLUDE_ASM("asm/nonmatchings/cache", func_2416F0);

INCLUDE_ASM("asm/nonmatchings/cache", func_241860);

INCLUDE_ASM("asm/nonmatchings/cache", func_2418D4);

INCLUDE_ASM("asm/nonmatchings/cache", func_241A28);

INCLUDE_ASM("asm/nonmatchings/cache", func_241B68);

INCLUDE_ASM("asm/nonmatchings/cache", func_241B78);

void func_241B88(void) {
}

INCLUDE_ASM("asm/nonmatchings/cache", func_241B90);

INCLUDE_ASM("asm/nonmatchings/cache", func_241BA0);

INCLUDE_ASM("asm/nonmatchings/cache", func_241BB0);

INCLUDE_ASM("asm/nonmatchings/cache", func_241BB8);

INCLUDE_ASM("asm/nonmatchings/cache", func_241BC8);

INCLUDE_ASM("asm/nonmatchings/cache", func_241BD8);

INCLUDE_ASM("asm/nonmatchings/cache", func_241BF0);

INCLUDE_ASM("asm/nonmatchings/cache", func_241C08);

INCLUDE_ASM("asm/nonmatchings/cache", func_241CD8);

INCLUDE_ASM("asm/nonmatchings/cache", func_241D84);

INCLUDE_ASM("asm/nonmatchings/cache", func_241DC4);

INCLUDE_ASM("asm/nonmatchings/cache", func_241E34);

INCLUDE_ASM("asm/nonmatchings/cache", func_241EB4);

INCLUDE_ASM("asm/nonmatchings/cache", func_241ED0);

INCLUDE_ASM("asm/nonmatchings/cache", func_241F9C);

INCLUDE_ASM("asm/nonmatchings/cache", func_24202C);

void func_242070(void) {
}

INCLUDE_ASM("asm/nonmatchings/cache", func_242078);

INCLUDE_ASM("asm/nonmatchings/cache", func_2420D8);

INCLUDE_ASM("asm/nonmatchings/cache", func_242130);

INCLUDE_ASM("asm/nonmatchings/cache", func_24217C);

INCLUDE_ASM("asm/nonmatchings/cache", func_24222C);

INCLUDE_ASM("asm/nonmatchings/cache", func_242274);

INCLUDE_ASM("asm/nonmatchings/cache", func_2422D4);

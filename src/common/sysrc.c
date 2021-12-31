#include "sysrc.h"
#include "common.h"

// TODO: find location of .data so this can be shiftable (these are technically in the DISCARD section)
CLoader gLoader;
CDecompressor gDecompressor;
CHeap gHeap;

extern uint32_t __bss_objend[];

void InitializeSystemResources(void) {
    void* heap_start;
    uint32_t heap_length;
    uint32_t memory_end;

    heap_start = (uint32_t)__bss_objend | 0x80000000;
    memory_end = 0x80400000;

    if (GetMemSize() != 0x00400000) {
        memory_end = GetMemSize() | 0x80000000;
    }

    heap_length = memory_end - (uint32_t)heap_start;
    memset(heap_start, 0, heap_length);
    CHeap__Construct(GetHeap(), heap_start, heap_length);

    CDecompressor__Construct(GetDecompressor(), THREAD_DECOMPRESSOR);
    CLoader__Construct(GetLoader(), THREAD_LOADER);
    VM_Initialize(0, 0);
    CCache__Construct(THREAD_CACHE);
}

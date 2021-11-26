#include "hash.h"
#include "heap.h"
#include "include_asm.h"

uint32_t gHashSize = 0;
uint32_t gHashTableSize = 0;

// TODO: locate this split
#ifdef NON_MATCHING
uint32_t gHashMask;
uint32_t gHashTableMask;
HashEntry* gHashTable;
#endif

static inline uint32_t RoundToPowerOfTwo(uint32_t x) {
    int32_t num_bits = 0;
    int32_t high_bit = 0;
    int32_t index;

    for (index = 0; index < sizeof(x) * 8; index++) {
        if (x & (1 << index)) {
            num_bits++;
            high_bit = index;
        }
    }

    if (num_bits != 1) {
        high_bit++;
    }

    return (1 << high_bit);
}


#if defined(NON_MATCHING) || defined(ORIGINAL_AS_TESTS) || defined(IGNORE_PSEUDOOPS)
void CHashTable__Construct(uint32_t num_entries) {
    int32_t index;

    gHashSize = RoundToPowerOfTwo(num_entries);
    gHashTableSize = gHashSize * 2;
    gHashMask = (gHashTableSize - 1) & (~1);
    gHashTableMask = gHashTableSize - 1;
    gHashTable = Malloc(gHashTableSize * sizeof(HashEntry));

    for (index = 0; index < gHashTableSize; index++) {
        gHashTable[index].value = 0;
        gHashTable[index].key = NULL;
        gHashTable[index].next = NULLPTR;
        gHashTable[index].index = index;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/hash/", CHashTable__Construct);
#endif

INCLUDE_ASM("asm/nonmatchings/hash/", func_242644);

INCLUDE_ASM("asm/nonmatchings/hash/", func_242718);

INCLUDE_ASM("asm/nonmatchings/hash/", func_2427D0);

INCLUDE_ASM("asm/nonmatchings/hash/", func_24281C);

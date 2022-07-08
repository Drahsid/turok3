#include "common.h"

INCLUDE_ASM("asm/nonmatchings/defs", func_252890);

INCLUDE_ASM("asm/nonmatchings/defs", func_252AEC);

// NONMATCHING (behavior OK)
// regalloc, instruction order
#ifdef NON_MATCHING
SIZE_TYPE GetMemSize(void) {
    if (osMemSize <= 0x007FFFFF) {
        return osMemSize;
    }

    return 0x00700000; // in this case, the last megabyte is used for fast virtual memory I believe
}
#else
INCLUDE_ASM("asm/nonmatchings/defs", GetMemSize);
#endif

INCLUDE_ASM("asm/nonmatchings/defs", func_252CA8);

INCLUDE_ASM("asm/nonmatchings/defs", func_252D74);

INCLUDE_ASM("asm/nonmatchings/defs", strcmp);

INCLUDE_ASM("asm/nonmatchings/defs", strcpy);

INCLUDE_ASM("asm/nonmatchings/defs", func_252ED0);

INCLUDE_ASM("asm/nonmatchings/defs", func_252F38);

INCLUDE_ASM("asm/nonmatchings/defs", BinaryRange);

INCLUDE_ASM("asm/nonmatchings/defs", func_25308C);

INCLUDE_ASM("asm/nonmatchings/defs", func_2530A0);

INCLUDE_ASM("asm/nonmatchings/defs", func_2530D8);

INCLUDE_ASM("asm/nonmatchings/defs", func_25312C);

INCLUDE_ASM("asm/nonmatchings/defs", func_253164);

INCLUDE_ASM("asm/nonmatchings/defs", func_2531D4);

INCLUDE_ASM("asm/nonmatchings/defs", func_25326C);

INCLUDE_ASM("asm/nonmatchings/defs", func_2532D4);

#ifdef NON_MATCHING
s32 CCache_GetFromLookupTable(s32 offset) {
    return *(*func_23F734(0x1E0000, 0x1E0000, 0x20, 0x10, 0, 0, &D_800F9CB8, 1) + offset);
}
#else
INCLUDE_ASM("asm/nonmatchings/defs", CCache_GetFromLookupTable);
#endif


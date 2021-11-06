#include "common.h"

INCLUDE_ASM(s32, "defs", func_252890);

INCLUDE_ASM(s32, "defs", func_252AEC);

// OK besides delay slot optimization
//#ifdef NON_MATCHING
/*
SIZE_TYPE GetMemSize(void) {
    if (osMemSize <= 0x007FFFFF) {
        return osMemSize;
    }

    return 0x00700000; // in this case, the last megabyte is used for fast virtual memory I believe
}
*/
//#else
INCLUDE_ASM(s32, "defs", GetMemSize);
//#endif

INCLUDE_ASM(s32, "defs", func_252CA8);

INCLUDE_ASM(s32, "defs", func_252D74);

INCLUDE_ASM(s32, "defs", strcmp);

INCLUDE_ASM(s32, "defs", strcpy);

INCLUDE_ASM(s32, "defs", func_252ED0);

INCLUDE_ASM(s32, "defs", func_252F38);

INCLUDE_ASM(s32, "defs", func_252FA0);

INCLUDE_ASM(s32, "defs", func_25308C);

INCLUDE_ASM(s32, "defs", func_2530A0);

INCLUDE_ASM(s32, "defs", func_2530D8);

INCLUDE_ASM(s32, "defs", func_25312C);

INCLUDE_ASM(s32, "defs", func_253164);

INCLUDE_ASM(s32, "defs", func_2531D4);

INCLUDE_ASM(s32, "defs", func_25326C);

INCLUDE_ASM(s32, "defs", func_2532D4);

INCLUDE_ASM(s32, "defs", CCache_GetFromLookupTable);

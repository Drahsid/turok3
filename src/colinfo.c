#include "include_asm.h"
#include "colinfo.h"

// Matching besides loading of virtual data
//#ifdef NON_MATCHING
/*
void CCollisionInfo__Reset(void) {
    gCollisionResultsP = &gCollisionResults;
    CCollisionSetup__Construct(gCollisionSetupTable);
}
*/
//#else
INCLUDE_ASM(s32, "colinfo", CCollisionInfo__Reset);
//#endif

INCLUDE_ASM(s32, "colinfo", func_2291D4);

INCLUDE_ASM(s32, "colinfo", CCollisionSetup__Construct);

INCLUDE_ASM(s32, "colinfo", func_2292B0);

INCLUDE_ASM(s32, "colinfo", func_22985C);

INCLUDE_ASM(s32, "colinfo", func_229A64);

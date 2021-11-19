#include "include_asm.h"
#include "colinfo.h"

// Matching besides loading of virtual data
#ifdef NON_MATCHING
void CCollisionInfo__Reset(void) {
    gCollisionResultsP = &gCollisionResults;
    CCollisionSetup__Construct(gCollisionSetupTable);
}
#else
INCLUDE_ASM("asm/nonmatchings/colinfo/", CCollisionInfo__Reset);
#endif

INCLUDE_ASM("asm/nonmatchings/colinfo/", func_2291D4);

INCLUDE_ASM("asm/nonmatchings/colinfo/", CCollisionSetup__Construct);

INCLUDE_ASM("asm/nonmatchings/colinfo/", func_2292B0);

INCLUDE_ASM("asm/nonmatchings/colinfo/", func_22985C);

INCLUDE_ASM("asm/nonmatchings/colinfo/", func_229A64);

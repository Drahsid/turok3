#include "sun.h"
#include "graphu64.h"
#include "common.h"

// need .rdata
#if defined(NON_MATCHING)
void CSun__Construct(CSun* thisx) {
    thisx->dir.x = -0.667424f;
    thisx->dir.y = 2.0f * 0.476731f;
    thisx->dir.z = -0.572078f;
    CVector3__Normalize(&thisx->dir);

    thisx->isVisible = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/virtual/sun", CSun__Construct);
#endif


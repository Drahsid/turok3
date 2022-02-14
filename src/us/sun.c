#include "include_asm.h"
#include "sun.h"
#include "graphu64.h"

void CSunFrameData__Construct(CSunFrameData* thisx) {
    thisx->isVisible = 0;
    thisx->isVisibleZ = 0;
}

void func_283D7C(void) {
}

// needs .rdata
#if defined(NON_MATCHING)  //|| defined(NEW_ORIGINAL_AS_TEST)
void CSun__SetSunDir(CSun* thisx, CVector3* dir) {
    thisx->dir = *dir;
    CVector3__Normalize(&thisx->dir);
}
#else
INCLUDE_ASM("asm/nonmatchings/sun", CSun__SetSunDir);
#endif

void CSun__GetSunData(CSun* thisx, int32_t* visible, float* pos_x, float* pos_y, float* opacity) {
    *visible = thisx->isVisible;
    *opacity = thisx->opacity;
    *pos_x = thisx->screenX;
    *pos_y = thisx->screenY;
}

void func_283E5C(void) {
}

void func_283E64(void) {
}

void func_283E6C(void) {
}

#include "include_asm.h"
#include "sun.h"
#include "graphu64.h"

void CSunFrameData__Construct(CSunFrameData* thisx) {
    thisx->isVisible = 0;
    thisx->isVisibleZ = 0;
}

void func_283D7C(void) {
}

// Behaviorally equal; CVector3__Normalize is inlined, which seems to effect codegen (stack and regalloc)
//#ifdef NON_MATCHING
/*
void CSun__SetSunDir(CSun* thisx, CVector3* dir) {
    float length;
    float norm;

    thisx->m_vDir = *dir;

    length = CVector3__Magnitude(&thisx->m_vDir);
    if (length != 0) {
        norm = 1.0f / length;
        (&thisx->m_vDir)->x *= norm;
        (&thisx->m_vDir)->y *= norm;
        (&thisx->m_vDir)->z *= norm;
    }
}
*/
//#else
INCLUDE_ASM(s32, "sun", CSun__SetSunDir);
//#endif

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

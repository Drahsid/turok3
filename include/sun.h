#ifndef SUN_H
#define SUN_H

#include "inttypes.h"
#include "common_structs.h"

typedef struct {
    /* 0x00 */ uint64_t m_DepthData[2];
    /* 0x10 */ int32_t m_DepthPos;
    /* 0x14 */ int32_t m_bVisible;
    /* 0x18 */ int32_t m_bVisibleZ;
    /* 0x1C */ int32_t _pad;
} CSunFrameData; /* sizeof = 0x20 */

typedef struct {
    /* 0x00 */ int32_t unk_0x00;
    /* 0x04 */ int32_t unk_0x04;
    /* 0x08 */ float m_ScreenX;
    /* 0x0C */ float m_ScreenY;
    /* 0x10 */ float m_Opacity;
    /* 0x14 */ CVector3 m_vDir;
    /* 0x20 */ int32_t m_Visible;
} CSun; /* sizeof = 0x24 */

extern void CSunFrameData__Construct(CSunFrameData* thisx);
extern void CSun__GetSunData(CSun* thisx, int32_t* visible, float* posx, float* posy, float* opacity);
extern void CSun__SetSunDir(CSun* thisx, CVector3* dir);

#endif


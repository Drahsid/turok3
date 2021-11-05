#ifndef SUN_H
#define SUN_H

#include "inttypes.h"

typedef struct {
    /* 0x00 */ uint64_t m_DepthData[2];
    /* 0x10 */ int32_t m_DepthPos;
    /* 0x14 */ int32_t m_bVisible;
    /* 0x18 */ int32_t m_bVisibleZ;
    /* 0x1C */ int32_t _pad;
} CSunFrameData; /* sizeof = 0x20 */

extern CSunFrameData__Construct(CSunFrameData* thisx);

#endif


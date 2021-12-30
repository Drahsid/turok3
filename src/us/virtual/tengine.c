#include "tengine.h"
#include "common.h"

void CEngineApp__SetupShadowVtxs(void) {
    int32_t index;
    Vtx* vtx;
    int16_t low = 0;
    int16_t high = 1024;

    gShadowVertexes[0].v.ob[0] = -1;
    gShadowVertexes[0].v.ob[2] = 1;
    gShadowVertexes[0].v.tc[0] = low;
    gShadowVertexes[0].v.tc[1] = low;

    gShadowVertexes[1].v.ob[0] = 1;
    gShadowVertexes[1].v.ob[2] = 1;
    gShadowVertexes[1].v.tc[0] = high;
    gShadowVertexes[1].v.tc[1] = low;

    gShadowVertexes[2].v.ob[0] = 1;
    gShadowVertexes[2].v.ob[2] = -1;
    gShadowVertexes[2].v.tc[0] = high;
    gShadowVertexes[2].v.tc[1] = high;

    gShadowVertexes[3].v.ob[0] = -1;
    gShadowVertexes[3].v.ob[2] = -1;
    gShadowVertexes[3].v.tc[0] = low;
    gShadowVertexes[3].v.tc[1] = high;

    for (index = 0; index < 4; index++) {
        vtx = &gShadowVertexes[index];

        vtx->v.ob[1] = 0;
        vtx->v.flag = 0;
        vtx->v.cn[0] = 255;
        vtx->v.cn[1] = 255;
        vtx->v.cn[2] = 255;
        vtx->v.cn[3] = 255;
    }
}

INCLUDE_ASM("asm/nonmatchings/virtual/tengine", func_44BC40);

INCLUDE_ASM("asm/nonmatchings/virtual/tengine", func_44BC94);

INCLUDE_ASM("asm/nonmatchings/virtual/tengine", func_44BCF4);

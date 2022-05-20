#ifndef COMMON_STRUCTS_H
#define COMMON_STRUCTS_H

#include "inttypes.h"

typedef struct {
    /* 0x00 */ float x;
    /* 0x04 */ float y;
    /* 0x08 */ float z;
} CVector3; /* sizeof = 0x0C */

typedef float CMtxF[4][4]; /* sizeof = 0x40 */

typedef struct {
    /* 0x00 */ float x;
    /* 0x04 */ float y;
    /* 0x08 */ float z;
    /* 0x0C */ float w;
} CQuaternion; /* sizeof = 0x10 */

// TODO: move these
typedef struct {
    /* 0x00 */ void* rpTextureSet;
    /* 0x04 */ uint32_t textureSetSize;
} CTextureLoader; /* sizeof = 0x08 */

typedef struct {
    /* 0x00 */ uint32_t materialFlags;
    /* 0x04 */ uint32_t materialIndex;
    /* 0x08 */ CTextureLoader textureLoader;
    /* 0x10 */ uint8_t color[4];
    /* 0x14 */ uint8_t blackColor[4];
    /* 0x18 */ uint16_t multU;
    /* 0x1A */ uint16_t multV;
} CGameSection; /* sizeof = 0x1C */

#endif


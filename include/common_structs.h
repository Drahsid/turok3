#ifndef COMMON_STRUCTS_H
#define COMMON_STRUCTS_H

typedef struct {
    /* 0x00 */ float x;
    /* 0x04 */ float y;
    /* 0x08 */ float z;
} CVector3; /* sizeof = 0xC */

typedef float CMtxF[4][4];

typedef struct {
    /* 0x00 */ float x;
    /* 0x04 */ float y;
    /* 0x08 */ float z;
    /* 0x0C */ float w;
} CQuaternion; /* sizeof = 0x10 */

#endif


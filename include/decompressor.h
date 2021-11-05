#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include "inttypes.h"
#include <ultra64.h>

typedef struct {
    /* 0x0000 */ OSThread thread;
    /* 0x01C0 */ OSMesgQueue queue;
    /* 0x01DC */ OSMesg messages[128];
    /* 0x03DC */ uint8_t stack[0x1000];
    /* 0x13DC */ uint32_t lastDecompression;
} CDecompressor; /* sizeof = 0x13E0 */

extern void CDecompressor__Construct(CDecompressor* thisx, OSId threadId);

#endif


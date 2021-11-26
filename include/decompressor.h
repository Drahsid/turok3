#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include "common.h"

#define DECOMPRESSOR_QUEUE_SIZE (128)

typedef struct {
    /* 0x0000 */ OSThread thread;
    /* 0x01B0 */ uint8_t unk_0x1B0[0x80];
    /* 0x01C0 */ OSMesgQueue queue;
    /* 0x01DC */ OSMesg messages[DECOMPRESSOR_QUEUE_SIZE];
    /* 0x03DC */ uint8_t stack[STACKSIZE_DECOMPRESSOR];
    /* 0x13DC */ uint32_t lastDecompression;
} CDecompressor; /* sizeof = 0x13E0 */

extern void CDecompressor__Construct(CDecompressor* thisx, OSId threadId);
extern void CDecompressor__Main(CDecompressor* thisx);

#endif


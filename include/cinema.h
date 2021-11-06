#ifndef CINEMA_H
#define CINEMA_H

#include "inttypes.h"

// I am confident this is nearly identical to the same structure in T2 with some additions,
// however, I have yet to actually analyze it to be sure
typedef struct {
    /* 0x000 */ uint32_t unk_0x00;
    /* 0x004 */ uint32_t unk_0x04;
    /* 0x008 */ uint32_t unk_0x08;
    /* 0x00C */ uint32_t unk_0x0C;
    /* 0x010 */ uint32_t unk_0x10;
    /* 0x014 */ uint32_t unk_0x14;
    /* 0x018 */ uint32_t unk_0x18;
    /* 0x01C */ uint32_t unk_0x1C;
    /* 0x020 */ uint32_t unk_0x20;
    /* 0x024 */ uint32_t unk_0x24;
    /* 0x028 */ uint32_t unk_0x28;
    /* 0x02C */ uint32_t unk_0x2C;
    /* 0x030 */ uint32_t unk_0x30;
    /* 0x034 */ uint32_t unk_0x34;
    /* 0x038 */ uint32_t unk_0x38;
    /* 0x03C */ uint32_t unk_0x3C;
    /* 0x040 */ uint32_t unk_0x40;
    /* 0x044 */ uint32_t unk_0x44;
    /* 0x048 */ uint32_t unk_0x48;
    /* 0x04C */ uint32_t unk_0x4C;
    /* 0x050 */ uint32_t unk_0x50;
    /* 0x054 */ uint32_t unk_0x54;
    /* 0x058 */ uint32_t unk_0x58;
    /* 0x05C */ uint32_t unk_0x5C;
    /* 0x060 */ uint32_t unk_0x60;
    /* 0x064 */ uint32_t unk_0x64;
    /* 0x068 */ uint8_t unk_0x68[0x4C]; // CCinemaInfo?
    /* 0x0B4 */ uint32_t unk_0xB4;
    /* 0x0B8 */ uint32_t unk_0xB8;
    /* 0x0BC */ uint32_t lastWarpId; // "LastWarpID"
    /* 0x0C0 */ uint32_t lastLevel; // "LastLevel"
    /* 0x0C4 */ uint32_t unk_0xC4;
    /* 0x0C8 */ uint32_t unk_0xC8;
    /* 0x0CC */ uint32_t unk_0xCC;
    /* 0x0D0 */ uint32_t unk_0xD0;
    /* 0x0D4 */ uint32_t unk_0xD4;
    /* 0x0D8 */ uint32_t requestedLevel; // "RequestedLevel"
    /* 0x0DC */ uint32_t requestedCinema; // "RequestedCinema"
    /* 0x0E0 */ uint32_t requestedType; // "RequestedType"
    /* 0x0E4 */ uint32_t unk_0xE4;
    /* 0x0E8 */ uint32_t unk_0xE8;
    /* 0x0EC */ uint32_t unk_0xEC;
    /* 0x0F0 */ uint32_t unk_0xF0;
    /* 0x0F4 */ uint32_t unk_0xF4;
    /* 0x0F8 */ uint32_t unk_0xF8;
    /* 0x0FC */ uint32_t unk_0xFC;
    /* 0x100 */ uint32_t unk_0x100;
    /* 0x104 */ float unk_0x104;
    /* 0x108 */ uint32_t unk_0x108;
} CCinemaPlayer; /* sizeof = 0x10C */

extern CCinemaPlayer gCinemaPlayer;
extern CCinemaPlayer* gCinemaPlayerP;

extern void Cinema__Initialize(void);

#endif


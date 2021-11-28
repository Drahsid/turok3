#ifndef OPTIONS_H
#define OPTIONS_H

#include "inttypes.h"

#define MAX_PLAYERS (4)
#define GetOptions() (&gEngineApp.options)

typedef struct {
    /* 0x00 */ uint8_t unk_0x0;
    /* 0x01 */ uint8_t unk_0x1;
    /* 0x02 */ uint8_t unk_0x2;
    /* 0x03 */ uint8_t unk_0x3;
    /* 0x04 */ uint8_t unk_0x4;
    /* 0x05 */ uint8_t unk_0x5;
    /* 0x06 */ uint8_t unk_0x6;
    /* 0x07 */ uint8_t unk_0x7;
} CPlayerControlOptions; /* sizeof = 0x08 */

typedef struct {
    /* 0x000 */ uint8_t unk_0x00;
    /* 0x001 */ uint8_t unk_0x01;
    /* 0x002 */ uint8_t unk_0x02;
    /* 0x003 */ uint8_t unk_0x03;
    /* 0x004 */ uint8_t unk_0x04;
    /* 0x005 */ int8_t unk_0x05;
    /* 0x006 */ uint16_t unk_0x06;
    /* 0x008 */ uint8_t unk_0x08;
    /* 0x009 */ uint8_t unk_0x09;
    /* 0x00A */ uint8_t unk_0x0A;
    /* 0x00B */ uint8_t unk_0x0B;
    /* 0x00C */ uint8_t unk_0x0C[0x14];
    /* 0x020 */ int32_t playerIndex;
    /* 0x024 */ uint8_t unk_0x24[0xE4];
} CPlayerOptions; /* sizeof = 0x108 */

typedef struct {
    /* 0x000 */ uint8_t unk_0x0;
    /* 0x001 */ uint8_t unk_0x1;
    /* 0x002 */ uint8_t unk_0x2;
    /* 0x003 */ uint8_t unk_0x3;
    /* 0x004 */ uint32_t unk_0x4;
    /* 0x008 */ uint8_t unk_0x8;
    /* 0x009 */ uint8_t unk_0x9;
    /* 0x00A */ uint8_t unk_0xA;
    /* 0x00B */ uint8_t unk_0xB;
    /* 0x00C */ uint8_t unk_0xC;
    /* 0x00D */ uint8_t unk_0xD;
    /* 0x00E */ uint8_t unk_0xE;
    /* 0x00F */ uint8_t unk_0xF;
    /* 0x010 */ uint32_t unk_0x10;
    /* 0x014 */ uint8_t unk_0x14;
    /* 0x015 */ uint8_t unk_0x15;
    /* 0x016 */ uint8_t unk_0x16;
    /* 0x017 */ uint8_t unk_0x17;
    /* 0x018 */ uint8_t unk_0x18;
    /* 0x019 */ uint8_t unk_0x19;
    /* 0x01A */ uint8_t unk_0x1A;
    /* 0x01B */ uint8_t unk_0x1B;
    /* 0x01C */ uint32_t unk_0x1C;
    /* 0x020 */ uint32_t unk_0x20;
    /* 0x024 */ uint8_t unk_0x24;
    /* 0x025 */ uint8_t unk_0x25;
    /* 0x026 */ uint8_t unk_0x26;
    /* 0x027 */ uint8_t unk_0x27;
    /* 0x028 */ uint8_t unk_0x28[0x180];
    /* 0x1A8 */ CPlayerOptions singePlayerOptions;
    /* 0x2B0 */ CPlayerOptions multiPlayerOptions[MAX_PLAYERS];
    /* 0x6D0 */ CPlayerControlOptions playerControlOptions[MAX_PLAYERS]; // unknown source name
} COptions; /* sizeof = 0x6F0 */

extern void COptions__SetDefaults(COptions* thisx);

#endif


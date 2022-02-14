#include "common.h"
#include "cinema.h"

// Differences seem to be relevant to optimization of D_800F8D60; it is likely an immediate rvalue, and not data to-be loaded
#ifdef NON_MATCHING
void Cinema__Initialize(void) {
    gCinemaPlayerP->unk_0x00 = 0;
    gCinemaPlayerP->unk_0x04 = 0;
    gCinemaPlayerP->unk_0x08 = 0;
    gCinemaPlayerP->unk_0x0C = 0;
    gCinemaPlayerP->unk_0x10 = 0;
    gCinemaPlayerP->unk_0x14 = 0;
    gCinemaPlayerP->unk_0x18 = 0;
    gCinemaPlayerP->currentTime = 0;
    gCinemaPlayerP->unk_0x20 = 0;
    gCinemaPlayerP->unk_0x24 = 0;
    gCinemaPlayerP->unk_0x28 = 0;
    gCinemaPlayerP->unk_0x2C = 0;
    gCinemaPlayerP->pathBegin = 0;
    gCinemaPlayerP->pathEnd = 0;
    gCinemaPlayerP->playing = 0;
    gCinemaPlayerP->unk_0x3C = 0;
    gCinemaPlayerP->unk_0x40 = 0;
    gCinemaPlayerP->unk_0x44 = 0;
    gCinemaPlayerP->unk_0x48 = 0;
    gCinemaPlayerP->unk_0x4C = 0;
    gCinemaPlayerP->unk_0x50 = 0;
    gCinemaPlayerP->unk_0x54 = 0;
    gCinemaPlayerP->unk_0x58 = 0;
    gCinemaPlayerP->unk_0x5C = 0;
    gCinemaPlayerP->unk_0x60 = 0;
    gCinemaPlayerP->unk_0x64 = 0;
    gCinemaPlayerP->unk_0xB4 = 0;
    gCinemaPlayerP->unk_0xB8 = 0;
    gCinemaPlayerP->lastWarpId = -1;
    gCinemaPlayerP->lastLevel = -1;
    gCinemaPlayerP->unk_0xC4 = 0;
    gCinemaPlayerP->unk_0xC8 = 0;
    gCinemaPlayerP->unk_0xCC = 0;
    gCinemaPlayerP->unk_0xD0 = 0;
    gCinemaPlayerP->unk_0xD4 = 0;
    gCinemaPlayerP->requestedLevel = -1;
    gCinemaPlayerP->requestedCinema = -1;
    gCinemaPlayerP->requestedType = -1;
    gCinemaPlayerP->unk_0xE4 = 0;
    gCinemaPlayerP->unk_0xE8 = 0;
    gCinemaPlayerP->unk_0xEC = 0;
    gCinemaPlayerP->unk_0xF0 = 0;
    gCinemaPlayerP->unk_0xF4 = 0;
    gCinemaPlayerP->unk_0xF8 = 0;
    gCinemaPlayerP->unk_0xFC = 0;
    gCinemaPlayerP->unk_0x100 = 0;
    gCinemaPlayerP->unk_0x104 = D_800F8D60; // this is probably an immediate float; rodata
    gCinemaPlayerP->unk_0x108 = 0;
    func_232A68();
    func_232B00();
}
#else
INCLUDE_ASM("asm/nonmatchings/cinema", Cinema__Initialize);
#endif

INCLUDE_ASM("asm/nonmatchings/cinema", func_231B74);

INCLUDE_ASM("asm/nonmatchings/cinema", func_231DDC);

INCLUDE_ASM("asm/nonmatchings/cinema", func_231ED0);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2320A4);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232414);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232574);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2325FC);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232678);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2326D0);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232700);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232718);

int32_t Cinema_PathPlaying(void) {
    return (gCinemaPlayerP->playing)
        && (gCinemaPlayerP->currentTime >= gCinemaPlayerP->pathBegin)
        && (gCinemaPlayerP->currentTime <= gCinemaPlayerP->pathEnd);
}

INCLUDE_ASM("asm/nonmatchings/cinema", func_232774);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2327A8);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2327E4);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2327F8);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232828);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232878);

INCLUDE_ASM("asm/nonmatchings/cinema", func_23288C);

INCLUDE_ASM("asm/nonmatchings/cinema", func_23289C);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2328AC);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2328BC);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2328F4);

INCLUDE_ASM("asm/nonmatchings/cinema", func_23291C);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232944);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232954);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2329B4);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232A10);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232A20);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232A30);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232A40);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232A58);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232A68);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232A94);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232AB0);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232B00);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232B10);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232B30);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232B44);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232B58);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232BB4);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232C4C);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232CD4);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232D2C);

INCLUDE_ASM("asm/nonmatchings/cinema", func_232D40);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2331A0);

INCLUDE_ASM("asm/nonmatchings/cinema", func_233204);

INCLUDE_ASM("asm/nonmatchings/cinema", func_233304);

INCLUDE_ASM("asm/nonmatchings/cinema", func_233458);

INCLUDE_ASM("asm/nonmatchings/cinema", func_23358C);

INCLUDE_ASM("asm/nonmatchings/cinema", func_2336B8);

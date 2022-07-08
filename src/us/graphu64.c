#include "common.h"
#include "graphu64.h"

#define RANDOM_SEED (3824563683UL)
#define RANDOM_ADD  (1479838765UL)
#define RANDOM_MULT (2823445331UL)

INCLUDE_ASM("asm/nonmatchings/graphu64", func_25EC10);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_25ED48);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_25F158);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_25F454);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_25F7A8);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_25FA20);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_25FE24);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_260404);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_260888);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_260A98);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_260C34);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_260E58);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_261170);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2613D0);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2615BC);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2617B0);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2619A4);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_261C34);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_261DE8);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262094);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262110);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2621A4);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26222C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26238C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2624DC);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262584);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26258C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26264C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262688);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2626D8);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262768);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2627B8);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26283C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2628E8);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2629B4);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262ADC);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262B70);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262C04);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262C54);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262CA4);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262DE0);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262F48);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262F60);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_262FE4);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2630B0);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26313C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263158);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263220);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2632B4);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2632E8);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263364);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263414);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2634B4);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263540);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2635CC);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26365C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26372C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263830);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263904);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263A04);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263AD4);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263BD8);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263C0C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263C8C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263CD0);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263D50);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263E00);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263E8C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_263F04);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264010);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2640B0);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264184);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2641EC);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264318);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264320);

s32 RandomSwapWord(void) {
    gRandomValue = (gRandomValue * RANDOM_MULT) + RANDOM_ADD;
    return ((gRandomValue << 16) | (gRandomValue >> 16)) & 0x7FFFFFFF;
}

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264388);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2643D0);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26443C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26450C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_26460C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264674);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2646DC);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264760);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2647B0);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264820);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2648FC);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2649B0);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_2649E8);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264A60);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264AE8);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264B7C);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264BF8);

INCLUDE_ASM("asm/nonmatchings/graphu64", func_264C68);

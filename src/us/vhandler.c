#include "le_vm.h"

INCLUDE_ASM("asm/nonmatchings/vhandler", VM_Initialize);

#ifdef NON_MATCHING
s32 VM_AcquireNextTLB(void) {
    s32 temp_a1;
    s32 temp_v1;
    s32 var_v0;
    u16 temp_a0;
    u16 temp_v0;

    temp_a0 = D_80126DD0.unk0;
    temp_v0 = temp_a0 + 1;
    D_80126DD0.unk0 = temp_v0;
    var_v0 = temp_a0 << 0x10;

    if ((s16) temp_v0 >= 0x18) {
        D_80126DD0.unk0 = (u16) D_80126DD0.unk2;
        var_v0 = temp_a0 << 0x10;
    }

    temp_a1 = var_v0 >> 0x10;
    temp_v1 = temp_a1 * 4;

    if (*(&D_80126D5A + temp_v1) != 0xFF) {
        *(&D_8012698B + (*(&D_80126D5A + temp_v1) * 0x10)) = 0xFF;
        *(&D_80126D5A + temp_v1) = 0xFF;
    }
    if (*(&D_80126D5B + temp_v1) != 0xFF) {
        *(&D_8012698B + (*(&D_80126D5B + temp_v1) * 0x10)) = 0xFF;
        *(&D_80126D5B + temp_v1) = 0xFF;
    }

    return temp_a1;
}
#else
INCLUDE_ASM("asm/nonmatchings/vhandler", VM_AcquireNextTLB);
#endif

INCLUDE_ASM("asm/nonmatchings/vhandler", VM_MapTLBEntry);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_225B14);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_225C80);

#ifdef NON_MATCHING
void VM_Age(void) {
    struct t_VM_Region* pRegion;
    u32 inUse;
    u32 currentAgeTemp;
    u32 index;
    u32 oldestAge;
    u32 youngestAge;
    u32* pageTableTemp;

    oldestAge = 0;
    youngestAge = 1 << 31;
    pageTableTemp = &D_8012698C;

    for (index = 0; index < VM_PHYS_PAGE_COUNT; index++) {
        currentAgeTemp = *pageTableTemp; // VM.PageTable[i].Age

        if (currentAgeTemp > oldestAge) {
            oldestAge = currentAgeTemp;
        }

        if (currentAgeTemp < youngestAge) {
            youngestAge = currentAgeTemp;
        }

        pageTableTemp += 0x10;
    }

    pRegion = &D_80126DB8; // VM.MappedRegions
    inUse = 0;
    while (pRegion) {
        pRegion = pRegion->unk0; // pRegion->pNext
        inUse += pRegion->unk6 << 0xC;
    }
    
    D_8012607C.unk0 = inUse;
    D_8012607C.unk-C = oldestAge;
    D_8012607C.unk-8 = youngestAge;
    D_8012607C.unk-4 = (s32) D_80126C50->unkC; // VM.LRU.pTail->Age
}
#else
INCLUDE_ASM("asm/nonmatchings/vhandler", VM_Age);
#endif

void osMapTLBRdb(void) {
    VM_MapTLB(31, OS_PM_1M, VM_OS_BASE, VM_MEGABYTE(0), VM_MEGABYTE(1), 7);
}

#ifdef NON_MATCHING
void* VM_Alloc(u32 size, u32 flags, u32 romBase) {
    OSMesgQueue sp10;
    s16 sp28;
    u32 sp2C;
    void* sp30;
    OSMesgQueue* sp34;
    void* sp38;
    void* sp3C;
    u32 temp_s1;
    void* temp_v1;
    void** temp_v0;

    temp_s1 = (u32) (size + 0xFFF) >> 0xC;
    osCreateMesgQueue(&sp10, &sp38, 1);
    sp28 = 3;
    sp2C = size;
    sp34 = &sp10;
    temp_v0 = func_240C98((temp_s1 * 4) + (((temp_s1 + 1) & ~1) + 0x18), 3, &D_800F8A50);
    temp_v1 = *temp_v0;
    sp30 = temp_v1;
    temp_v1->unkC = temp_v0;
    sp30->unk8 = romBase;
    osSendMesg(&D_80126084, &sp28, 1);
    osRecvMesg(&sp10, &sp3C, 1);
    return sp3C;
}
#else
INCLUDE_ASM("asm/nonmatchings/vhandler", VM_Alloc);
#endif

INCLUDE_ASM("asm/nonmatchings/vhandler", func_2262C4);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_22633C);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_22638C);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_2265CC);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_2265FC);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_22662C);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_226674);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_226740);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_226840);

INCLUDE_ASM("asm/nonmatchings/vhandler", func_226908);

#include "common.h"
#include "tengine.h"

uint32_t func_20A9E0(int32_t arg0) {
    if (arg0 == 0) {
        return (uint32_t)NULLPTR;
    }
    else {
        return (uint32_t)&D_800F20CC[arg0];
    }
}

INCLUDE_ASM("asm/nonmatchings/main/", func_20AA08);

// loading of "systembootdone" string, (particularly bzero in place of the memset for setting the null character... but why JAL for one byte?)
// additionally, missing behavior in bss clearing function
#ifdef NON_MATCHING
uint32_t gFirstBoot;
char gBootSignature[16] = "BootNotDone";

int32_t main(void) {
    char signature[16] = "systembootdone";

    if (strcmp(gBootSignature, signature) == 0) {
        gFirstBoot = 0;
    }
    else {
        gFirstBoot = 1;
        strcpy(signature, gBootSignature);
    }

    // Reset code and data if not the first boot (ie - crash recovery)
    if (!gFirstBoot) {
        register uint32_t* dest;
        register uint32_t* src;
        register uint32_t length;
        register uint32_t* status;

        length = (1024 * 1024) / 4;
        src = (uint32_t*)0xB0001000;
        dest = (uint32_t*)0x80000400;
        status = (uint32_t*)K0_TO_K1(PI_STATUS_REG);

        while (length--) {
            while (*status & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY));

            *dest = *src;

            dest++;
            src++;
        }
    }

    // Clear bss
    {
        register uint32_t* ptr;
        ptr = OS_PHYSICAL_TO_K0(0);
        while (ptr < (uint32_t*)OS_PHYSICAL_TO_K0(0)) {
            if (*ptr != 0) {
                *ptr = 0;
            }

            ptr++;
        }
    }

    osInitialize();
    boot();

    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/main/", main);
#endif

void __main(void) {
}

INCLUDE_ASM("asm/nonmatchings/main/", func_20AC08);

INCLUDE_ASM("asm/nonmatchings/main/", func_20AC50);

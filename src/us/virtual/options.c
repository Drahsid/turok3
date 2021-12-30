#include "options.h"
#include "tengine.h"
#include "include_asm.h"

// High Level Behavior the same, stack differences and stores/loads are executed differently
#ifdef NON_MATCHING
void COptions__SetDefaults(COptions* thisx) {
    int32_t index;
    int32_t playerIndex;

    thisx->unk_0x1 = 0xC0;
    thisx->unk_0x2 = 0xFF;
    thisx->unk_0x3 = 0xFF;
    thisx->unk_0x8 = 0x80;
    thisx->unk_0xB = 2;
    thisx->unk_0x0 = 1;
    thisx->unk_0x9 = 1;
    thisx->unk_0x4 = 0;
    thisx->unk_0xA = 0;
    thisx->unk_0xC = 0;
    thisx->unk_0x10 = 0;
    thisx->unk_0x1C = 1;
    thisx->unk_0x24 = 0;
    memset(&thisx->unk_0x20, 0, 4U);
    func_40B98C(0x7FFFFFFF); // writes some data in gEngineApp.options

    for (index = 1; index < MAX_PLAYERS + 1; index++) {
        playerIndex = func_204648(index); // returns a0 - 1, if it's > 4 = 4
        if (playerIndex >= 4) {
            playerIndex = 0;
        }

        thisx->multiPlayerOptions[index].unk_0x04 = index;
        gEngineApp.options.multiPlayerOptions[index].unk_0x05 = 0;
        gEngineApp.options.multiPlayerOptions[index].unk_0x09 = 0;
        thisx->multiPlayerOptions[index].playerIndex = playerIndex;
        thisx->playerControlOptions[index].unk_0x0 = 0x80;
        thisx->playerControlOptions[index].unk_0x1 = 0x80;
        thisx->playerControlOptions[index].unk_0x3 = 1;
        thisx->playerControlOptions[index].unk_0x2 = 0;
        thisx->playerControlOptions[index].unk_0x5 = 1;
        thisx->playerControlOptions[index].unk_0x4 = 0;
        thisx->playerControlOptions[index].unk_0x6 = 1;
        thisx->playerControlOptions[index].unk_0x7 = 3;
    }

    // Acclaim devs were clearly off the deep end here
    gEngineApp.options.singePlayerOptions.unk_0x04 = 0;
    gEngineApp.options.singePlayerOptions.unk_0x05 = 0;
    gEngineApp.options.singePlayerOptions.unk_0x09 = 0;
    gEngineApp.options.singePlayerOptions.playerIndex = 0;

    gEngineApp.options.singePlayerOptions.unk_0x08 = 1;
    gEngineApp.options.playerControlOptions[0].unk_0x0 = 0x80;
    gEngineApp.options.playerControlOptions[0].unk_0x1 = 0x80;
    gEngineApp.options.playerControlOptions[0].unk_0x3 = 1;
    gEngineApp.options.playerControlOptions[0].unk_0x2 = 0;
    gEngineApp.options.playerControlOptions[0].unk_0x5 = 1;
    gEngineApp.options.playerControlOptions[0].unk_0x4 = 0;
    gEngineApp.options.playerControlOptions[0].unk_0x6 = 1;
    gEngineApp.options.playerControlOptions[0].unk_0x7 = 3;
    gEngineApp.options.playerControlOptions[0].unk_0x5 = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/virtual/options", COptions__SetDefaults);
#endif

INCLUDE_ASM("asm/nonmatchings/virtual/options", func_400194);

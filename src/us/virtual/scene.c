#include "common.h"
#include "scene.h"
#include "cache.h"
#include "cartdir.h"

void func_25D534(CScene* thisx);
void func_44AE08(CScene* thisx, void* romData);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", CScene__ConstructMap);

// Need all of rodata to OK
#ifdef NON_MATCHING
void CScene__Construct(CScene* thisx, void* romData) {
    CISet* cartIndex;
    CMemEntry* memEntry;

    CScene__ClearListCounts();
    thisx->levelStatus = 0;
    CScene__ConstructWarp(thisx);

    thisx->isPersistentDataLoaded = 0;
    thisx->levelIntroFlags = 0;
    thisx->levelIndex = -1;
    thisx->unk_0x1CD08 = 0;
    thisx->unk_0x1D0A0 = 0;
    thisx->unk_0x1D0A4 = 0;
    thisx->unk_0x1D0A8 = 0;
    thisx->unk_0x1D0AC = 0;
    thisx->unk_0x1D0B0 = 0;
    thisx->unk_0x1D0B4 = 0;
    thisx->unk_0x1D0FC = 0;
    thisx->unk_0x1D140 = 0;
    thisx->unk_0x1D160 = 0;
    thisx->unk_0x1D418 = 0;
    thisx->unk_0x1D420 = 0;

    CPlayerPool__LevelStart(&gEngineApp.playerPool);

    thisx->unk_0x1D414 = 0;
    thisx->unk_0x1D424 = 0;
    thisx->unk_0x1D428 = 0;

    func_24128C(); // CCache__Compress?

    CCache__LoadPersistantIndex(&cartIndex, romData, "cartridge index");

    thisx->rpLevels = CISet__GetROMAddress(cartIndex, romData, CART_ROOT_INDEXEDSET_LEVELS);
    CCache__LoadPersistantIndex(&thisx->indexedSetLevelsIndex, thisx->rpLevels, "levels index");

    thisx->rpTextureSets = CISet__GetROMAddress(cartIndex, romData, CART_ROOT_INDEXEDSET_TEXTURE_SETS);
    CCache__LoadPersistantIndex(&thisx->indexedSetTextureSetsIndex, thisx->rpTextureSets, "texture sets index");

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_UNINDEXEDSET_OBJECT_TYPES,
        romData, thisx, ProPack__Decompress, "object types");
    thisx->unindexedSetObjectTypes = memEntry->data;

    thisx->rpObjects = CISet__GetROMAddress(cartIndex, romData, CART_ROOT_INDEXEDSET_GRAPHIC_OBJECTS);
    CCache__LoadPersistantIndex(&thisx->indexedSetObjectsIndex, thisx->rpObjects, "objects index");

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_INDEXEDSET_INTELLIGENCE,
        romData, thisx, CScene__DecompressIntelligence, "intelligence");
    thisx->indexedSetIntelligence = memEntry->data;

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_INDEXEDSET_PARTICLE_EFFECTS,
        romData, thisx, CScene__DecompressParticles, "particle effects");
    thisx->memEntryParticleEffects = memEntry->data;

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_UNINDEXEDSET_BINARY_TYPES,
        romData, thisx, ProPack__Decompress, "object types");
    thisx->unindexedSetBinaryTypes = memEntry->data;

    thisx->rpBinaries = CISet__GetROMAddress(cartIndex, romData, CART_ROOT_INDEXEDSET_BINARIES);
    CCache__LoadPersistantIndex(&thisx->indexedSetBinariesIndex, thisx->rpBinaries, "binaries index");

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_INDEXEDSET_PARTICLE_SWOOSHES,
        romData, thisx, ProPack__Decompress, "particle swooshes");
    thisx->indexedSetParticleSwooshes = memEntry->data;

    thisx->indexedSetLoadSavePersistentData = &gLoadSavePersistentData;

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_UNINDEXEDSET_DYNAMIC_LIGHTS,
        romData, thisx, ProPack__Decompress, "dynamic lights");
    thisx->unindexedSetDynamicLights = memEntry->data;

    thisx->rpLoadSavePersistentData = CISet__GetROMAddressAndSize(cartIndex,
        romData, CART_ROOT_INDEXEDSET_LOAD_SAVE_PERSISTENT_DATA, &thisx->loadSavePersistentDataSize);
    thisx->indexedSetGamePersistentData = &gGamePersistentData;
    thisx->rpGamePersistentData = CISet__GetROMAddressAndSize(cartIndex,
        romData, CART_ROOT_INDEXEDSET_GAME_PERSISTENT_DATA, &thisx->gamePersistentDataSize);

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_UNINDEXEDSET_CURVES,
        romData, thisx, ProPack__Decompress, "curves");
    thisx->unindexedSetCurves = memEntry->data;

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_UNINDEXEDSET_RUMBLES,
        romData, thisx, ProPack__Decompress, "rumbles");
    thisx->unindexedSetRumbles = memEntry->data;

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_UNINDEXEDSET_RUMBLE_TYPES,
        romData, thisx, ProPack__Decompress, "rumble types");
    thisx->unindexedSetRumbleTypes = memEntry->data;

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_UNINDEXEDSET_GRAPHICSET_TYPE,
        romData, thisx, ProPack__Decompress, "graphicset type");
    thisx->unindexedSetGraphicSetType = memEntry->data;


    thisx->rpGraphicSet = CISet__GetROMAddress(cartIndex, romData, CART_ROOT_INDEXEDSET_GRAPHICSET);
    CCache__LoadPersistantIndex(&thisx->indexedSetGraphicSetIndex, thisx->rpGraphicSet, "graphicset index");

    thisx->rpCinemas = CISet__GetROMAddress(cartIndex, romData, CART_ROOT_INDEXEDSET_CINEMAS);
    CCache__LoadPersistantIndex(&thisx->indexedSetCinemas, thisx->rpCinemas, "Cinemas index");

    func_403FA4(); // loads "Cinema Directory" using CART_ROOT_INDEXEDSET_GRAPHIC_OBJECTS

    thisx->unk_0xC = 0;
    thisx->unk_0x10 = 0;
    thisx->unk_0x14 = 0;
    thisx->unk_0x18 = -1;

    memEntry = CCache__LoadPersistantSubBlock(cartIndex, CART_ROOT_UNINDEXEDSET_LINK_GROUP_TYPES,
        romData, thisx, ProPack__Decompress, "link group types");
    thisx->unindexedSetLinkGroupTypes = memEntry->data;

    func_25D534(thisx); // sets up up shadows? (possibly for the fancy character shadows)
    func_44AE08(thisx, romData); // probably CScene__NewGame?

    gCacheIsValid = 1;

    CScene__ConstructMap(thisx, &thisx->unk_0x1CE80, 3500);
    CScene__ConstructMap(thisx, &thisx->unk_0x1CF0C, 3505);
    CScene__ConstructMap(thisx, &thisx->unk_0x1CEF0, 3504);

    thisx->memEntryLevelNavNodes = NULL;
    thisx->memEntryLevelNavLinks = NULL;
    thisx->memEntryLevelNavVision = NULL;
    thisx->unk_0xF8 = NULL;
    thisx->unk_0x8C = NULL;
    thisx->unk_0x120 = 0;
    thisx->unk_0x124 = 0;
    thisx->unk_0x1D408 = 0;
    thisx->unk_0x1D40C = -1;
    thisx->unk_0x1D410 = -1;

    CScene__LoadLevel(thisx, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/virtual/scene", CScene__Construct);
#endif

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44965C);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_4497F8);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44998C);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_449AD4);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_449DA0);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44A180);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44A9B0);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44ABEC);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44AE08);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44AE8C);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44AF20);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44AFA0);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", CScene__ConstructWarp);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44B048);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44B1DC);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44B248);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44B28C);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44B330);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44B45C);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44B4CC);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", CScene__DecompressParticles);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", CScene__DecompressIntelligence);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44B8A4);

INCLUDE_ASM("asm/nonmatchings/virtual/scene", func_44B9C0);

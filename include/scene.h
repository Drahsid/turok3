#ifndef SCENE_H
#define SCENE_H

#include "inttypes.h"
#include "list.h"
#include "SetN64.h"

typedef struct {
    /* 0x00000 */ int32_t levelStatus; // "m_LevelStatus"
    /* 0x00004 */ int32_t isPersistentDataLoaded; // "m_bPersistentDataLoaded"
    /* 0x00008 */ uint32_t levelIntroFlags; // "m_LevelIntroPlayedFlags"
    /* 0x0000C */ uint8_t unk_0xC[0x10];
    /* 0x0001C */ void* rpLevels; // "m_rpLevels"
    /* 0x00020 */ void* rpLevel; // "m_rpLevel"
    /* 0x00024 */ void* rpTextureSets; // "m_rpTextureSets"
    /* 0x00028 */ void* rpObjects; // "m_rpObjects"
    /* 0x0002C */ void* rpBinaries; // "m_rpBinaries"
    /* 0x00030 */ void* rpGraphicSet; // "m_rpGraphicSet"
    /* 0x00034 */ void* rpGridSections; // "m_rpGridSections"
    /* 0x00038 */ void* rpCinemas; // "m_rpCinemas"
    /* 0x0003C */ void* rpLoadSavePersistentData; // "m_rpLoadSavePersistentData"
    /* 0x00040 */ void* rpGamePersistentData; // "m_rpGamePersistentData"
    /* 0x00044 */ void* rpVisibility; // "m_rpVisibility"
    /* 0x00048 */ int32_t loadSavePersistentDataSize; // "m_LoadSavePersistentDataSize"
    /* 0x0004C */ int32_t gamePersistentDataSize; // "m_GamePersistentDataSize"
    /* 0x00050 */ CISet* indexedSetLevelsIndex; // "m_pisLevelsIndex"
    /* 0x00054 */ CISet* indexedSetTextureSetsIndex; // "m_pisTextureSetsIndex"
    /* 0x00058 */ CISet* indexedSetObjectsIndex; // "m_pisObjectsIndex"
    /* 0x0005C */ CISet* indexedSetBinariesIndex; // "m_pisBinariesIndex"
    /* 0x00060 */ CISet* indexedSetGraphicSetIndex; // "m_pisGraphicSetIndex"
    /* 0x00064 */ CISet* indexedSetLevelIndex; // "m_pisLevelIndex"
    /* 0x00068 */ CISet* unk_0x68;
    /* 0x0006C */ CISet* indexedSetGridBounds; // "m_pisGridBounds"
    /* 0x00070 */ CISet* indexedSetCollision; // "m_pisCollision"
    /* 0x00074 */ CISet* indexedSetParticleSwooshes; // "m_pisParticleSwooshes"
    /* 0x00078 */ CISet* indexedSetCinemas; // "m_pisCinemas"
    /* 0x0007C */ CISet* indexedSetIntelligence; // "m_pisIntelligence"
    /* 0x00080 */ CISet* unk_0x80;
    /* 0x00084 */ CISet* indexedSetLoadSavePersistentData; // "m_pisLoadSavePersistentData"
    /* 0x00088 */ CISet* indexedSetGamePersistentData; // "m_pisGamePersistentData"
    /* 0x0008C */ CISet* unk_0x8C;
    /* 0x00090 */ CISet* indexedSetVisibilityIndex; // "m_pisVisibilityIndex"
    /* 0x00094 */ CUSet* unindexedSetObjectTypes; // "m_pusObjectTypes"
    /* 0x00098 */ CUSet* unindexedSetBinaryTypes; // "m_pusBinaryTypes"
    /* 0x0009C */ CUSet* unindexedSetGraphicSetType; // "m_pusGraphicSetType"
    /* 0x000A0 */ CUSet* unindexedSetDynamicLights; // "m_pusDynamicLights"
    /* 0x000A4 */ CUSet* unindexedSetCurves; // "m_pusCurves"
    /* 0x000A8 */ CUSet* unindexedSetRumbleTypes; // "m_pusRumbleTypes"
    /* 0x000AC */ CUSet* unindexedSetRumbles; // "m_pusRumbles"
    /* 0x000B0 */ CUSet* unindexedSetLinkGroupTypes; // "m_pusLinkGroupTypes"
    /* 0x000B4 */ struct CMemEntry* memEntryParticleEffects; // "m_pmeParticleEffects"
    /* 0x000B8 */ struct CMemEntry* memEntryLevelIndex; // "m_pmeLevelIndex"
    /* 0x000BC */ struct CMemEntry* memEntryCollision; // "m_pmeCollision"
    /* 0x000C0 */ struct CMemEntry* memEntryGridBounds; // "m_pmeGridBounds"
    /* 0x000C4 */ struct CMemEntry* memEntryGridSectionsIndex; // "m_pmeGridSectionsIndex"
    /* 0x000C8 */ struct CMemEntry* memEntryLevelInfo; // "m_pmeLevelInfo"
    /* 0x000CC */ struct CMemEntry* memEntrySkyLayers; // "m_pmeSkyLayers"
    /* 0x000D0 */ struct CMemEntry* memEntryAnimInstances; // "m_pmeAnimInstances"
    /* 0x000D4 */ struct CMemEntry* memEntryLinks; // "m_pmeLinks"
    /* 0x000D8 */ struct CMemEntry* unk_0xD8;
    /* 0x000DC */ struct CMemEntry* unk_0xDC;
    /* 0x000E0 */ struct CMemEntry* unk_0xE0;
    /* 0x000E4 */ struct CMemEntry* unk_0xE4;
    /* 0x000E8 */ struct CMemEntry* memEntryMatrices; // "m_pmeMatrices"
    /* 0x000EC */ struct CMemEntry* memEntryPaths; // "m_pmePaths"
    /* 0x000F0 */ struct CMemEntry* memEntryLevelNavNodes; // "m_pmeLevelNavNodes"
    /* 0x000F4 */ struct CMemEntry* memEntryLevelNavLinks; // "m_pmeLevelNavLinks"
    /* 0x000F8 */ struct CMemEntry* unk_0xF8;
    /* 0x000FC */ struct CMemEntry* memEntryLevelNavVision; // "m_pmeLevelNavVision"
    /* 0x00100 */ struct CMemEntry* memEntryVisibility; // "m_pmeVisibility"
    /* 0x00104 */ uint8_t unk_0x104[0x1D32C];
} CScene; /* sizeof = 0x1D430 */

#define GetScene() (&gEngineApp.scene)

#endif


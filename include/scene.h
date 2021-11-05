#ifndef SCENE_H
#define SCENE_H

#include "inttypes.h"
#include "list.h"
#include "SetN64.h"

typedef struct {
    /* 0x00000 */ int32_t m_LevelStatus;
    /* 0x00004 */ int32_t m_bPersistentDataLoaded;
    /* 0x00008 */ uint32_t m_LevelIntroPlayedFlags;
    /* 0x0000C */ uint8_t unk_0xC[0x10];
    /* 0x0001C */ void* m_rpLevels;
    /* 0x00020 */ void* m_rpLevel;
    /* 0x00024 */ void* m_rpTextureSets;
    /* 0x00028 */ void* m_rpObjects;
    /* 0x0002C */ void* m_rpBinaries;
    /* 0x00030 */ void* m_rpGraphicSet;
    /* 0x00034 */ void* m_rpGridSections;
    /* 0x00038 */ void* m_rpCinemas;
    /* 0x0003C */ void* m_rpLoadSavePersistentData;
    /* 0x00040 */ void* m_rpGamePersistentData;
    /* 0x00044 */ void* m_rpVisibility;
    /* 0x00048 */ int32_t m_LoadSavePersistentDataSize;
    /* 0x0004C */ int32_t m_GamePersistentDataSize;
    /* 0x00050 */ CISet* m_pisLevelsIndex;
    /* 0x00054 */ CISet* m_pisTextureSetsIndex;
    /* 0x00058 */ CISet* m_pisObjectsIndex;
    /* 0x0005C */ CISet* m_pisBinariesIndex;
    /* 0x00060 */ CISet* m_pisGraphicSetIndex;
    /* 0x00064 */ CISet* m_pisLevelIndex;
    /* 0x00068 */ CISet* unk_0x68;
    /* 0x0006C */ CISet* m_pisGridBounds;
    /* 0x00070 */ CISet* m_pisCollision;
    /* 0x00074 */ CISet* m_pisParticleSwooshes;
    /* 0x00078 */ CISet* m_pisCinemas;
    /* 0x0007C */ CISet* m_pisIntelligence;
    /* 0x00080 */ CISet* unk_0x80;
    /* 0x00084 */ CISet* m_pisLoadSavePersistentData;
    /* 0x00088 */ CISet* m_pisGamePersistentData;
    /* 0x0008C */ CISet* unk_0x8C;
    /* 0x00090 */ CISet* m_pisVisibilityIndex;
    /* 0x00094 */ CUSet* m_pusObjectTypes;
    /* 0x00098 */ CUSet* m_pusBinaryTypes;
    /* 0x0009C */ CUSet* m_pusGraphicSetType;
    /* 0x000A0 */ CUSet* m_pusDynamicLights;
    /* 0x000A4 */ CUSet* m_pusCurves;
    /* 0x000A8 */ CUSet* m_pusRumbleTypes;
    /* 0x000AC */ CUSet* m_pusRumbles;
    /* 0x000B0 */ CUSet* m_pusLinkGroupTypes;
    /* 0x000B4 */ struct CMemEntry* m_pmeParticleEffects;
    /* 0x000B8 */ struct CMemEntry* m_pmeLevelIndex;
    /* 0x000BC */ struct CMemEntry* m_pmeCollision;
    /* 0x000C0 */ struct CMemEntry* m_pmeGridBounds;
    /* 0x000C4 */ struct CMemEntry* m_pmeGridSectionsIndex;
    /* 0x000C8 */ struct CMemEntry* m_pmeLevelInfo;
    /* 0x000CC */ struct CMemEntry* m_pmeSkyLayers;
    /* 0x000D0 */ struct CMemEntry* m_pmeAnimInstances;
    /* 0x000D4 */ struct CMemEntry* m_pmeLinks;
    /* 0x000D8 */ struct CMemEntry* unk_0xD8;
    /* 0x000DC */ struct CMemEntry* unk_0xDC;
    /* 0x000E0 */ struct CMemEntry* unk_0xE0;
    /* 0x000E4 */ struct CMemEntry* unk_0xE4;
    /* 0x000E8 */ struct CMemEntry* m_pmeMatrices;
    /* 0x000EC */ struct CMemEntry* m_pmePaths;
    /* 0x000F0 */ struct CMemEntry* m_pmeLevelNavNodes;
    /* 0x000F4 */ struct CMemEntry* m_pmeLevelNavLinks;
    /* 0x000F8 */ struct CMemEntry* unk_0xF8;
    /* 0x000FC */ struct CMemEntry* m_pmeLevelNavVision;
    /* 0x00100 */ struct CMemEntry* m_pmeVisibility;
    /* 0x00104 */ uint8_t unk_0x104[0x1D32C];
} CScene; /* sizeof = 0x1D430 */

#define GetScene() (&gEngineApp.m_Scene)

#endif


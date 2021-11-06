#ifndef CAMERA_H
#define CAMERA_H

#include "inttypes.h"
#include "list.h"
#include "common_structs.h"
#include <ultra64.h>

typedef struct {
	/* 0x00 */ float width;         // "m_Width"
	/* 0x04 */ float height;        // "m_Height"
	/* 0x08 */ float screenPosX;    // "m_ScreenPosX"
	/* 0x0C */ float screenPosY;    // "m_ScreenPosY"
} CCameraViewport; /* sizeof = 0x10 */

typedef struct {
    /* 0x00 */ int32_t type;                // "m_nType"
    /* 0x04 */ float rotY;                  // "m_RotY"
    /* 0x08 */ CVector3 rotOffset;          // "m_vRotOffset"
    /* 0x14 */ CVector3 pos;                // "m_vPos"
    /* 0x20 */ float yPosOffset;            // "m_YPosOffset"
    /* 0x24 */ CQuaternion groundQuat;      // "m_qGround"
    /* 0x34 */ void* unk_0x34;
    /* 0x38 */ float zoomBlend;             // "m_ZoomBlend"
    /* 0x3C */ float zoomFov;               // "m_ZoomFov"
    /* 0x40 */ uint32_t visibilityFlags;    // "m_VisBits"
} CCameraViewParams; /* sizeof = 0x44 */

typedef struct CCamera {
    /* 0x000 */ struct CCamera* prev;               // "m_pLast"
    /* 0x004 */ struct CCamera* next;               // "m_pNext"
    /* 0x008 */ int32_t index;                      // "m_Index"
    /* 0x00C */ float pixelScaleX;                  // "m_PixelXScale"
    /* 0x010 */ float pixelScaleY;                  // "m_PixelYScale"
    /* 0x014 */ int16_t currentMode;                // "m_Mode"
    /* 0x016 */ int16_t _pad0;
    /* 0x018 */ float time;                         // "m_Time"
    /* 0x01C */ int16_t stage;                      // "m_Stage"
    /* 0x01E */ int16_t _pad1;
    /* 0x020 */ float stageTime;                    // "m_StageTime"
    /* 0x024 */ CCameraViewParams viewParams;       // "m_ViewParams"
    /* 0x068 */ uint8_t unk_0x68[0x18];
    /* 0x080 */ float viewScaleX;                   // "m_XScale"
    /* 0x084 */ float viewScaleY;                   // "m_YScale"
    /* 0x088 */ uint8_t unk_0x88[0x74];
    /* 0x0FC */ int32_t warpMode;                   // "m_WarpMode"
    /* 0x100 */ float warpTime;                     // "m_WarpTime"
    /* 0x104 */ CVector3 warpPos;                   // "m_vWarpPos"
    /* 0x110 */ float warpScaleX;                   // "m_WarpXScale"
    /* 0x114 */ float warpScaleY;                   // "m_WarpYScale"
    /* 0x118 */ float warpSpin;                     // "m_WarpSpin"
    /* 0x11C */ uint8_t unk_0x11C[0x24];
    /* 0x140 */ CQuaternion viewAlignmentQuat;      // "m_qViewAlign"
    /* 0x150 */ CQuaternion viewAlignmentQuatNoZ;   // "m_qViewAlignNoZ"
    /* 0x160 */ CMtxF viewOrientationMatrix;        // "m_mfViewOrient"
    /* 0x1A0 */ CMtxF viewOrientationMatrixInverse; // "m_mfInverseViewOrient"
    /* 0x1E0 */ CMtxF projectionMatrix;             // "m_mfProjection"
    /* 0x220 */ CMtxF viewMatrix;                   // "m_mfView"
    /* 0x260 */ CVector3 viewCorners[5];            // "m_vTCorners" corners and center point of view
    /* 0x29C */ CCameraViewport cameraViewport;     // "m_Viewport"
    /* 0x2AC */ Vp_t vp0[2];                        // "m_vp"
    /* 0x2CC */ Vp_t vp1[2];                        // "m_vpSecondary"
    /* 0x2EC */ uint8_t unk_0x2EC[0x22C];
    /* 0x518 */ int32_t currentRegionSet;           // "m_nCurrentRegionSet"
    /* 0x51C */ float currentRegionSetBlend;        // "m_cRegionSetBlend"
    /* 0x520 */ uint8_t fogColor[4];                // "m_FogColor"
    /* 0x524 */ uint8_t lastFogColor[4];            // "m_LastFogColor"
    /* 0x528 */ float farClip;                      // "m_FarClip"
    /* 0x52C */ float lastFarClip;                  // "m_LastFarClip"
    /* 0x530 */ float fov;                          // "m_FieldOfView"
    /* 0x534 */ float lastFov;                      // "m_LastFieldOfView"
    /* 0x538 */ float unk_0x538;
    /* 0x53C */ int32_t fogStart;                   // "m_FogStart"
    /* 0x540 */ int32_t lastFogStart;               // "m_LastFogStart"
    /* 0x544 */ uint8_t unk_0x544[0x8F8];
    /* 0xE3C */ CMtxF screenAlignmentMatrix;        // "m_mfFaceScreen"
    /* 0xE7C */ CMtxF screenAlignmentMatrixWorldUp; // "m_mfFaceScreenYAxisUp"
} CCamera; /* sizeof = 0xEBC */

typedef struct {
    /* 0x0000 */ struct CMemEntry* camerasMemEntry; // "m_pmeCameras"
    /* 0x0004 */ CCamera* cameras;                  // "m_Cameras"
    /* 0x0008 */ int32_t cameraCount;               // "m_nCameras"
    /* 0x000C */ CList freeList;                    // "m_FreeList"
    /* 0x0020 */ CList activeList;                  // "m_ActiveList"
    /* 0x0034 */ int32_t activeLastFrame;           // "m_ActiveLastFrame"
    /* 0x0038 */ int32_t activeChanged;             // "m_bActiveChanged"
    /* 0x003C */ int32_t _pad0;
    /* 0x0040 */ CCamera mainCamera;                // "m_MainCamera"
    /* 0x0F00 */ struct CMemEntry* textsMemEntry;   // "m_pmeTexts"
    /* 0x0F04 */ struct CCameraText* texts;         // "m_Texts"
    /* 0x0F08 */ int32_t textCount;                 // "m_nTexts"
    /* 0x0F0C */ CList freeListText;                // "m_FreeTextList"
    /* 0x0F20 */ uint8_t unk_0xF20[0x2A0];          // m_ShakeVars in T2, probably the same here
    /* 0x11C0 */ CList freeListShake;               // "m_ShakeFreeList"
    /* 0x11D4 */ CList activeListShake;             // "m_ShakeActiveList"
    /* 0x11E8 */ int32_t useOnlyMainCameraForSound; // "m_bOnlyUseMainCameraForSound"
    /* 0x11EC */ int32_t _pad1;
} CCameraPool; /* sizeof = 0x11F0 */

#endif


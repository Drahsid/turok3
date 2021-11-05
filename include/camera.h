#ifndef CAMERA_H
#define CAMERA_H

#include "inttypes.h"
#include "list.h"
#include "common_structs.h"
#include <ultra64.h>

typedef struct {
	/* 0x00 */ float m_Width;
	/* 0x04 */ float m_Height;
	/* 0x08 */ float m_ScreenPosX;
	/* 0x0C */ float m_ScreenPosY;
} CCameraViewport; /* sizeof = 0x10 */

typedef struct {
    /* 0x00 */ int m_nType;
    /* 0x04 */ float m_RotY;
    /* 0x08 */ CVector3 m_vRotOffset;
    /* 0x14 */ CVector3 m_vPos;
    /* 0x20 */ float m_YPosOffset;
    /* 0x24 */ CQuaternion m_qGround;
    /* 0x34 */ void* unk_0x34;
    /* 0x38 */ float m_ZoomBlend;
    /* 0x3C */ float m_ZoomFov;
    /* 0x40 */ uint32_t m_VisBits;
} CCameraViewParams; /* sizeof = 0x44 */

typedef struct CCamera {
    /* 0x000 */ struct CCamera* m_pLast;
    /* 0x004 */ struct CCamera* m_pNext;
    /* 0x008 */ int m_Index;
    /* 0x00C */ float m_PixelXScale;
    /* 0x010 */ float m_PixelYScale;
    /* 0x014 */ int16_t m_Mode;
    /* 0x016 */ int16_t _pad0;
    /* 0x018 */ float m_Time;
    /* 0x01C */ int16_t m_Stage; // Very interesting member organization here
    /* 0x01E */ int16_t _pad1;
    /* 0x020 */ float m_StageTime;
    /* 0x024 */ CCameraViewParams m_ViewParams;
    /* 0x068 */ uint8_t unk_0x68[0x24];
    /* 0x080 */ float m_XScale;
    /* 0x084 */ float m_YScale;
    /* 0x088 */ uint8_t unk_0x88[0x74];
    /* 0x0FC */ int m_WarpMode;
    /* 0x100 */ float m_WarpTime;
    /* 0x104 */ CVector3 m_vWarpPos;
    /* 0x110 */ float m_WarpXScale;
    /* 0x114 */ float m_WarpYScale;
    /* 0x118 */ float m_WarpSpin;
    /* 0x11C */ uint8_t unk_0x11C[0x24];
    /* 0x140 */ CQuaternion m_qViewAlign;
    /* 0x150 */ CQuaternion m_qViewAlignNoZ;
    /* 0x160 */ CMtxF m_mfViewOrient;
    /* 0x1A0 */ CMtxF m_mfInverseViewOrient;
    /* 0x1E0 */ CMtxF m_mfProjection;
    /* 0x220 */ CMtxF m_mfView;
    /* 0x260 */ CVector3 m_vTCorners[5];
    /* 0x29C */ CCameraViewport m_Viewport;
    /* 0x2AC */ Vp m_vp[2];
    /* 0x2CC */ Vp m_vpSecondary[2];
    /* 0x2E0 */ uint8_t unk_0x2E0[0x250];
    /* 0x518 */ int m_nCurrentRegionSet;
    /* 0x51C */ float m_cRegionSetBlend;
    /* 0x520 */ uint8_t m_FogColor[4];
    /* 0x524 */ uint8_t m_LastFogColor[4];
    /* 0x528 */ float m_FarClip;
    /* 0x52C */ float m_LastFarClip;
    /* 0x530 */ float m_FieldOfView;
    /* 0x534 */ float m_LastFieldOfView;
    /* 0x538 */ float unk_0x538;
    /* 0x53C */ int m_FogStart;
    /* 0x540 */ int m_LastFogStart;
    /* 0x544 */ uint8_t unk_0x544[0x8F8];
    /* 0xE3C */ CMtxF m_mfFaceScreen;
    /* 0xE7C */ CMtxF m_mfFaceScreenYAxisUp;
} CCamera; /* sizeof = 0xEBC */

typedef struct {
    /* 0x0000 */ struct CMemEntry* m_pmeCameras;
    /* 0x0004 */ CCamera* m_Cameras;
    /* 0x0008 */ int m_nCameras;
    /* 0x000C */ CList m_FreeList;
    /* 0x0020 */ CList m_ActiveList;
    /* 0x0034 */ int m_ActiveLastFrame;
    /* 0x0038 */ int m_bActiveChanged;
    /* 0x003C */ int _pad0;
    /* 0x0040 */ CCamera m_MainCamera;
    /* 0x0F00 */ struct CMemEntry* m_pmeTexts;
    /* 0x0F04 */ struct CCameraText* m_Texts;
    /* 0x0F08 */ int m_nTexts;
    /* 0x0F0C */ CList m_FreeTextList;
    /* 0x0F20 */ uint8_t unk_0xF20[0x2A0]; // m_ShakeVars in T2, probably the same here
    /* 0x11C0 */ CList m_ShakeFreeList;
    /* 0x11D4 */ CList m_ShakeActiveList;
    /* 0x11E8 */ int m_bOnlyUseMainCameraForSound;
    /* 0x11EC */ int _pad1;
} CCameraPool; /* sizeof = 0x11F0 */

#endif


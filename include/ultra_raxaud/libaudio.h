#ifndef T3_LIBAUDIO_ACCLAIM
#define T3_LIBAUDIO_ACCLAIM

#include <PR/ultratypes.h>
#include <PR/libaudio.h>

enum {
    /* 0x00 */ __AL_ADPCM_WAVE = 0,
    /* 0x01 */ __AL_RAW16_WAVE,
    /* 0x02 */ AL_RAX_WAVE
};

typedef struct {
    /* 0x00 */ u32 start;
    /* 0x04 */ u32 end;
    /* 0x08 */ u32 count;
} ALRaxLoop; /* sizeof = 0x0C */

typedef struct {
    /* 0x00 */ ALRaxLoop* loop;
} ALRaxWaveInfo; /* sizeof = 0x04 */

typedef struct {
    /* 0x00 */ u8* base;   /* ptr to start of wave data */
    /* 0x04 */ s32 len;    /* length of data in bytes */
    /* 0x08 */ u8 type;    /* compression type */
    /* 0x09 */ u8 flags;   /* offset/address flags */
    /* 0x0C */ union {
        ALADPCMWaveInfo adpcmWave;
        ALRAWWaveInfo rawWave;
        ALRaxWaveInfo raxWave;
    } waveInfo;
} ALWaveTableAcclaim; /* sizeof = 0x14 */

typedef struct {
    /* 0x04 */ s32 len;
    /* 0x08 */ u8 type;
    /* 0x09 */ u8 _pad0[3];
    /* 0x0C */ u32 loop;
    /* 0x10 */ u32 _pad1;
    /* 0x00 */ u8* base;
} ALWaveTableAcclaim_FAKEMATCH;

typedef struct {
    /* 0x00 */ s32 sampleRate;
    /* 0x04 */ s32 length;
    /* 0x08 */ s32 unk_0x08;
    /* 0x0C */ s32 rax_unk_0x04; // unk_0x04 from the header
    /* 0x10 */ s32 remainingSamples; // ???
    /* 0x14 */ u32 audioOffset; // rom pointer to current audio sample in file ???
} RaxHeader; /* sizeof = 0x18 */

typedef struct {
    /* 0x00 */ s32 sampleRate;
    /* 0x04 */ s32 unk_0x04;
    /* 0x08 */ s32 length;
    /* 0x0C */ u8 data[1];
} RaxRomHeader; /* sizeof = 0x0C + length */

typedef struct {
    u8 unk_0x00[512];
} struct_D_80172D60; /* sizeof = 0x200 */

extern s16 D_8010BDEE;
extern s16 D_8010BDF0;
extern s16 D_8010BDE8;
extern s16 D_8010BDEA;
extern s16 D_8010BDEC;
extern s32 __osRaxStatus;
extern RaxHeader gRAX;
extern u16 D_8010BDF2; // index into D_80172D60
extern struct_D_80172D60 D_80172D60[];

extern void func_2E1358(s32, s32, s32, s32);
extern void ReadCmpFrame(void*);
extern void DecompressFrame(struct_D_80172D60*, void*);

extern void func_2E1990(u32 unused, RaxRomHeader* arg1); // arg1 possibly not RAXHeader*, just reusing the struct
extern s16 RoundSample(f32 arg0);
extern s32 alRaxStatus(void);
extern void alRaxKill(void);
extern ALMicroTime alRaxOpen(RaxRomHeader* base, s32 outputRate, s32* sampleRate);
extern ALMicroTime func_2DE6F0(u64 a0, s32 a2, s32 outputRate);

#endif


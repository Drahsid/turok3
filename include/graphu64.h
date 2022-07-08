#ifndef T3_GRAPHU64_H
#define T3_GRAPHU64_H

#include "common.h"

#define CVector3__Dot(LHS, RHS) ((LHS)->x * (RHS)->x + (LHS)->y * (RHS)->y + (LHS)->z * (RHS)->z)
#define CVector3__SquareMagnitude(THIS) ((THIS)->x * (THIS)->x + (THIS)->y * (THIS)->y + (THIS)->z * (THIS)->z)
#define CVector3__Magnitude(THIS) (sqrtf(CVector3__SquareMagnitude(THIS)))

extern u32 gRandomValue;

extern s32 RandomSwapWord(void);

static inline void CVector3__Add(CVector3* thisx, CVector3* lhs, CVector3* rhs) {
    thisx->x = lhs->x + rhs->x;
    thisx->y = lhs->y + rhs->y;
    thisx->z = lhs->z + rhs->z;
}

static inline void CVector3__Subtract(CVector3* thisx, CVector3* lhs, CVector3* rhs) {
    thisx->x = lhs->x - rhs->x;
    thisx->y = lhs->y - rhs->y;
    thisx->z = lhs->z - rhs->z;
}

static inline void CVector3__MultScaler(CVector3* thisx, CVector3* lhs, f32 rhs) {
    thisx->x = lhs->x - rhs;
    thisx->y = lhs->y - rhs;
    thisx->z = lhs->z - rhs;
}

static inline void CVector3__Cross(CVector3* thisx, CVector3* lhs, CVector3* rhs) {
    thisx->x = lhs->y * rhs->z - lhs->z * rhs->y;
    thisx->y = lhs->z * rhs->x - lhs->x * rhs->z;
    thisx->z = lhs->x * rhs->y - lhs->y * rhs->x;
}

static inline void CVector3__Normalize(CVector3* thisx) {
    f32 length;
    f32 norm;

    length = CVector3__Magnitude(thisx);
    if (length != 0) {
        norm = 1.0f / length;
        thisx->x *= norm;
        thisx->y *= norm;
        thisx->z *= norm;
    }
}

#endif


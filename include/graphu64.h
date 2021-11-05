#ifndef GRAPHU64_H
#define GRAPHU64_H

#include "common_structs.h"

#define CVector3__Dot(LHS, RHS) ((LHS)->x * (RHS)->x + (LHS)->y * (RHS)->y + (LHS)->z * (RHS)->z)
#define CVector3__SquareMagnitude(THIS) ((THIS)->x * (THIS)->x + (THIS)->y * (THIS)->y + (THIS)->z * (THIS)->z)
#define CVector3__Magnitude(THIS) (sqrtf(CVector3__SquareMagnitude(THIS)))

inline void CVector3__Add(CVector3* thisx, CVector3* lhs, CVector3* rhs);
inline void CVector3__Subtract(CVector3* thisx, CVector3* lhs, CVector3* rhs);
inline void CVector3__MultScaler(CVector3* thisx, CVector3* lhs, float rhs);
inline void CVector3__Cross(CVector3* thisx, CVector3* lhs, CVector3* rhs);
inline void CVector3__Normalize(CVector3* thisx);

#endif


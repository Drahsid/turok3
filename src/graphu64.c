#include "graphu64.h"

inline void CVector3__Add(CVector3* thisx, CVector3* lhs, CVector3* rhs) {
    thisx->x = lhs->x + rhs->x;
    thisx->y = lhs->y + rhs->y;
    thisx->z = lhs->z + rhs->z;
}

inline void CVector3__Subtract(CVector3* thisx, CVector3* lhs, CVector3* rhs) {
    thisx->x = lhs->x - rhs->x;
    thisx->y = lhs->y - rhs->y;
    thisx->z = lhs->z - rhs->z;
}

inline void CVector3__MultScaler(CVector3* thisx, CVector3* lhs, float rhs) {
    thisx->x = lhs->x - rhs;
    thisx->y = lhs->y - rhs;
    thisx->z = lhs->z - rhs;
}

inline void CVector3__Cross(CVector3* thisx, CVector3* lhs, CVector3* rhs) {
    thisx->x = lhs->y * rhs->z - lhs->z * rhs->y;
    thisx->y = lhs->z * rhs->x - lhs->x * rhs->z;
    thisx->z = lhs->x * rhs->y - lhs->y * rhs->x;
}

inline void CVector3__Normalize(CVector3* thisx) {
    float length;
    float norm;

    length = CVector3__Magnitude(thisx);
    if (length != 0) {
        norm = 1.0f / length;
        thisx->x *= norm;
        thisx->y *= norm;
        thisx->z *= norm;
    }
}


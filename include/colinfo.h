#ifndef COLINFO_H
#define COLINFO_H

#include "inttypes.h"

extern UNK_TYPE gCollisionResults; // "collision_results"
extern struct CCollisionResults* gCollisionResultsP; // "p_collision_results"
extern UNK_TYPE gCollisionSetupTable[]; // "CollisionSetupTable" this is virtual data @ 0x004480E0

extern void CCollisionInfo__Reset(void);
extern void CCollisionSetup__Construct(struct CCollisionSetup* thisx);

#endif


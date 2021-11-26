#ifndef SCSI_C_H
#define SCSI_C_H

#include "inttypes.h"

typedef uint32_t (*SCSI_MessageFunc)(uint32_t);

extern SCSI_MessageFunc gScsiMessageFunc;

extern void SCSI_PollHost(void);
extern void SCSI_SetMessageFunc(SCSI_MessageFunc func);

#endif


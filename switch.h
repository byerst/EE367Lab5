#include "queue.h"
#include "table.h"
/* 
 * Created this file
 * switch.h 
 */
#ifndef SWITCH_H
#define SWITCH_H

#define NAME_LENGTH 100 
#define MAX_SWITCH_LINKS 10
#define NUMSWITCHES 1

typedef struct { /* State of host */
   int   physid;              /* physical id */
   int inputSize;
   int outputSize;
   LinkInfo* linkin;           /* Incoming communication link */
   LinkInfo* linkout;          /* Outgoing communication link */
   Table table;
   Queue packetQ;
} switchState;

void switchMain(switchState * sstate);

void switchInit(switchState * sstate, int physid);

#endif

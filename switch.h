/* 
 * Created this file
 * switch.h 
 */

#define NAME_LENGTH 100 

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


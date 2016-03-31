/* 
 * This is the source code for the switch.  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <unistd.h>
#include <fcntl.h>

#include "main.h"
#include "utilities.h"
#include "link.h"
#include "man.h"
#include "host.h"
#include "switch.h"

#define EMPTY_ADDR  0xffff  /* Indicates that the empty address */
                             /* It also indicates that the broadcast address */
#define MAXBUFFER 1000
#define PIPEWRITE 1 
#define PIPEREAD  0
#define TENMILLISEC 10000   /* 10 millisecond sleep */

void switchMain(switchState * sState)
{
	int i = 0;
	int j = 0;
	int packetSize = 0;
	int outLink = 0;
	int inLink = 0;
	packetBuffer tBuff[5];
	int size = 0;

while(1) {

	/* Check if there is something to receive from incoming links */
	for (i = 0; i < sState->inputSize; i++){
		packetSize = linkReceive(&(sState->linkin[i]), tBuff, &size);
		
		// If there is a packet
		if(packetSize > 0){
			for(j = 0; j < size; j++){
				// either add value to table or update table
				updateTable(&(sState->table), tBuff[j].valid, tBuff[j].srcaddr, i);
				PushQueue(tBuff[j], &(sState->packetQ));
			}
		}
	}

	// If queue not empty
	if(!(isEmpty(&(sState->packetQ)))){
		tBuff[0] = PopQueue(&(sState->packetQ));
		
		if(tBuff[0].srcaddr != -1){
			outLink = getOutLink(&(sState->table), tBuff[0].dstaddr);

			// If link in table
			if(outLink != -1)
				linkSend(&(sState->linkout[outLink]), &tBuff[0]);
			else{
				// we have srcaddr link
				inLink = getOutLink(&(sState->table), tBuff[0].srcaddr);
				
				// send it to all but incoming link
				for(i = 0; i < sState->outputSize; i++){
					if(i != inLink){
						linkSend(&(sState->linkout[i]), &(tBuff[0]));
					}
				}
			}
		}
	}
	usleep(TENMILLISEC);
}
}

void switchInit(switchState * sState, int physid)
{
	sState->inputSize = 0;
	sState->outputSize = 0;
	sState->physid = physid;
	InitQueue(&(sState->packetQ));
	initTable(&(sState->table));
}


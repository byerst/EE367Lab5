#include "main.h"
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 10

typedef struct {
	packetBuffer packetArray[MAX_QUEUE];
	int head;
	int tail;
	int size;
} Queue;

void InitQueue(Queue* queue);
void PushQueue(packetBuffer packet, Queue* queue);
packetBuffer PopQueue(Queue* queue);
int isEmpty(Queue* queue);

#endif

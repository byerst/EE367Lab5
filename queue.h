#include "main.h"

#define MAX_QUEUE 100000

typedef struct {
	packetBuffer packetArray[MAX_QUEUE];
	int head;
	int tail;
	int size;
} Queue;

void InitQueue(Queue* queue);
void PushQueue(packetBuffer packet, Queue* queue);
packetBuffer PopQueue(Queue* queue);

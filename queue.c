#include <stdio.h>
#include "queue.h"

const packetBuffer ERROR_PACKET = {
	.srcaddr = -1,
	.dstaddr = -1,
	.length = -1,
	.valid = -1
};

void InitQueue(Queue* queue) {
	queue->head = 0;
	queue->tail = 0;
	queue->size = 0;
}

void printQueue(Queue* queue) {
	int i;
	for (i = 0; i < queue->size; i++) {
		printf("%d\n", queue->packetArray[i]);
	}
}
 
void PushQueue(packetBuffer packet, Queue* queue) {
	if(queue->size >= MAX_QUEUE){
		printf("Queue is full\n");
		return;
	}
	queue->packetArray[queue->tail] = packet;
	queue->tail++;
	queue->size++;
}

packetBuffer PopQueue(Queue* queue) {
	if(queue->size==0){
		printf("Queue is empty\n");
		return ERROR_PACKET;
	}
	packetBuffer temp;
	temp = queue->packetArray[queue->head];
	queue->head++;
	queue->size--;
	return temp;
}

int isEmpty(Queue* queue) {
	if(queue->size==0){
		printf("Queue is empty\n");
		return 1;
	}
	else {
		printf("Queue is not empty\n");
		return 0;
	}
}

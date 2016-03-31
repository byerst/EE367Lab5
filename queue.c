#include <stdio.h>
#include "queue.h"

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
		return;
	}
	packetBuffer temp;
	temp = queue->packetArray[queue->head];
	queue->head++;
	queue->size--;
	return temp;
}



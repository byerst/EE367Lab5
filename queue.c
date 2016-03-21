#include <stdio.h>
#include "queue.h"

void InitQueue(Queue* queue) {
	queue->head = 0;
	queue->tail = 0;
	queue->size = 0;
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

packetbuffer PopQueue(Queue* queue) {
	if(queue->size==0){
		printf("Queue is empty\n");
		return;
	}
	packetbuffer temp;
	temp = queue->packetArray[queue->head];
	queue->head++;
	queue->size--;
	return temp;
}



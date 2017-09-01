#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct DynArrayQueue {
	int front, rear;
	int capacity;
	int *array;
};

struct DynArrayQueue *CreateDynQueue() {
	struct DynArrayQueue *Q = malloc(sizeof(struct DynArrayQueue));
	if (!Q) {
		return NULL;
	}
	Q->capacity = 1;
	Q->front = Q->rear = -1;
	Q->array = malloc(Q->capacity * sizeof(int));
	if (!Q->array) {
		return NULL;
	}
	return Q;
};

int IsEmptyQueue(struct DynArrayQueue *Q) {
	return (Q->front == -1);
};

int IsFullQueue(struct DynArrayQueue *Q) {
	return ((Q->rear + 1) % Q->capacity == Q->front);
};

int QueueSize(struct DynArrayQueue *Q) {
	return ((Q->capacity - Q->front + Q->rear + 1) % Q->capacity);
};

int main(int argc, char const* argv[])
{
	
	return 0;
}

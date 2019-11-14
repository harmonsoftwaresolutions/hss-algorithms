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
	printf("Q->capacity %d, Q->front %d, Q->rear %d\n", Q->capacity, Q->front, Q->rear);
	return ((Q->capacity - Q->front + Q->rear + 1) % Q->capacity);
};

void ResizeQueue(struct DynArrayQueue *Q) {
	int size = Q->capacity;
	Q->capacity = Q->capacity * 2;
	Q->array = realloc(Q->array, Q->capacity);
	printf("resized queue\n");
	if (!Q->array) {
		printf("Memory Error\n");
		return;
	}
	if (Q->front > Q->rear) {
		for (int i = 0; i < Q->front; i++) {
			Q->array[i + size] = Q->array[i];
		}
	}
	Q->rear = Q->rear + size;

};

void EnQueue(struct DynArrayQueue *Q, int data) {
	if (IsFullQueue(Q)) {
		ResizeQueue(Q);
	}
	Q->rear = (Q->rear + 1) % Q->capacity;
	Q->array[Q->rear] = data;

	if (Q->front == -1) {
		Q->front = Q->rear;
	}
};

int DeQueue(struct DynArrayQueue *Q) {
	int data = 0; // or element that does not exist in Queue
	if (IsEmptyQueue(Q)) {
		printf("Queue is empty\n");
		return 0;
	} else {
		data = Q->array[Q->front];
		if (Q->front == Q->rear) {
			Q->front = Q->rear = -1;
		} else {
			Q->front = (Q->front + 1) % Q->capacity;
		}
	}

	return data;
};

void DeleteQueue(struct DynArrayQueue *Q) {
	if (Q) {
		if (Q->array) {
			free(Q->array);
		}
		free(Q);
	}
};

int main(int argc, char const* argv[])
{
	struct DynArrayQueue *Q	= CreateDynQueue();
	printf("ISEmptyQueue %d\n", IsEmptyQueue(Q));
	EnQueue(Q, 1);
	printf("ISFullQueue %d\n", IsFullQueue(Q));
	EnQueue(Q, 2);
	printf("Queue Size Should be 1: %d\n", QueueSize(Q));
	EnQueue(Q, 3);
	printf("Queue Size %d\n", QueueSize(Q));
	DeQueue(Q);
	printf("Queue Size after DeQueue %d\n", QueueSize(Q));

	return 0;
}

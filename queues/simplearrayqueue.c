#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ArrayQueue {
	int front, rear;
	int capacity;
	int *array;
};

struct ArrayQueue *Queue(int size) {
	struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
	if (!Q) {
		return NULL;
	}
	Q->capacity = size;
	Q->front = Q->rear = -1;
	Q->array = malloc(Q->capacity * sizeof(int));
	if (!Q->array) {
		return NULL;
	}
	return Q;
};

int IsEmptyQueue(struct ArrayQueue *Q) {
	return (Q->front == -1);
};

int IsFullQueue(struct ArrayQueue *Q) {
	return ((Q->rear + 1) % Q->capacity == Q->front);
};

int QueueSize(struct ArrayQueue *Q) {
	return ((Q->capacity - Q->front + Q->rear + 1) % Q->capacity);
};

void EnQueue(struct ArrayQueue *Q, int data) {
	if (IsFullQueue(Q)) {
		printf("Queue Overflow\n");
	} else {
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = data;
		if (Q->front == -1) {
			Q->front = Q->rear;
		}
	}
};

int DeQueue(struct ArrayQueue *Q) {
	int data = 0; // or element that does not exist in queue
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

void DeleteQueue(struct ArrayQueue *Q) {
	if (Q) {
		if (Q->array) {
			free(Q->array);
		}
		free(Q);
	}
};

int main(int argc, char const* argv[])
{
	struct ArrayQueue *Q = Queue(5);
	EnQueue(Q, 1);	
	EnQueue(Q, 2);	

	int s1, s2, d;
	s1 = QueueSize(Q);
	printf("Size %d\n", s1);

	d = DeQueue(Q);
	printf("DeQueue data %d\n", d);
	s2 = QueueSize(Q);
	printf("Size %d\n", s2);

	return 0;
}

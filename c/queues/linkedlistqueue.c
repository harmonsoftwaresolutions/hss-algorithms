#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode {
	int data;
	struct ListNode *next;
};

struct Queue {
	struct ListNode *front;
	struct ListNode *rear;
};

struct Queue *CreateQueue() {
	struct Queue *Q;
	struct ListNode *temp;
	Q = malloc(sizeof(struct Queue));
	if (!Q) {
		return NULL;
	}
	temp = malloc(sizeof(struct ListNode));
	Q->front = Q->rear = NULL;
	return Q;
};

int IsEmptyQueue(struct Queue *Q) {
	return (Q->front == NULL);
};

void EnQueue(struct Queue *Q, int data) {
	struct ListNode *newNode;
	newNode = malloc(sizeof(struct ListNode));
	if (!newNode) {
		printf("Memory Error\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	if (Q->rear) {
		Q->rear->next = newNode;
	}
	Q->rear = newNode;

	if (Q->front == NULL) {
		Q->front = Q->rear;
	}
};

int DeQueue(struct Queue *Q) {
	int data = 0;
	struct ListNode *temp;
	if (IsEmptyQueue(Q)) {
		printf("Queue is empty\n");
		return 0;
	} else {
		temp = Q->front;
		data = Q->front->data;
		Q->front = Q->front->next;
		free(temp);
	}

	return data;
};

void DeleteQueue(struct Queue *Q) {
	struct Queue *temp;
	while (Q) {
		temp = Q;
		Q->front = Q->front->next;
		free(temp);
	}
	free(Q);
};

int main(int argc, char const* argv[])
{
	struct Queue *Q = CreateQueue();
	EnQueue(Q, 1);
	EnQueue(Q, 2);

	int d;
	d = DeQueue(Q);
	printf("DQ first %d\n", d);
	d = DeQueue(Q);
	printf("DQ second %d\n", d);

	return 0;
}

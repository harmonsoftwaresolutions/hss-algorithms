#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int data) {
	struct Node *t = malloc(sizeof(struct Node));
	assert(t);
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
};

struct List {
	struct Node *node;
	struct List *next;
};

struct List *newList(struct Node *t) {
	assert(t);
	struct List *l = malloc(sizeof(struct List));
	assert(l);
	l->node = t;
	l->next = NULL;
	return l;
};

struct Queue {
	struct List *front;
	struct List *rear;
};

struct Queue *newQueue() {
	struct Queue *q = malloc(sizeof(struct Queue));
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	return q;
};

int IsEmpty(struct Queue *q) {
	return !q->front;
};

void EnQueue(struct Queue *q, struct Node *node) {
	assert(q);
	assert(node);
	// create a new list
	struct List *list = newList(node);
	// attach new list to Queue
	if (!q->front) {
		q->front = list;
	} else {
		q->rear = list;
	}
};

struct Node *DeQueue(struct Queue *q) {
	assert(IsEmpty(q) == 0);
	// store old list pointer
	struct List *res = q->front;
	q->front = q->rear;
	if (q->rear) {
		q->rear = q->rear->next;	
	} else {
		q->rear = NULL;
	}
	return res->node;
};

void PrintTree(struct Node *root) {
	printf("\t\troot %d %p\n", root->data, root);
	printf("\tr l %d %p\t\t", root->left->data, root->left);
	printf("r r %d %p\t\t\n", root->right->data, root->right);
	printf("r l l %d %p\t", root->left->left->data, root->left->left);
	printf("r l r %d %p\t\n", root->left->right->data, root->left->right);

	return;
};

void PrintQueue(struct Queue *Q) {
	int cnt = 0;
	struct List *temp = Q->front;
	while (temp) {
		printf("cnt %d, Q fr %p, d %d ", cnt, temp, temp->node->data);
		if (Q->rear) {
			printf("Q rr %p, d %d\n", Q->rear, Q->rear->node->data);
		} else {
			printf("rr null\n");
		}
		printf("nxt %p\n", temp->next);
		temp = temp->next;
		cnt++;
		printf("cnt %d\n", cnt);
	}
	free(temp);
	temp = NULL;
};

int main(int argc, char *argv[])
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	struct Queue *q = newQueue();
	EnQueue(q, root);
	PrintQueue(q); // BUG: acting like a stack not a queue

	EnQueue(q, root->left);
	PrintQueue(q);
	/* printf("1EQ fr %p, rr %p, node %p, data %d\n", q->front, q->rear, q->front->node, q->front->node->data); */

	/* EnQueue(q, root->right); */
	/* PrintQueue(q); */

	/* EnQueue(q, root->left->left); */
	/* PrintQueue(q); */
	/* EnQueue(q, root->left->right); */
	/* PrintQueue(q); */

	/* DeQueue(q); */
	/* printf("1DEQ fr %p, rr %p, node %p, data %d\n", q->front, q->rear, q->front->node, q->front->node->data); */
	/* DeQueue(q); */
	

	/* printf("\t\t *** BINARY TREE ***\n"); */
	/* PrintTree(root); */

	/* printf("*** Recursive Traverse (1 2 3 4 5)\n"); */
	/* PrintLevelOrder(root); */
	/* printf("\n"); */

	return 0;
}

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
	// attach new list item as last (rear next) of the Queue
	if (q->rear) q->rear->next = list;
	// important - update rear so it represents "last" item
	q->rear = list;
	/* this ties it all together, make front equal the first rear
	this means the front->next ties in with the whole queue list of rear
	so you can follow front->next recursively all the way
	to the last rear in a large queue */
	if (!q->front)
		q->front = q->rear;
};

struct Node *DeQueue(struct Queue *q) {
	assert(IsEmpty(q) == 0);
	// store old list pointer
	struct List *temp = q->front;
	struct Node *node = temp->node;
	q->front = q->front->next;	
	free(temp);
	return node;
};

void PrintTree(struct Node *root) {
	printf("\t\troot %d %p\n", root->data, root);
	printf("\tr l %d %p\t\t", root->left->data, root->left);
	printf("r r %d %p\t\t\n", root->right->data, root->right);
	printf("r l l %d %p\t", root->left->left->data, root->left->left);
	printf("r l r %d %p\t\n", root->left->right->data, root->left->right);

	return;
};

void PrintQueue(struct Queue *Q, char name[]) {
	int cnt = 0;
	struct List *temp = Q->front;
	if (Q->front)
		printf("%s, FR cnt %d, Q fr %p, d %d ", name, cnt, temp, temp->node->data);
	if (Q->rear) {
		printf("RR %p, d %d\n", Q->rear, Q->rear->node->data);
	} else {
		printf("rr null\n");
	}
	while (temp) {
		printf("\tcnt %d, nxt %p\n", cnt, temp->next);
		temp = temp->next;
		cnt++;
	}
	free(temp);
	temp = NULL;
};

void PrintLevelOrder(struct Node *root) {
	struct Node *temp = root;
	struct Queue *q = newQueue();
	while (temp) {
		printf("temp %p, %d \n", temp, temp->data);

		// for each node, add left and right to force traversal of both sides of node
		if (temp->left)
			EnQueue(q, temp->left);
		if (temp->right)
			EnQueue(q, temp->right);

		if (IsEmpty(q)) {
			break;
		} else {
			temp = DeQueue(q);
		}
	}
};

int main(int argc, char *argv[])
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	/* struct Queue *q = newQueue(); */
	/* EnQueue(q, root); */
	/* PrintQueue(q, "EnQueue"); // BUG: acting like a stack not a queue */
	/* EnQueue(q, root->left); */
	/* PrintQueue(q, "EnQueue"); // BUG: acting like a stack not a queue */
	/* EnQueue(q, root->right); */
	/* PrintQueue(q, "EnQueue"); // BUG: acting like a stack not a queue */
	/* EnQueue(q, root->left->left); */
	/* PrintQueue(q, "EnQueue"); // BUG: acting like a stack not a queue */
	/* EnQueue(q, root->left->right); */
	/* PrintQueue(q, "EnQueue"); // BUG: acting like a stack not a queue */

	/* DeQueue(q); */
	/* PrintQueue(q, "DeQueue"); // BUG: acting like a stack not a queue */
	/* DeQueue(q); */
	/* PrintQueue(q, "DeQueue"); // BUG: acting like a stack not a queue */
	/* DeQueue(q); */
	/* PrintQueue(q, "DeQueue"); // BUG: acting like a stack not a queue */

	printf("\t\t *** BINARY TREE ***\n");
	PrintTree(root);

	printf("*** Recursive Traverse (1 2 3 4 5)\n");
	PrintLevelOrder(root);
	printf("\n");

	return 0;
}

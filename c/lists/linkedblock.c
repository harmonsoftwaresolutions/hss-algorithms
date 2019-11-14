#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <strings.h>

int blockSize; // max # of nodes in block

struct ListNode {
	struct ListNode *next;
	int value;
};

struct LinkedBlock {
	struct LinkedBlock *next;
	struct ListNode *head;
	int nodeCount;
};

struct LinkedBlock *blockHead;

struct LinkedBlock *newLinkedBlock() {
	struct LinkedBlock *block = malloc(sizeof(struct LinkedBlock));
	block->next = NULL;
	block->head = NULL;
	block->nodeCount = 0;
	return block;
};

struct ListNode *newListNode(int value) {
	struct ListNode *node = malloc(sizeof(struct ListNode));
	node->next = NULL;
	node->value = value;
	return node;
};

void vsearchElement(int k, struct LinkedBlock **fLinkedBlock, struct ListNode **fListNode) {
	// find the block
	int j = (k + blockSize - 1) / blockSize; //k-th node is in the j-th block
	struct LinkedBlock *p = blockHead;
	while (--j) {
		p = p->next;
	}
	*fLinkedBlock = p;

	// find the node
	struct ListNode *q = p->head;
	k = k % blockSize;
	if (k == 0) {
		k = blockSize;
	}
	k = p->nodeCount + 1 - k;
	
	while (k--) {
		q = q->next;
	}
	*fListNode = q;
};

void shift(struct LinkedBlock *A) {
	struct LinkedBlock *B;
	struct ListNode *temp;
	while (A->nodeCount > blockSize) { // if this block still have to shift
		if (A->next == NULL) { // reach the end -- a little different
			A->next = newLinkedBlock();
			B = A->next;
			temp = A->head->next;
			A->head->next = A->head->next->next;
			B->head = temp;
			temp->next = temp;
			A->nodeCount--;
			B->nodeCount++;
		} else {
			B = A->next;
			temp = A->head->next;
			A->head->next = A->head->next->next;
			temp->next = B->head->next;
			B->head->next = temp;
			B->head = temp;
			A->nodeCount--;
			B->nodeCount++;
		}
		A = B;
	}
};

void addElement(int k, int x) {
	struct ListNode *p, *q;
	struct LinkedBlock *r;

	if (!blockHead) { // initial, first nod and block
		blockHead = newLinkedBlock();
		blockHead->head = newListNode(x);
		blockHead->head->next = blockHead->head;
		blockHead->nodeCount++;
	} else {
		if (k == 0) { // special case for k = 0
			p = blockHead->head;
			q = p->next;
			p->next = newListNode(x);
			p->next->next = q;
			blockHead->head = p->next;
			blockHead->nodeCount++;
			shift(blockHead);
		} else {
			vsearchElement(k, &r, &p);
			q = p;
			while (q->next != p) {
				q = q->next;
			}
			q->next = newListNode(x);
			q->next->next = p;
			r->nodeCount++;
			shift(r);
		}
	}
};

int searchElement(int k) {
	struct ListNode *p;
	struct LinkedBlock *q;
	vsearchElement(k, &q, &p);
	return p->value;
};

int testUnrolledLinkedList() {
	/* int tt = clock(); */
	int m, i, k, x;
	char cmd[10];
	printf("A number: ");
	scanf("%d", &m);
	blockSize = (int)(sqrt(m - 0.001)) + 1;

	for (i = 0; i < m; i++) {
		printf("Command: ");
		scanf("%s", cmd);
		if (strcmp(cmd, "add") == 0) {
			printf("Add two elements: ");
			scanf("%d %d", &k, &x);
			addElement(k, x);
		} else if (strcmp(cmd, "search") == 0) {
			printf("Search: ");
			scanf("%d", &k);
			printf("%d\n", searchElement(k));
		} else {
			printf("i %d, m %d\n", i, m);
			fprintf(stderr, "Wrong input\n");
			break;
		}
	};
	return 0;
};

int main(int argc, char const* argv[])
{
	testUnrolledLinkedList();	

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <signal.h>

// Binary tree node
struct tNode {
	int data;
	struct tNode *left;
	struct tNode *right;
};

// Linked List implementation of a Stack
struct sNode {
	struct tNode *t;
	struct sNode *next;
};

struct tNode *newtNode(int data) {
	struct tNode *t = malloc(sizeof(struct tNode));
	if (!t) {
		return NULL;
	}
	t->data = data;
	t->left = NULL;
	t->right = NULL;

	return t;
};

struct sNode *newsNode() {
	/* struct sNode *s = malloc(sizeof(struct sNode)); */
	/* if (!s) { */
		/* return NULL; */
	/* } */
	/* s-> */
	/* s->t = NULL; */
	/* s->next = NULL; */

	/* return s; */
	return NULL;
};

int IsEmptyStack(struct sNode *top_ref) {
	printf("top_ref %p\n", top_ref);
	/* raise(SIGINT); */
	return (top_ref == NULL);
};

void Push(struct sNode **top, struct tNode *t) {
	struct sNode *sNode = malloc(sizeof(struct sNode));
	if (!sNode) {
		return;
	}
	sNode->t = t;
	// link old list item
	sNode->next = *top;
	// move head to point to new sNode
	*top = sNode;	
	printf("Push stack %p, stack next %p, top %p\n", sNode, sNode->next, top);
};

struct tNode *Pop(struct sNode **top_ref) {
	struct tNode *res;
	struct sNode *top;
	if (IsEmptyStack(*top_ref)) {
		return NULL;
	} else {
		// assign values from top
		top = *top_ref;
		res = top->t;
		*top_ref = top->next;
	}
	return res;
};

void DeleteStack(struct sNode *top_ref) {
	struct sNode *top;
	while (top_ref) {
		top = top_ref;
		top->next = top_ref->next;
		free(top);
	}
	free(top_ref);
};

void Preorder(struct tNode *root) {
	if (root) {
		printf("data %d\t", root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
};

// 1 2 4 5 3
void PreorderNonRecursive(struct tNode *root, struct sNode *s) {
	struct tNode *current = root;
	/* if (!s) { */
		/* return; */
	/* } */
	int cnt = 0;
	while (cnt < 3) {
		while (current) {
			printf("data %d\t", current->data);
			Push(&s, current);
			current = current->left;
		}
		if (IsEmptyStack(s)) {
			break;
		}
		current = Pop(&s);

		current = root->right;
		cnt++;
	}
	/* DeleteStack(s); */
};

int main(int argc, char const* argv[])
{
	struct tNode *root = newtNode(1);
	if (!root) {
		return 1;
	}
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	struct sNode *s = newsNode();
	/* if (!s) { */
		/* return 1; */
	/* } */
	/* printf("Preorder\n"); */
	/* Preorder(root); */
	printf("Is Empty? %d\n", IsEmptyStack(s));
	/* Push(&s, root); */
	/* printf("After Push Is Empty? %d\n", IsEmptyStack(s)); */
	PreorderNonRecursive(root, s);
	printf("Post Pre Is Empty? %d\n", IsEmptyStack(s));

	return 0;
}

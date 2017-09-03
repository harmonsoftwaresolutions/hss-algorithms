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

struct sNode *newsNode(struct tNode *t) {
	struct sNode *s = malloc(sizeof(struct sNode));
	if (!s) {
		return NULL;
	}
	s->t = t;
	s->next = NULL;
	return s;
};

int IsEmptyStack(struct sNode *top) {
	return !top;
};

void Push(struct sNode **top, struct tNode *t) {
	struct sNode *sNode = newsNode(t);
	if (!sNode) {
		return;
	}
	sNode->t = t;
	// link old list item
	sNode->next = *top;
	// move head to point to new sNode
	*top = sNode;	
};

struct tNode *Pop(struct sNode **top) {
	struct tNode *res;
	if (IsEmptyStack(*top)) {
		return NULL;
	}
	
	struct sNode *temp = *top;
	*top = temp->next;
	res = temp->t;
	free(temp);
	temp = NULL;
	return res;
};

void DeleteStack(struct sNode **list) {
	struct sNode *top = *list;
	while (top->next) {
		struct tNode *tnode = top->t;
		struct sNode *temp = top->next;
		top->t = top->next->t;
		top->next = top->next->next;
		free(tnode);
		tnode = NULL;
		free(temp);
		temp = NULL;
	}
	free(top);
	top = NULL;
	*list = NULL;
};

// 1 2 4 5 3
void Preorder(struct tNode *root) {
	if (root) {
		printf("node %d\t", root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
};

// 1 2 4 5 3
void PreorderNonRecursive(struct tNode *root, struct sNode **top) {
	struct tNode *current = root;
	struct sNode *s = *top;
	while (1) {
		while (current) {
			printf("node %d node pntr %p, top stack %p\n", current->data, current, s);
			Push(&s, current);
			current = current->left;
		}
		if (IsEmptyStack(s)) {
			break;
		}
		current = Pop(&s);

		current = current->right;
	}
};

void PrintTree(struct tNode *root) {
	printf("\t\troot %d %p\n", root->data, root);
	printf("\tr l %d %p\t\t", root->left->data, root->left);
	printf("r r %d %p\t\t\n", root->right->data, root->right);
	printf("r l l %d %p\t", root->left->left->data, root->left->left);
	printf("r l r %d %p\t\n", root->left->right->data, root->left->right);
};

int main(int argc, char const* argv[])
{
	// build up binary tree
	struct tNode *root = newtNode(1);
	if (!root) {
		return 1;
	}
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	printf("\t\t *** BINARY TREE ***\n");
	PrintTree(root);

	struct sNode *s = NULL;
	printf("*** Recursive Traverse\n");
	Preorder(root);
	printf("\n");

	printf("\nIs Empty? %d\n", IsEmptyStack(s));

	printf("*** Traverse without recursion\n");
	PreorderNonRecursive(root, &s);

	printf("\nStill Empty Stack? %d\n", IsEmptyStack(s));
	return 0;
}

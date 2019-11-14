#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Binary tree node
struct tNode {
	int data;
	struct tNode *left;
	struct tNode *right;
};

struct tNode *newtNode(int data) {
	struct tNode *t = malloc(sizeof(struct tNode));
	assert(t);
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
};

// Linked List implementation of a Stack
struct sNode {
	struct tNode *tnode;
	struct sNode *next;
};

struct sNode *newsNode(struct tNode *t) {
	assert(t);
	struct sNode *s = malloc(sizeof(struct sNode));
	assert(s);
	s->tnode = t;
	s->next = NULL;
	return s;
};

int IsEmpty(struct sNode *s) {
	return !s;
};

void Push(struct sNode **top, struct tNode *t) {
	struct sNode *s = newsNode(t);
	s->tnode = t;
	// link old list item
	s->next = *top;
	// move head to point to new sNode
	*top = s;	
};

struct tNode *Pop(struct sNode **top) {
	assert(IsEmpty(*top) == 0);
	struct sNode *temp = *top;
	struct tNode *res = temp->tnode;
	*top = temp->next;
	free(temp);
	temp = NULL;
	return res;
};

void DeleteStack(struct sNode **list) {
	struct sNode *top = *list;
	while (top->next) {
		struct tNode *tnode = top->tnode;
		struct sNode *temp = top->next;
		top->tnode = top->next->tnode;
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
		printf("%d ", root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
};

// 1 2 4 5 3
void PreorderNonRecursive(struct tNode *root, struct sNode **list) {
	struct tNode *node = root;
	struct sNode *top = *list;
	while (1) {
		while (node) {
			printf("%d ", node->data);
			Push(&top, node);
			node = node->left;
		}
		if (IsEmpty(top)) {
			break;
		}
		node = Pop(&top);
		node = node->right;
	}
	free(top);
	top = NULL;
	*list = NULL;
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
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	struct sNode *s = NULL;
	assert(IsEmpty(s) == 1);
	Push(&s, root);
	assert(IsEmpty(s) == 0);
	Pop(&s);
	assert(IsEmpty(s) == 1);
	Push(&s, root);
	DeleteStack(&s);
	assert(IsEmpty(s) == 1);
	assert(!s);

	printf("\t\t *** BINARY TREE ***\n");
	PrintTree(root);

	printf("*** Recursive Traverse (1 2 4 5 3)\n");
	Preorder(root);
	printf("\n");

	printf("*** Traverse without recursion (1 2 4 5 3)\n");
	PreorderNonRecursive(root, &s);
	printf("\n");

	return 0;
}

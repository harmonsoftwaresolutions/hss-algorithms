#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct tNode {
	int data;
	struct tNode *left;
	struct tNode *right;
};

struct sNode {
	struct tNode *tnode;
	struct sNode *next;
};

struct tNode *newtNode(int data) {
	struct tNode *t = malloc(sizeof(struct tNode));
	assert(t != NULL);
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
};

struct sNode *newsNode(struct tNode *t) {
	assert(t);
	struct sNode *s = malloc(sizeof(struct sNode));
	s->tnode = t;
	s->next = NULL;
	return s;
}

int IsEmpty(struct sNode *s) {
	return !s;
};

struct tNode *Peek(struct sNode *s) {
	assert(s);
	struct tNode *res = s->tnode;
	return res;
};

void Push(struct sNode **top, struct tNode *t) {
	assert(t);
	struct sNode *s = newsNode(t);
	s->next = *top;
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
		top->tnode = temp->tnode;
		top->next = temp->next;
		free(tnode);
		free(temp);
		tnode = NULL;
		temp = NULL;
	}
	free(top);
	top = NULL;
	*list = NULL;
};

// 4 2 5 1 3
void Inorder(struct tNode *root) {
	if (root) {
		Inorder(root->left);
		printf("%d ", root->data);
		Inorder(root->right);
	}
};

// 4 2 5 1 3
void InorderNonRecursive(struct tNode *root, struct sNode **top) {
	struct tNode *node = root;
	struct sNode *s = *top;
	while (1) {
		while (node) {
			Push(&s, node);
			node = node->left;
		}
		if (IsEmpty(s)) {
			break;
		}
		node = Pop(&s);
		printf("%d ", node->data);
		node = node->right;
	}
};

void PrintTree(struct tNode *root) {
	printf("\t\troot %d %p\n", root->data, root);
	printf("\tr l %d %p\t\t", root->left->data, root->left);
	printf("r r %d %p\t\t\n", root->right->data, root->right);
	printf("r l l %d %p\t", root->left->left->data, root->left->left);
	printf("r l r %d %p\t\n", root->left->right->data, root->left->right);

	return;
};

int main(int argc, char *argv[])
{
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

	printf("*** Recursive Traverse (4 2 5 1 3)\n");
	Inorder(root);
	printf("\n");

	printf("*** Traverse without recursion (4 2 5 1 3)\n");
	InorderNonRecursive(root, &s);
	printf("\n");

	return 0;
};

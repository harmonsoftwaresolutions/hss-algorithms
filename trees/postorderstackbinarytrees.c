#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

struct sNode {
	struct tNode *tnode;
	struct sNode *next;
};

struct sNode *newsNode(struct tNode *t) {
	struct sNode *s = malloc(sizeof(struct sNode));
	assert(s);
	s->tnode = t;
	s->next = NULL;
	return s;
};

int IsEmpty(struct sNode *s) {
	return !s;
};

struct tNode *Peek(struct sNode *s) {
	assert(s);
	struct tNode *res = s->tnode;

	return res;
};

void Push(struct sNode **top, struct tNode *t) {
	struct sNode *s = newsNode(t);
	s->tnode = t;
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
		struct tNode *t = top->tnode;
		struct sNode *temp = top->next;
		top->tnode = temp->tnode;
		top->next = temp->next;	
		free(t);
		free(temp);
		t = NULL;
		temp = NULL;
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

	return;
};

// Left, Right, Root
// 4 5 2 3 1
void Postorder(struct tNode *root) {
	if (root) {
		Postorder(root->left);
		Postorder(root->right);
		printf("%d ", root->data);
	}

	return;
};

// Left, Right, Root
// 4 5 2 3 1
void PostorderNonRecursive(struct tNode *root, struct sNode **list) {
	struct tNode *node = root;
	struct sNode *top = *list;
	while (1) {
		while (node) {
			if (node->right) {
				Push(&top, node->right);
			}
			Push(&top, node);
			node = node->left;
		}
		node = Pop(&top);
		if (IsEmpty(top)) {
			printf("%d ", node->data);
			break;
		}

		if (node->right && Peek(top) == node->right) {
			Pop(&top);
			Push(&top, node);
			node = node->right;
		} else {
			printf("%d ", node->data);
			node = NULL;
		}
	}
	free(top);
	top = NULL;
	*list = NULL;
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

	printf("*** Recursive Traverse (4 5 2 3 1)\n");
	Postorder(root);
	printf("\n");

	printf("*** Traverse without recursion (4 5 2 3 1)\n");
	PostorderNonRecursive(root, &s);
	printf("\n");

	return 0;
}

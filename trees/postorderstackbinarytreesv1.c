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

struct Stack {
	struct tNode *tnode;
	struct Stack *next;
};

struct Stack *newStack(struct tNode *t) {
	assert(t);
	struct Stack *s = malloc(sizeof(struct Stack));
	assert(s);
	s->tnode = t;
	s->next = NULL;
	return s;
};

int IsEmpty(struct Stack *s) {
	return !s;
};

struct tNode *Peek(struct Stack *s) {
	assert(s);
	struct tNode *res = s->tnode;

	return res;
};

void Push(struct Stack **top, struct tNode *t) {
	struct Stack *s = newStack(t);
	s->tnode = t;
	s->next = *top;
	*top = s;
};

struct tNode *Pop(struct Stack **top) {
	assert(IsEmpty(*top) == 0);
	struct Stack *temp = *top;
	struct tNode *res = temp->tnode;
	*top = temp->next;
	free(temp);
	temp = NULL;
	return res;
};

void DeleteStack(struct Stack **list) {
	struct Stack *top = *list;
	while (top->next) {
		struct tNode *t = top->tnode;
		struct Stack *temp = top->next;
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
void PostorderNonRecursive(struct tNode *root, struct Stack **list, struct Stack **list2) {
	struct tNode *node = root;
	struct Stack *s1 = *list;
	struct Stack *s2 = *list2;
	// push root to stack
	Push(&s1, node);
	while (!IsEmpty(s1)) {
		node = Pop(&s1);
		Push(&s2, node);

		if (node->left) {
			Push(&s1, node->left);
		}
		if (node->right) {
			Push(&s1, node->right);
		}
	}

	// print stack
	while (!IsEmpty(s2)) {
		node = Pop(&s2);
		printf("%d ", node->data);
	}
	free(node);
	node = NULL;
	free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
	*list = NULL;
};

int main(int argc, char *argv[])
{
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	struct Stack *s = NULL;
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
	struct Stack *s1 = NULL;
	struct Stack *s2 = NULL;
	PostorderNonRecursive(root, &s1, &s2);
	printf("\n");

	return 0;
}

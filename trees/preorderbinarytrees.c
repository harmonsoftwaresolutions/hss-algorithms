#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 5

struct Stack {
	struct Stack *next;
	struct BinaryTreeNode *node;
};

struct BinaryTreeNode {
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;

};

struct Stack *CreateStack() {
	return NULL;
};

int IsEmptyStack(struct Stack *top) {
	return (top == NULL);
};

void Push(struct Stack *top) {
	struct Stack *temp = malloc(sizeof(struct Stack));
	if (!temp) {
		printf("Push error\n");
		return;
	}
	printf("temp %p\n", temp);
	temp->next = NULL;
	temp->node = NULL;
	printf("temp %p, next %p, node %p\n", temp, temp->next, temp->node);
	struct BinaryTreeNode *node = malloc(sizeof(struct BinaryTreeNode));
	if (!node) {
		printf("Push node error\n");
		return;
	}
	node->left = NULL;
	node->right = NULL;
	node->data = 0;
	printf("node %p, left %p, right %p, data %d\n", node, node->left, node->right, node->data);
	top->next = NULL;
	/* printf("node %p, top %p, temp %p\n", node, top, temp); */
	/* if (top) { */
		/* top = temp; */
	/* } else { */
		/* node = top->node; */
	/* } */
	/* temp->node = node; */
	/* printf("temp %p, top %p\n", temp, top); */
	/* top = temp; */
};

struct BinaryTreeNode *Pop(struct Stack **top) {
	// not creating new stack item, so no malloc
	struct Stack *temp;
	if (IsEmptyStack(*top)) {
		return NULL;
	}
	// assign values from top
	temp = *top;
	*top = temp->next;

	return temp->node;
};

void DeleteStack(struct Stack *top) {
	struct Stack *temp;
	while (top) {
		temp = top;
		temp->next = top->next;
		free(temp);
	}
	free(top);
};

void PreOrder(struct BinaryTreeNode *root) {
	if (root) {
		printf("data %d\n", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
};

void PreOrderNonRecursive(struct BinaryTreeNode *root) {
	struct Stack *S = CreateStack();
	while (1) {
		while (root) {
			// process current node
			printf("data %d\n", root->data);
			Push(S);
			// If left tree exists, add to stack
			root = root->left;
		}
		if (IsEmptyStack(S)) {
			break;
		}
		root = Pop(&S);
		// indicates completion of left subtree and current node, now go to right subtree
		root = root->right;
	}
	DeleteStack(S);
};

int main(int argc, char const* argv[])
{
	struct Stack *top = CreateStack();	
	// create 7 node binary tree
	struct BinaryTreeNode *root = malloc(sizeof(struct BinaryTreeNode));
	if (!root) {
		printf("Memory error\n");
	}
	printf("IsEmptyStack %d\n", IsEmptyStack(top));
	Push(top);
	/* printf("next %p\n", top); */

	return 0;
}

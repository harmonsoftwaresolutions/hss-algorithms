#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int data) {
	struct Node *node = malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
};

struct Node *insert(struct Node *node, int data) {
	printf("data %d\n", data);
	if (!node) return newNode(data);

	if (data < node->data)
		node->left = insert(node->left, data);
	else if(data > node->data)
		node->right = insert(node->right, data);

	return node;
};

struct Node *createFromArray(int *arr, int ln) {
	// create first
	struct Node *node = newNode(arr[0]);
	for (int i = 1; i < ln; i++)
		node = insert(node, arr[i]);

	return node;
};

void PrintTree(struct Node *root) {
	printf("\t\t\t%d\n", root->data);
	printf("\t%d", root->left->data);
	printf("\t\t\t\t%d\n", root->right->data);
	printf("%d", root->left->left->data);
	printf("\t\t%d", root->left->right->data);
	printf("\t\t%d", root->right->left->data);
	printf("\t\t%d\n", root->right->right->data);

	return;
};

int main(int argc, char *argv[]) {
	int arr[7] = { 50, 30, 20, 40, 70, 60, 80 };
	int ln = sizeof(arr) / sizeof(arr[0]);
	struct Node *root = createFromArray(arr, ln);

	printf("\t\t *** BINARY TREE ***\n");
	PrintTree(root);
	printf("\n");

	return 0;
};

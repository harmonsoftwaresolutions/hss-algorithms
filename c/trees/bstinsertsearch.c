#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node *newNode(int data) {
	struct Node *node = malloc(sizeof(struct Node));
	assert(node);
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
};

struct Node *insert(struct Node *node, int data) {
	// necessary since recursion could send null node
	if (!node) return newNode(data);
	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);

	// return unchanged pointer
	return node;
};

struct Node *search(struct Node *root, int data) {
	if (!root || root->data == data)
		return root;

	if (root->data < data)
		return search(root->right, data);

	// key is smaller so search left
	return search(root->left, data);
};

void PrintTree(struct Node *root) {
	printf("\t\t\t%d\n", root->data);
	printf("\t%d", root->left->data);
	printf("\t\t\t\t%d\n", root->right->data);
	printf("%d", root->left->left->data);
	printf("\t\t%d\n", root->left->right->data);

	return;
};

int main(int argc, char *argv[]) {
	struct Node *root = newNode(50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	printf("\t\t *** BINARY TREE ***\n");
	PrintTree(root);
	printf("\n");

	printf("\t\t Search\n");
	int s = 40;
	struct Node *node = search(root, s);
	if (node->data < 1) {
		printf("Error on node data %d", node->data);
		return 0;
	}
	printf("Found S %d root pnt %p data %d\n", s, node, node->data);

	return 0;
};

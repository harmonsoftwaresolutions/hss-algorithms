#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int data) {
	struct Node *t = malloc(sizeof(struct Node));
	assert(t);
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
};

int height(struct Node *node) {
	if (!node) {
		return 0;
	} else {
		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight) {
			return (lheight + 1);
		} else {
			return (rheight + 1);
		}
	}
};

void PrintGivenLevel(struct Node *root, int level) {
	if (!root)
		return;

	if (level == 1) {
		printf("%d ", root->data);
	} else if (level > 1) {
		PrintGivenLevel(root->left, level-1);
		PrintGivenLevel(root->right, level-1);
	}
};

// 1 2 3 4 5
void PrintLevelOrder(struct Node *root) {
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		PrintGivenLevel(root, i);
};

void PrintTree(struct Node *root) {
	printf("\t\troot %d %p\n", root->data, root);
	printf("\tr l %d %p\t\t", root->left->data, root->left);
	printf("r r %d %p\t\t\n", root->right->data, root->right);
	printf("r l l %d %p\t", root->left->left->data, root->left->left);
	printf("r l r %d %p\t\n", root->left->right->data, root->left->right);

	return;
};

int main(int argc, char *argv[])
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("\t\t *** BINARY TREE ***\n");
	PrintTree(root);

	printf("*** Recursive Traverse (1 2 3 4 5)\n");
	PrintLevelOrder(root);
	printf("\n");

	return 0;
}

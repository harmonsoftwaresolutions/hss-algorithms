#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *CreateNode(int val) {
	struct Node *node = malloc(sizeof(struct Node));
	if (!node) {
		return NULL;
	}
	node->data = val;
	node->left = NULL;
	node->right = NULL;

	return node;
};

// Root Left Right
// 1 2 4 5 3
void PrintPreorder(struct Node *node) {
	if (!node) {
		return;
	}
	printf("%d\t", node->data);

	PrintPreorder(node->left);

	PrintPreorder(node->right);
};

// Left Root Right
// 4 2 5 1 3
void PrintInorder(struct Node *root) {
	if (!root) {
		return;
	}

	PrintInorder(root->left);

	printf("%d\t", root->data);

	PrintInorder(root->right);
};

// Right Root Left
// 4 5 2 3 1
void PrintPostorder(struct Node *root) {
	if (!root) {
		return;
	}

	PrintPostorder(root->left);

	PrintPostorder(root->right);

	printf("%d\t", root->data);
};

int main(int argc, char *argv[])
{
	struct Node *root = CreateNode(1);
	if (!root) {
		return 1;
	}

	root->left = CreateNode(2);
	root->right = CreateNode(3);

	root->left->left = CreateNode(4);
	root->left->right = CreateNode(5);

	printf("\nPreorder: \n");
	PrintPreorder(root);

	printf("\nInorder: \n");
	PrintInorder(root);

	printf("\nPostorder: \n");
	PrintPostorder(root);

	return 0;
}

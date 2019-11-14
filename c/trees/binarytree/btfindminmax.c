#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

struct node {
	int data;
	struct node *left, *right;
};

struct node *newNode(int data) {
	struct node *n = malloc(sizeof(struct node));
	assert(n);
	n->data = data;
	n->left = n->right = NULL;
	
	return n;
};

int findMin(struct node *root) {
	int root_val = INT_MAX;
	int left = INT_MAX;
	int right = INT_MAX;
	int min = INT_MAX;

	if (root) {
		root_val = root->data;
		left = findMin(root->left);
		right = findMin(root->right);

		if (left < right)
			min = left;
		else min = right;

		if (root_val < min)
			min = root_val;
	}

	return min;
};

int findMax(struct node *root) {
	int root_val = INT_MIN;
	int left = INT_MIN;
	int right = INT_MIN;
	int max = INT_MIN;

	if (root) {
		root_val = root->data;
		left = findMax(root->left);
		right = findMax(root->right);

		if (left > right)
			max = left;
		else max = right;

		if (root_val > max)
			max = root_val;
	}

	return max;
};

int main() {
	struct node *root = newNode(2);
	root->left = newNode(7);
	root->right = newNode(5);
	root->left->right = newNode(6);
	root->left->right->left = newNode(1);
	root->left->right->right = newNode(11);
	root->right->right = newNode(9);
	root->right->right->left = newNode(4);

	int mx = findMax(root);
	printf("Max %d\n", mx);

	int mn = findMin(root);
	printf("Min %d\n", mn);
};

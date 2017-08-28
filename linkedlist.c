#include <stdlib.h>
#include <stdio.h>
/* #include <criterion/criterion.h> */
/* #include <criterion/logging.h> */

struct ListNode {
	int data;
	struct ListNode *next;
};

int ListLength(struct ListNode *head) {
	struct ListNode *current = head;
	int count = 0;

	while (current != NULL) {
		printf("List Length %d\n", current->data);
		count++;
		current = current->next;
	}
	return count;
}

void InsertLinkedList(struct ListNode **head, int data, int position) {
	printf("Insert \n");
	int k = 1;
	struct ListNode *p, *q, *newNode;
	newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (!newNode) {
		printf("Memory Error\n");
		return;
	}

	newNode->data = data;
	p = *head;
	// Insert at Beginning
	if (position == 1) {
		newNode->next = p;
		*head = newNode;
	}
	else {
		// Traverse List until position where to insert
		while ((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}
		q->next = newNode;
		newNode->next = p;
	}
}

int main(int argc, char const* argv[]) {
	// local variable for function
	struct ListNode *head = NULL;
	head = malloc(sizeof(struct ListNode));
	if (head == NULL) {
		return 1;
	}

	head->data = 1;
	head->next = malloc(sizeof(struct ListNode));
	if (head->next == NULL) {
		return 1;
	}
	head->next->data = 2;
	head->next->next = malloc(sizeof(struct ListNode));

	head->next->next->data = 3;
	head->next->next->next = NULL;

	ListLength(head);
	InsertLinkedList(&head, 5, 1);
	ListLength(head);

	return 0;
}

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

	if (current == NULL) {
		printf("Empty \n");
	}

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

void DeleteNodeFromLinkedList(struct ListNode **head, int position) {
	int k = 1;
	struct ListNode *p, *q;
	if (*head == NULL) {
		printf("List Empty");
		return;
	}

	p = *head;
	/* from the beginning */
	if (position == 1) {
		*head = (*head)->next;
		free(p);
		return;
	} else {
		// Traverse list until position from which we want to delete
		while ((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}
		if (p == NULL) {
			printf("Position does not exist");
		} else {
			q->next = p->next;
			free(p);
		}
	}

}

void DeleteLinkedList(struct ListNode **head) {
	struct ListNode *auxNode, *iterator;
	iterator = *head;
	while (iterator) {
		auxNode = iterator->next;
		free(iterator);
		iterator = auxNode;
	}
	*head = NULL;
};

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
	InsertLinkedList(&head, 4, 3);
	ListLength(head);
	DeleteNodeFromLinkedList(&head, 3);
	ListLength(head);
	DeleteLinkedList(&head);
	ListLength(head);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct CLLNode {
	int data;
	struct CLLNode *next;
};

int CircularListLength(struct CLLNode *head) {
	struct CLLNode *current = head;
	printf("current addr %p, head addr %p\n", current, head);
	int count = 0;
	if (head == NULL) {
		return 0;
	}

	printf("next %p\n", current->next);
	do {
		current = current->next;
		count++;
	} while (current != head);
	printf("Count %d\n", count);
	return count;
}

void PrintCircularListData(struct CLLNode *head) {
	struct CLLNode *current = head;
	if (head == NULL) {
		return;
	}

	do {
		printf("data %d\n", current->data);
		current = current->next;
	} while (current != head); // NULL would cause infinite loop
}

void InsertAtBeginInCLL(struct CLLNode **head, int data) {
	struct CLLNode *current = *head;
	struct CLLNode *newNode = malloc(sizeof(struct CLLNode));
	if (!newNode) {
		printf("Memory Error \n");
		return;
	}
	newNode->data = data;

	while (current->next != *head) {
		current = current->next;
	}
	newNode->next = newNode;
	if (*head == NULL) {
		*head = newNode;
	} else {
		newNode->next = *head;
		current->next = newNode;
		*head = newNode;
	}

	return;
}

void InsertAtEndInCLL(struct CLLNode **head, int data) {
	struct CLLNode *current = *head;
	struct CLLNode *newNode = malloc(sizeof(struct CLLNode));
	if (!newNode) {
		printf("Memory Error \n");
		return;
	}

	newNode->data = data;
	while (current->next != *head) {
		current = current->next;
	}

	newNode->next = newNode;

	if (*head == NULL) {
		*head = newNode;
	} else {
		newNode->next = *head;
		current->next = newNode;
	}
}

void DeleteLastNodeFromCLL(struct CLLNode **head) {
	struct CLLNode *temp = *head, *current = *head;
	if (*head == NULL) {
		printf("List Empty \n");
		return;
	}
	while (current->next != *head) {
		temp = current;
		current = current->next;
	}
	temp->next = current->next;
	free(current);

	return;
}

void DeleteFrontNodeFromCLL(struct CLLNode **head) {
	struct CLLNode *temp = *head;
	struct CLLNode *current = *head;
	if (*head == NULL) {
		printf("List Empty\n");
		return;
	}

	while (current->next != *head) {
		current = current->next;
	}

	current->next = (*head)->next;
	*head = (*head)->next;
	free(temp);

	return;
}

int main(int argc, char const* argv[])
{
	// Keep Track Of Head since circular list
	struct CLLNode *head = NULL;
	head = malloc(sizeof(struct CLLNode));
	printf("head addr %p\n", head);
	if (head == NULL) {
		return 1;
	}

	head->data = 1;
	head->next = head;

	CircularListLength(head);

	// Item 2
	InsertAtEndInCLL(&head, 2);
	InsertAtBeginInCLL(&head, 3);

	DeleteFrontNodeFromCLL(&head);
	DeleteLastNodeFromCLL(&head);
	PrintCircularListData(head);

	return 0;
}

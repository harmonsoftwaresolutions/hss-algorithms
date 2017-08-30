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
	PrintCircularListData(head);

	return 0;
}

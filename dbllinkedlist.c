#include <stdio.h>
#include <stdlib.h>

struct DLLNode {
	int data;
	struct DLLNode *next;
	struct DLLNode *prev;
};

// use the pointer of the argument struct
int ListLength(struct DLLNode *head) {
	int count = 0;	
	struct DLLNode *current = head;

	if (current == NULL) {
		printf("empty \n");
	}

	// assign current to next pointer until end NULL
	while (current != NULL) {
		printf("Item %p, Data %d, next %p, prev %p\n", current, current->data, current->next, current->prev);
		count++;
		current = current->next;
	}

	return count;
}

void DLLInsert(struct DLLNode **head, int data, int position) {
	// counter, two pointers, error check
	int k = 1;
	struct DLLNode *temp, *newNode;
	newNode = malloc(sizeof(struct DLLNode));
	if (!newNode) {
		printf("Memory error \n");
		return;
	}

	newNode->data = data;
	if (position == 1) {
		// insert ahead of head, no move necessary
		printf("Insert ahead");
		newNode->next = *head;
		newNode->prev = NULL;

		// if not the first item, set next item prev pointer
		if (*head)
			(*head)->prev = newNode;

		*head = newNode;
		return;
	}
	// use temp pointer to copy, iterate, and find item
	temp = *head;
	while ((k < position - 1) && temp->next != NULL) {
		// take next pointer and copy for next iteration
		temp = temp->next;
		k++;
	}

	// makes sense because next ref is null
	// can supress this its basically logging
	printf("temp next %p\n", temp->next);
	if (k != position) {
		printf("Desired position does not exist");
	}

	// insert new item, copy next item pointer from temp
	newNode->next = temp->next;
	// set previous pointer to temp item, newNode is going after it
	newNode->prev = temp;
	// if not last item
	if (temp->next) {
		// i have no idea what is happening
		temp->next->prev = newNode;
	}
	// set current (temp) item next pointer to our new inserted node
	temp->next = newNode;
	return;
}

int main(int argc, char const* argv[])
{
	// create a node set to NULL, alloc memory, error check
	struct DLLNode *head = NULL;
	head = malloc(sizeof(struct DLLNode));
	if (head == NULL) {
		return 1;
	}

	// ITEM 1
	// assign values and don't forget the pointers!
	head->data = 1;
	head->next = NULL;
	head->prev = NULL;
	head->next = malloc(sizeof(struct DLLNode));
	if (head->next == NULL) {
		printf("error on next\n");
		return 1;
	}
	head->next->next = NULL;
	/* head->next->next = NULL; */

	// ITEM 2
	struct DLLNode *aux = NULL;
	aux = malloc(sizeof(struct DLLNode));
	if (aux == NULL) {
		return 1;
	}
	aux->data = 2;
	aux->next = NULL;
	aux->prev = head;
	// remember to update first item
	head->next = aux;

	ListLength(head);
	DLLInsert(&head, 3, 3);
	ListLength(head);

	return 0;
}

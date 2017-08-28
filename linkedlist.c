#include <stdlib.h>
#include <stdio.h>
/* #include <criterion/criterion.h> */
/* #include <criterion/logging.h> */

/* #define NULL 0 */

typedef struct ListNode {
	int data;
	struct ListNode *next;
} node_t;

int ListLength(struct ListNode *head)
{
	struct ListNode *current = head;
	int count = 0;

	while (current != NULL) {
		printf("%d\n", current->data);
		count++;
		current = current->next;
	}
	return count;
}

int main(int argc, char const* argv[])
{
	// local variable for function
	node_t * head = NULL;
	head = malloc(sizeof(node_t));
	if (head == NULL) {
		return 1;
	}

	head->data = 1;
	head->next = malloc(sizeof(node_t));
	if (head->next == NULL) {
		return 1;
	}
	head->next->data = 2;
	head->next->next = NULL;

	ListLength(head);
	return 0;
}

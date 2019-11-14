#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ListNode
struct Stack {
	int data;
	struct Stack *next;
};

struct Stack *newStack(int val) {
	struct Stack *s = malloc(sizeof(struct Stack));
	if (!s) {
		return NULL;
	}
	s->data = val;
	s->next = NULL;
	return s;
};

void Push(struct Stack **top, int data) {
	struct Stack *s = newStack(data);
	if (!s) {
		return;
	}
	s->next = *top;
	*top = s;
};

int IsEmptyStack(struct Stack *top) {
	if (!top) {
		printf("Empty top %p\n", top);
	} else {
		printf("Empty top %p, top->next %p\n", top, top->next);
	}
	// is NULL?
	return !top;
};

int Pop(struct Stack **top) {
	int data;
	if (IsEmptyStack(*top)) {
		return INT_MIN;
	}
	struct Stack *temp = *top;
	*top = (*top)->next;
	data = temp->data;
	free(temp);
	return data;
};

int Peek(struct Stack *top) {
	if (IsEmptyStack(top)) {
		return INT_MIN;
	}
	return top->data;
};

void DeleteStack(struct Stack **list) {
	// access pointer of the parameter from function call
	struct Stack *top = *list;
	/* printf("Before **list %p, *list %p, list next %p\n", (* list), list, (* list)->next); */
	while (top->next) {
		// temp store of struct to free mem later
		struct Stack *temp = top->next;
		/* printf("Pre del temp %p, top %p, top next %p, top next next %p\n", temp, top, top->next, top->next->next); */
		// move to next pointer
		top->next = top->next->next;
		/* printf("Post del temp %p, temp next %p, top %p, top next %p\n", temp, temp->next, top, top->next); */
		free(temp);
		// defensive set to null
		temp = NULL;
	}
	/* printf("After **list %p, *list %p, top %p, top next %p\n", (* list), list, top, top->next); */
	// free list
	free(top);
	top = NULL;
	// set list value to null
	*list = NULL;
	/* printf("Free delete **list %p, *list %p, top %p\n", (* list), list, top); */
};

int main(int argc, char const* argv[])
{
	struct Stack *S = NULL;
	Push(&S, 1);
	Push(&S, 2);
	Push(&S, 3);

	/* printf("2 Push Top %d\n", Peek(S)); */
	Pop(&S);
	/* printf("1 Pop Top %d\n", Peek(S)); */
	/* Pop(&S); */

	DeleteStack(&S);
	printf("Stack %p, &Stack %p\n", S, &S);
	printf("Empty? %d\n", IsEmptyStack(S));

	return 0;
}

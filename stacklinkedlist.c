#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ListNode
struct Stack {
	int data;
	struct Stack *next;
};

struct Stack *CreateStack() {
	return NULL;
};

void Push(struct Stack **top, int data) {
	struct Stack *temp;
	temp = malloc(sizeof(struct Stack));
	if (!temp) {
		return;
	}
	temp->data = data;
	temp->next = *top;
	*top = temp;
};

int IsEmptyStack(struct Stack *top) {
	printf("top %p, top->next %p\n", top, top->next);
	return (top == NULL);
};

int Pop(struct Stack **top) {
	int data;
	struct Stack *temp;
	if (IsEmptyStack(*top)) {
		return INT_MIN;
	}
	temp = *top;
	*top = temp->next;
	data = temp->data;
	free(temp);
	return data;
};

int Top(struct Stack *top) {
	if (IsEmptyStack(top)) {
		return INT_MIN;
	}
	return top->next->data;
};

void DeleteStack(struct Stack **top) {
	struct Stack *temp, *p;
	p = *top;
	while (p->next) {
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
	free(p);
};

int main(int argc, char const* argv[])
{
	struct Stack *S = CreateStack();
	Push(&S, 1);
	Push(&S, 2);
	int t, p, e;
	t = -1;
	p = -1;
	e = -1;

	t = Top(S);
	p = Pop(&S);

	DeleteStack(&S);
	e = IsEmptyStack(S);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 10
struct ArrayStack {
	int top;
	int capacity;
	int *array;
};

struct ArrayStack *CreateStack() {
	struct ArrayStack *S = malloc(sizeof(struct ArrayStack));
	if (!S) {
		return NULL;
	}
	S->capacity = MAXSIZE;
	S->top = -1;
	S->array = malloc(S->capacity * sizeof(int));
	if (!S->array) {
		return NULL;
	}
	return S;
};

int IsEmptyStack(struct ArrayStack *S) {
	return (S->top == -1);
};

int IsFullStack(struct ArrayStack *S) {
	return (S->top == S->capacity - 1);
};

void Push(struct ArrayStack *S, int data) {
	/* S->top == capacity -1 stack is full */
	if (IsFullStack(S)) {
		printf("Stack Overflow\n");
	} else {
		/*  increase top by 1 and store value */
		S->array[++S->top] = data;
	}
};

int Pop(struct ArrayStack *S) {
	/* S->top == -1 means empty stack */
	if (IsEmptyStack(S)) {
		printf("Stack is empty\n");
		return INT_MIN;
	} else {
		return (S->array[S->top--]);
	}
};

void DeleteStack(struct ArrayStack *S) {
	if (S) {
		if(S->array) {
			free(S->array);
		}
		free(S);
	}
};

int main(int argc, char const* argv[])
{
	struct ArrayStack *S = CreateStack();
	Push(S, 1);
	Push(S, 2);

	int e, t;
	t = S->top;
	e = IsEmptyStack(S);
	printf("t %d, e %d\n", t, e);

	return 0;
}

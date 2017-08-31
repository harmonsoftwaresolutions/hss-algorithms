#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 5

struct DynArrayStack {
	int top;
	int capacity;
	int *array;
};

struct DynArrayStack *CreateStack() {
	struct DynArrayStack *S = malloc(sizeof(struct DynArrayStack));
	if (!S) {
		return NULL;
	}
	S->top = -1;
	S->capacity = MAXSIZE;
	S->array = malloc(S->capacity * sizeof(int));
	if (!S->array) {
		return NULL;
	}
	
	return S;
};

int IsFullStack(struct DynArrayStack *S) {
	return (S->top == S->capacity - 1);
};

int IsEmptyStack(struct DynArrayStack *S) {
	return (S->top == -1);
};

void DoubleStack(struct DynArrayStack *S) {
	S->capacity *= 2;
	S->array = realloc(S->array, S->capacity * sizeof(int));
};

void Push(struct DynArrayStack *S, int x) {
	// no overflow
	if (IsFullStack(S)) {
		DoubleStack(S);
	}
	S->array[++S->top] = x;
};

int Top(struct DynArrayStack *S) {
	if (IsEmptyStack(S)) {
		return INT_MIN;
	}
	return S->array[S->top];
};

int Pop(struct DynArrayStack *S) {
	if (IsEmptyStack(S)) {
		return INT_MIN;
	}
	return S->array[S->top--];

};

void DeleteStack(struct DynArrayStack *S) {
	if (S) {
		if (S->array) {
			free(S->array);
		}
		free(S);
	}
};

int main(int argc, char const* argv[])
{
	struct DynArrayStack *S = CreateStack();
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	printf("S->capacity %d\n", S->capacity);

	// force realloc
	Push(S, 6);
	printf("S->capacity %d\n", S->capacity);
	int r;
	r = Pop(S);
	printf("r %d\n", r);

	return 0;
}

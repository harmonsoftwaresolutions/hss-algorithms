#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Heap {
	int *array;
	int count;
	int capacity;
	int heap_type;
} Heap;

int Parent(Heap *h, int i) {
	if (i <= 0)
		return INT_MIN;
	if (i >= h->count)
		return INT_MIN;
	int p = (i - 1) / 2;

	return p;
};

int Left(Heap *h, int i) {
	if (i <= 0)
		return INT_MIN;
	int l = (i * 2) + 1;
	if (l >= h->count)
		return INT_MIN;

	return l;
};

int Right(Heap *h, int i) {
	if (i <= 0)
		return INT_MIN;
	int r = (i * 2) + 2;
	if (r >= h->count)
		return INT_MIN;

	return r;
};

int GetMax(Heap *h) {
	if (!h)
		return INT_MIN;
	int max = h->array[0];

	return max;
};

int GetMin(Heap *h) {
	if (!h)
		return INT_MIN;
	int min = h->array[h->count - 1];

	return min;
};

// test
void PercolateDown(Heap *h, int i) {
	int l = Left(h, i);
	int r = Right(h, i);
	int max = INT_MIN;
	int temp = INT_MIN;

	if (l != INT_MIN && h->array[l] > h->array[i])
		max = l;
	else max = i;
	if (r != INT_MIN && h->array[r] > h->array[i])
		max = r;
	if (max != i) {
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
		PercolateDown(h, max);
	}

	return;
};

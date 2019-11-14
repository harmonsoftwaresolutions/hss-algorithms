#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

typedef struct Heap {
	int *array;
	int count;
	int capacity;
	int heap_type;
} Heap;

struct Heap *CreateHeap(int capacity, int heap_type) {
  struct Heap *h = malloc(sizeof(struct Heap));
  assert(h);
  h->heap_type = heap_type;
  h->count = 0;
  h->capacity = capacity;
  h->array = malloc(sizeof(int) * h->capacity);
  assert(h->array);

  return h;
};

// not used yet
int Parent(Heap *h, int i) {
	if (i <= 0)
		return INT_MIN;
	if (i >= h->count)
		return INT_MIN;
	int p = (i - 1) / 2;

	return p;
};

// not used yet
int Left(Heap *h, int i) {
	if (i <= 0)
		return INT_MIN;
	int l = (i * 2) + 1;
	if (l >= h->count)
		return INT_MIN;

	return l;
};

// not used yet
int Right(Heap *h, int i) {
	if (i <= 0)
		return INT_MIN;
	int r = (i * 2) + 2;
	if (r >= h->count)
		return INT_MIN;

	return r;
};

// not used yet
int GetMax(Heap *h) {
	if (!h)
		return INT_MIN;
	int max = h->array[0];

	return max;
};

// not used yet
int GetMin(Heap *h) {
	if (!h)
		return INT_MIN;
	int min = h->array[h->count - 1];

	return min;
};

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
    printf("PercolateDown i %d\n", i);
		PercolateDown(h, max);
	}

	return;
};

// not used yet
int DeleteMax(Heap *h) {
  int data;
  if (h->count == 0)
    return -1;
  data = h->array[0];
  h->array[0] = h->array[h->count -1];
  h->count--;
  PercolateDown(h, 0);

  return data;
};

void ResizeHeap(Heap *h) {
  printf("ResizeHeap current capacity %d\n", h->capacity);
  int *array_old = h->array;
  h->array = malloc(sizeof(int) * h->capacity * 2);
  assert(h->array);
  for (int i = 0; i < h->capacity; i++)
    h->array[i] = array_old[i];
  h->capacity *= 2;
  free(array_old);
};

// not used yet
void Insert(Heap *h, int data) {
  int i;
  if (h->count == h->capacity)
    ResizeHeap(h);
  h->count++;
  i = h->count - 1;
  while (i >= 0 && data > h->array[(i - 1) / 2]) {
    h->array[i] = h->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  h->array[i] = data;
};

// not used yet
void DestroyHeap(Heap *h) {
  assert(h);
  free(h->array);
  free(h);
  h = NULL;
};

void BuildHeap(Heap *h, int A[], int n) {
  assert(h);
  while (n > h->capacity)
    ResizeHeap(h);
  printf("Building Heap\n");
  for (int i = 0; i < n; i++)
    h->array[i] = A[i];
  h->count = n;
  for (int i = (n - 1) / 2; i >= 0; i--)
    PercolateDown(h, i);
};

void PrintHeap(Heap *h) {
  assert(h);
  assert(h->capacity);
  for (int i = 0; i < h->capacity; i++)
    printf(" %d ", h->array[i]);
};

void HeapSort(int A[], int n) {
  struct Heap *h = CreateHeap(n, 1);
  int i = 0;
  int temp = INT_MIN;
  BuildHeap(h, A, n);
  int old_size = h->count;
  for (i = n - 1; i > 0; i--) {
    // h->array[0] is the largest element
    temp = h->array[0];
    h->array[0] = h->array[h->count - 1];
    h->array[0] = temp;
    h->count--;
    PercolateDown(h, 0);
  };
  h->count = old_size;
  PrintHeap(h);
};

void PrintArray(int a[], int ln) {
  assert(a);
  assert(ln);
  printf("\nLength %d\n", ln);
  for (int i = 0; i < ln; i++)
    printf(" %d ", a[i]);
};

int main() {
  int arr[] = { 12, 11, 13, 5, 6, 7 };
  int ln = sizeof(arr) / sizeof(arr[0]);
  /* int ln = 5; */
  HeapSort(arr, ln);
  PrintArray(arr, ln);

  return 0;
};

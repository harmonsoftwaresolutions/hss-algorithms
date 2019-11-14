#include <stdio.h>

int recursiveBinarySearch(int arr[], int left, int right, int x)
{
	// look in right or left to start
	if (right >= left) {
		// get middle index for comparison
		int middle = left + (right - 1)/2;
		// check if element is present at middle itself
		if (arr[middle] == x) {
			return middle;
		}
		// check if smaller than mid value
		// means look in left sub array using middle as right
		if (arr[middle] > x) {
			return recursiveBinarySearch(arr, left, middle - 1, x);
		}
		// else look in right sub array using middle as left
		return recursiveBinarySearch(arr, middle + 1, right, x);
	}

	// return -1 if element not present
	return -1;
};

int binarySearch(int arr[], int left, int right, int x)
{
	while (left <= right) {
		// get middle index
		int middle = left + (right - 1)/2;

		// check if x is present at middle index
		if (arr[middle] == x) {
			return middle;
		}

		// if x is greater than middle value, ignore left sub array
		if (arr[middle] < x) {
			left = middle + 1;
		} else {
			// ignore right sub array
			right = middle - 1;
		}
	}

	return -1;
};

int main()
{
	int arr[] = {2,3,4,10,40};
	int n = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = n - 1;
	// search element
	int x = 10;

	int recurse = recursiveBinarySearch(arr, left, right, x);
	if (recurse == -1) {
		printf("Recurse: Element not found in array\n");
	} else {
		printf("Recurse: Element is present at index %d\n", recurse);
	}

	int iterative = binarySearch(arr, left, right, x);
	if (iterative == -1) {
		printf("Iterative: Element not found in array\n");
	} else {
		printf("Iterative: Element is present at index %d\n", iterative);
	}

	return 0;
};

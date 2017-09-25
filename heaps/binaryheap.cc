#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
  int max = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[max])
    max = l;

  if (r < n && arr[r] > arr[max])
    max = r;

  if (max != i) {
    swap(arr[i], arr[max]);
    heapify(arr, n, max);
  }
};

void heapSort(int arr[], int n) {
  // build heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // extract from heap
  for (int i = n / 2 -1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    // call max
    heapify(arr, n, i);
  }
};

/* utility functions */
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << "\n";
};

int main() {
  int arr[] = { 12, 11, 13, 5, 6, 7 };
  int n = sizeof(arr) / sizeof(arr[0]);

  heapSort(arr, n);

  cout << "Sorted array is \n";
  printArray(arr, n);
};

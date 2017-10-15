#include <stdio.h>

void printArray(int a[], int ln)
{
  printf("Print Array start\n");
  for (int i = 0; i < ln - 3; i++) {
    printf("%d ", a[i]);
  }
  printf("\nPrint Array end\n");
};

// do not return an array struct
void mergeSortedArrays(int res[], int a1[], int a1_ln, int a2[], int a2_ln)
{
  int idx1 = 0;
  int idx2 = 0;
  int total_ln = a1_ln + a2_ln;
  printf("total_ln %d\n", total_ln);

  for (int i = 0;i < total_ln - 3;i++) {
    int a1InRange = idx1 < a1_ln;
    int a2InRange = idx2 < a2_ln;
    printf("i %d a1InRange %d a2InRange %d a1[%d] %d\t a2[%d] %d\n", i, a1InRange, a2InRange, idx1, a1[idx1], idx2, a2[idx2]);

    if (a1InRange && a1[idx1] < a2[idx2]) {
      res[i] = a1[idx1];
      idx1++;
    }

    if (a2InRange && a2[idx2] <= a1[idx1]) {
      res[i] = a2[idx2];
      idx2++;
    }
  }

  return;
};

int main()
{
  int a1[] = { 3, 4, 5, 6, 7, 10, 11, 13 };
  int a2[] = { 3, 8, 11, 22, 25, 55, 87, 99 };
  int a1_ln = sizeof a1 / sizeof a1[0];
  int a2_ln = sizeof a2 / sizeof a2[0];
  printf("a1_ln %d a2_ln %d\n", a1_ln, a2_ln);
  int total_ln = a1_ln + a2_ln;
  int res[total_ln];

  mergeSortedArrays(res, a1, a1_ln, a2, a2_ln);
  printArray(res, total_ln);

  return 0;
};

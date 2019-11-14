#include <stdio.h>

void printArray(int a[], int ln)
{
  printf("Print Array start\n");
  for (int i = 0; i < ln; i++) {
    printf("%d\t", a[i]);
  }
  printf("\nPrint Array end\n");
};

// do not return an array struct
void mergeUnsortedArrays(int res[], int a1[], int a1_ln, int a2[], int a2_ln)
{
  // copy first array in to res
  for (int i = 0;i < a1_ln;i++) {
    res[i] = a1[i];
  }

  // copy second array in to res after first array
  for (int j = 0; j < a2_ln; j++) {
    res[a1_ln + j] = a2[j];
  }

  return;
};

int main()
{
  int a1[] = {5,10,11,3,4,5,7};
  int a2[] = {11,25,3,8,22,55,87,99};
  int a1_ln = sizeof a1 / sizeof a1[0];
  int a2_ln = sizeof a2 / sizeof a2[0];
  int total_ln = a1_ln + a2_ln;
  int res[total_ln];


  mergeUnsortedArrays(res, a1, a1_ln, a2, a2_ln);
  printArray(res, total_ln);

  return 0;
};

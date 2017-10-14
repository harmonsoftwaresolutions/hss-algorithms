#include <iostream>
#include <vector>

using namespace std;

void reversePrintArray(vector<int> arr, int n)
{
  for (int i = n - 1; i >= 0; i--)
    cout << arr[i] << " ";
};

int main()
{
  int n = 4;
  vector<int> arr(n);
  int myints[] = {1,4,3,2};
  for (int arr_i = 0; arr_i < n; arr_i++)
    // cout << myints[arr_i] << "\n";
    arr[arr_i] = myints[arr_i];

  reversePrintArray(arr, 4);

  return 0;
}

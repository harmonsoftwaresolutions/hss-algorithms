// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

vector <int> leftRotation(vector <int> a, int d) {
    // Complete this function
    cout << "d " << d << endl;
    int temp[d];
    int ln = a.size();
    cout << "ln " << ln << endl;
    printf("Copy elements from 0 to a[%d] - they will be overwrote\n", (d - 1));
    for (int i=0;i<d;i++) {
      printf("a[%d] %d\n", i, a[i]);
      temp[i] = a[i];
    }

    printf("Move items from a[%d] to a[%d] to start of array\n", d, (ln-1));
    int cursor = 0;
    for (int j=d;j<ln;j++) {
      a[cursor] = a[j];
      printf("cursor a[%d] %d\n", cursor,a[cursor]);
      cursor++;
    }

    printf("Copy temp array items from a[%d] to a[%d] of array\n", (ln-d), (ln-1));
    int cntr = 0;
    for (int k=ln - d;k<ln;k++) {
      printf("a[%d] %d, temp[%d] %d\n", k, a[k], cntr, temp[cntr]);
      a[k] = temp[cntr];
      cntr++;
    }
    return a;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector <int> result = leftRotation(a, d);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}


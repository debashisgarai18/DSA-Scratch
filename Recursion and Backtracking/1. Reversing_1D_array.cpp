#include <bits/stdc++.h>
using namespace std;

// by using one variable
// void f(int arr[], int i, int n){
//   if(i >= n/2)
//     return;
//   swap(arr[i], arr[n-i-1]);
//   f(arr, i + 1, n);
// }

// by using two pointers
void f(int arr[], int s, int e) {
  if (s >= e)
    return;
  swap(arr[s], arr[e]);
  f(arr, s + 1, e - 1);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  f(arr, 0, 4);
  for (int i = 0; i < 5; ++i)
    cout << arr[i] << " ";
}
// to get all the subsequences and check the value is equal to the sum or not
#include <bits/stdc++.h>
using namespace std;

// concept used: pick and non-pick technique
// to find all the subsequences in an array using recursion
// to find the sum matching the value of k
void f(int i, int arr[], vector<int> &vv, int n, int s, int k) {
  if (i == n) {
    if (s == k) {
      for (auto j : vv)
        cout << j << " ";
      cout << endl;
    }
    return;
  }
  // pick the val
  vv.push_back(arr[i]);
  s += arr[i];
  f(i + 1, arr, vv, n, s, k);

  // not pick the val
  vv.pop_back();
  s -= arr[i];
  f(i + 1, arr, vv, n, s, k);
}

int main() {
  int arr[] = {1, 2, 1};
  int n = 3;
  int sum = 2;
  vector<int> vv;
  f(0, arr, vv, n, 0, sum);
}
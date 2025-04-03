// to count the numbert of subsequences whose val is equal to the sum
#include <bits/stdc++.h>
using namespace std;

// to print the count of the subsequences whose sum is equal to k
int f(int i, int arr[], int n, int sum, int k) {
  if (i == n) {
    if (sum == k)
      return 1;
    else
      return 0;
  }

  // take the value
  sum += arr[i];
  int l = f(i + 1, arr, n, sum, k);

  // not take the value
  sum -= arr[i];
  int r = f(i + 1, arr, n, sum, k);

  return l + r;
}
int main() {
  int arr[] = {1, 2, 1};
  int k = 2;
  cout << "Count: " << f(0, arr, 3, 0, k);
}
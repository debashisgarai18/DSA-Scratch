#include <bits/stdc++.h>
using namespace std;

// to implement merge sort

void merge(vector<int> &vv, int low, int mid, int high) {
  vector<int> tmp;
  int l = low;
  int r = mid + 1;
  while (l <= mid && r <= high) {
    if (vv[l] < vv[r]) {
      tmp.push_back(vv[l]);
      l++;
    } else {
      tmp.push_back(vv[r]);
      r++;
    }
  }
  while (l <= mid) {
    tmp.push_back(vv[l]);
    l++;
  }
  while (r <= high) {
    tmp.push_back(vv[r]);
    r++;
  }
  for (int i = low; i <= high; i++) {
    vv[i] = tmp[i - low];
    // cout << vv[i] << " ";
  }
}
void mergeSort(vector<int> &vv, int low, int high) {
  // base case
  if (low >= high)
    return;

  int mid = (low + high) / 2;
  mergeSort(vv, low, mid);
  mergeSort(vv, mid + 1, high);
  merge(vv, low, mid, high);
}

int main() {
  vector<int> vv = {3, 2, 1, 3, 4, 7, 6};
  mergeSort(vv, 0, 6);
  for (auto i : vv)
    cout << i << " ";
}
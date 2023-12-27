#include <bits/stdc++.h>
using namespace std;

// to search the given element in the rotated array
// catch is: this array will contain duplicates
// approach: same as finding in the sorted sub part of the array
// but the catch is we have duplicate elements in this so we need to trim the search space

int f(vector<int> &arr, int k){
  int l = 0, h = arr.size() - 1;
  while (l <= h){
    int mid = l + (h - l) / 2;

    // to check if the val of the mid and the low and the high are equal or not
    // if so then trim the search space from both the ends
    // this is the edge case for the rotated array having duplicates 
    if(arr[l] == arr[mid] && arr[mid] == arr[h]){
      l = l + 1;
      h = h - 1;
      continue;
    }

    // if the mid matches the target value
    if(arr[mid] == k) return mid;
    // check which half is sorted
    // for left half
    if(arr[l] <= arr[mid]){
      if(arr[l] <= k && k <= arr[mid]) h = mid - 1;
      else l = mid + 1;
    }
    // for right half
    else{
      if(arr[mid] <= k && k <= arr[h]) l= mid + 1;
      else h = mid - 1;
    }
  }
  return -1;
}
int main() {
  vector<int> arr = {6, 7, 8, 9, 9, 1, 2, 3};
  int target = 9;
  cout << f(arr, target);
}
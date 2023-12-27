#include <bits/stdc++.h>
using namespace std;

// to find the element in the rotated sorted array
// approach: using simple bs
// find the sorted half in the array as the whole array will not be sorted
// check whether the number lies in the array or not

int search_ele(vector<int> &arr, int target){
  int l = 0, h = arr.size() - 1;

  while (l <= h){
    int mid = l + (h - l)/2;

    if(target == arr[mid]) return mid;

    // to check whether left sub array is sorted
    if(arr[l] <= arr[mid]){
      // if so then to check whether the target lies in the left sub array
      if(target >= arr[l] && target <= arr[mid])
        h = mid - 1;
      else
        l = mid + 1;
    }
    // to check whether the right sub array is sorted
    else{
      // if so then to check whether the target lies in the right sub array 
      if(arr[mid] <= target && target <= arr[h])
        l = mid + 1;
      else
        h = mid - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {7,8,9,3,4,5};
  int target = 1;

  cout << search_ele(arr, target);
}
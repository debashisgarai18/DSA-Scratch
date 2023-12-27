#include <bits/stdc++.h>
using namespace std;

// to find the minimun element in the rotated sorted array
// approach: using bs to find position of the minimum in the rotated array
// we need to find the sorted space and update the result val with the idx of the min in the sorted array

int fmin(vector<int> & arr){
  int l = 0, h = arr.size() - 1;
  int ans = INT_MAX;
  while(l <= h){
    int mid = l + (h - l) / 2;

    // edge case if the array is not rotated
    if(arr[l] <= arr[h]){
      ans = min(ans, arr[l]);
      return ans;
    }
    // find the sorted search space 
    // to check if the left search space is sorted or not
    // if sorted, then update the ans with the min of the ans and the first ele of the sorted array
    if(arr[l] <= arr[mid]){
      ans = min(ans, arr[l]);
      l = mid + 1;
    }
    // if not then the right sub array will be sorted so do the same in the right sub array
    else{
      ans = min(ans, arr[mid]);
      h = mid - 1;
    }
  }
  return ans;
}
int main() {
  vector<int> arr = {-1, 0, 2, 3, 4};
  cout << fmin(arr);
  return 0;
}
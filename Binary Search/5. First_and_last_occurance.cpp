// to find the first and the last occurence of the target in a given array.
#include <bits/stdc++.h>
using namespace std;

// to find the first occurance of a number
// approach -> can use lower bound concept
// and can use traditional bs
int foccur(vector<int> &arr, int target){
  int l = 0, h = arr.size() - 1;
  int fo = arr.size();

  while(l <= h){
    int mid = l + (h - l) / 2;

    if(arr[mid] >= target){
      fo = mid;
      h = mid - 1;
    }
    else l = mid + 1;
  }

  return fo;
}

// to find the first occurance of a number
// approach -> can use upper bound concept
// and can use traditional bs
int loccur(vector<int> &arr, int target){
  int l = 0, h = arr.size() - 1;
  int lo = arr.size();

  while(l <= h){
    int mid = l + (h - l) / 2;

    if(arr[mid] > target){
      lo = mid;
      h = mid - 1;
    }
    else l = mid + 1;
  }

  return lo;

}
int main() {
  vector<int> arr = {1, 2, 3, 3, 3, 3, 4, 5};
  int target = 7;

  // some checks for first occurance
  if(foccur(arr, target) == arr.size() || arr[foccur(arr, target)] != target){
    cout << -1 << " " << -1;
  }
  else{
    cout << foccur(arr, target) << " " << loccur(arr, target) - 1;
  }
}
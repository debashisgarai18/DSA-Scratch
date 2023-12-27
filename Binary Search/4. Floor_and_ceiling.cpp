// to find the floor and ceiling of a specific target in an array
#include <bits/stdc++.h>
using namespace std;

// to find the floor of the number
// largest number which is <= target
int flr(vector<int> &arr, int target){
  int l = 0, h = arr.size() - 1;
  int fs = arr.size();

  while (l <= h){
    int mid = l + (h - l ) / 2;

    if (arr[mid] <= target){
      fs = arr[mid];
      l = mid + 1;
    }
    else h = mid - 1;
  }
  return fs;
}

// to find the ceil of the number
// smallest number which is >= target
// concept used: lower bound in BS
int cl(vector<int> &arr, int target){
  int l = 0, h = arr.size() - 1;
  int cl = arr.size();

  while (l <= h){
    int mid = l + (h - l ) / 2;

    if (arr[mid] >= target){
      cl = arr[mid];
      h = mid - 1;
    }
    else l = mid + 1;
  }
  return cl;
}

int main() {
  vector<int> arr = {1,2,4,5,9}; 
  int target = 6;
  cout << flr(arr, target) << " " << cl(arr, target);
}
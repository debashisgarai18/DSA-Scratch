#include <bits/stdc++.h>
using namespace std;

// to find an element and place it in its proper position
// tc o(log n)
// can also do this using lower bound concept in bs

int sort_ins_pos(vector<int> &arr, int target){
  int l = 0, h = arr.size() - 1;
 // int ans = arr.size();

  while(l <= h){
    int mid = l + (h - l) / 2;

    if (arr[mid] == target) return mid;
    else if(target > arr[mid]) l = mid + 1;
    else h = mid - 1;
  }

  return l;
}
int main() {
  vector<int> arr = {1,2,3,3,4,7};
  cout << "pos: " << sort_ins_pos(arr, 5);

  return 0;
}
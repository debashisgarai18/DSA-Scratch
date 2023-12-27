// to find the upper bound and the lower bound of a given sorted array
#include <bits/stdc++.h>
using namespace std;

// implementing the lower bound
int lb(vector<int> &arr, int target){
  int l = 0, h = arr.size() - 1;
  int ans = arr.size();

  while(l <= h){
    int mid = l + (h - l)/2;

    if(arr[mid] >= target){
      ans = arr[mid];
      h = mid - 1;
    }
    else l = mid + 1;
  }
  return ans;
}

// implementing the upper bound
int ub(vector<int> &arr, int target){
    int l = 0, h = arr.size() - 1;
    int ans = arr.size();

    while(l <= h){
      int mid = l + (h - l)/2;

      if(arr[mid] > target){
        ans = arr[mid];
        h = mid - 1;
      }
      else l = mid + 1;
    }
    return ans;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 7, 7, 8, 9, 10};
  pair<int, int> p;
  p.first = lb(arr, 6);
  p.second = ub(arr, 6);

  cout << "UB:" << p.second << " LB:" << p.first << endl;
}
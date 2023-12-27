#include <bits/stdc++.h>
using namespace std;


// to count the number of total occurrences of the target number
// two approaches : by lower and upper bounf concept
// by naive bs on finding first and last occur

// will be using naive bs for finding first and last occur
// to find the first occur
int foccur(vector<int> &vv, int target){
  int l = 0, h =  vv.size() - 1;
  int fo = -1;

  while(l <= h){
    int mid = l + (h - l)/2;

    if(vv[mid] == target){
      fo = mid;
      h = mid - 1;
    }
    else l = mid + 1;
  }

  return fo;
}

// to find the last occur
int loccur(vector<int> &vv, int target){
  int l = 0, h =  vv.size() - 1;
  int lo = -1;

  while(l <= h){
    int mid = l + (h - l)/2;

    if(vv[mid] == target){
      lo = mid;
      l = mid + 1;
    }
    else h = mid - 1;
  }

  return lo;
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5};
    int target = 3;
    if(foccur(arr, target) == -1) cout << 0 << endl;
    else cout << loccur(arr, target) - foccur(arr, target) + 1;
}
// to find the row with max number of ones
// condition is each row should contain alteast 1 zero
#include <bits/stdc++.h>
using namespace std;

// function to find the lower bound
int lBound(vector<int>& vv, int n, int target){
  int l = 0, h = n - 1;
  while(l <= h){
    int mid = (l + h) >> 1;
    if(vv[mid] >= target) h = mid - 1;
    else l = mid + 1;
  }
  return l;
}
int funct(vector<vector<int>>& arr, int n, int m){
  // naive solution
  // just iterate over the row and count the sum 
  // the one which is greater return that
  // int mx = -1, idx = -1;
  // for(int i = 0; i < n; ++i){
  //   int cnt = 0;
  //   for(int j = 0; j < m; ++j){
  //     cnt += arr[i][j];
  //   }
  //   if(cnt > mx && cnt != n){
  //     mx = cnt;
  //     idx = i;
  //   }
  // }
  // return idx;

  // this will take the TC of O(n * m)
  // optimised approah : BS
  // apply BS on every row and find the lower bound of 1
  // return the row with max val of (m - lowerBound(1))
  int mx_cnt = 0, idx = -1;
  for(int i = 0; i < n; ++i){
    int cnt = m - lBound(arr[i], m, 1);
    if(cnt > mx_cnt && cnt != m){
      mx_cnt = cnt;
      idx = i;
    }
  }
  return idx;
  
}
int main() {
  vector<vector<int>>vv = {{0, 1, 1}, {1,1,1}, {0, 0, 1}};
  int m = vv[0].size();
  int n = vv.size();
  cout << "The row is: " << funct(vv, n, m);
}
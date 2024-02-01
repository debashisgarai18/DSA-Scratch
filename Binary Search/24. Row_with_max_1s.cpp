// to find the row with max number of ones
// condition is each row should contain alteast 1 zero
#include <bits/stdc++.h>
using namespace std;

int funct(vector<vector<int>>& arr, int n, int m){
  // naive solution
  // just iterate over the row and count the sum 
  // the one which is greater return that
  int mx = -1, idx = -1;
  for(int i = 0; i < n; ++i){
    int cnt = 0;
    for(int j = 0; j < m; ++j){
      cnt += arr[i][j];
    }
    if(cnt > mx && cnt != n){
      mx = cnt;
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
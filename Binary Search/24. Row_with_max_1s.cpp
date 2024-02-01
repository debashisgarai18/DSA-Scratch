// to find the row with max number of ones
#include <bits/stdc++.h>
using namespace std;

int funct(vector<vetcor<int>>& arr, int n, int m){
  // naive solution
  // just iterate over the row and count the sum 
  // the one which is greater return that
  int mx = -1, idx = -1;
  for(int i = 0; i < n; ++i){
    int cnt = 0;
    for(int j = 0; j < m; ++j){
      cnt += arr[i][j];
    }
    if(cnt > mx){
      mx = cnt;
      idx = i;
    }
  }
  return i;
}
int main() {
  
}
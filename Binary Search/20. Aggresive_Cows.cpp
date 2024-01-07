// to place k aggressive cows into n stalls such that the min distance between them is the maximum distance possible 

#include <bits/stdc++.h>
using namespace std;

// function to calculate that the stalls are possible or not
// so that the min distance is the max possible distance
int possStalls(vector<int>& stalls, int k, int minDis){
  int n = stalls.size();
  int cowCnt = 1, lastCow = stalls[0];
  for(int i = 0; i < n; ++i){
    // calculate that the current pos - the last pos is >= dis
    // if it is greater inc the cowcount nd dedicate the lastcow to the current pointer
    if(stalls[i] - lastCow >= minDis){
      cowCnt++;
      lastCow = stalls[i];
    }

    if(cowCnt >= k) return true;
  }
  return false;
}

int f(vector<int>& stalls, int k){
  // sorting the array to get the max and min easily
  sort(stalls.begin(), stalls.end());
  int n = stalls.size();
  // the search space should be from 1 to stalls(max - min)
  int l = 1, h = stalls[n - 1] - stalls[0];

  // naive based
  // just iterate over the search space nd check
  // if the specific distance is posible then return it else return the distance prior  that specific distance
  // int res = -1;
  // for(int i = l; i <= h; ++i){
  //   if(!possStalls(stalls, k, i))
  //     return i - 1;
  //   else{
  //     res = i;
  //     continue;
  //   }
  // }
  // return res;

  // it will give TLE, TC = O(n * (max - min))
  // optimised approach  ==> Binary Search
  while(l <= h){
    int mid = (l + h) >> 1;
    // now to check the mid vas the minDis, if it statisfies then we need to trim the left search space(as max needs to be found)
    if(possStalls(stalls, k, mid)) l = mid + 1;
    // else trim the right search space
    else h = mid - 1;
  }
  // as the left side (l value) was giving proper result
  // we need to return the h val to get the proper result
  return h;
}

int main() {
  vector<int> stalls = {0, 3, 4, 7, 10, 9};
  int k = 4;
  cout << "The min. distance reqd is: " << f(stalls, k);
}
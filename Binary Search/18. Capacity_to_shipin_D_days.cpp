// to find the least weight capaciy of the ship so that the weights can be parcelled within D days
#include <bits/stdc++.h>
using namespace std;

// function to calculate the total number of days to ship the weights so that the sum <= the total capacity
int tot_days(vector<int>& weights, int capacity){
  int days = 1, load = 0;
  for(int i = 0; i < weights.size(); ++i){
    // if on adding weight load is > capacity then increase the day count and start the load from the fresh weight
    if(load + weights[i] > capacity){
      days += 1;
      load = weights[i];
    }
    else{
      load += weights[i];
    }
  }
  return days;
}

// function to find the minimum capacity of the ship
int mincap(vector<int>& weights, int days){
  // the search space should be b/w the max element of the weights to teh sum(weights[i])
  int l = *max_element(weights.begin(), weights.end());
  int h = accumulate(weights.begin(), weights.end(), 0); // to find the tot sum of the vector

  // naive approach
  // just iterate and match the val, whichever will be <= days return it
  // for(int i = l; i <= h; ++i){
  //   if(tot_days(weights, i) <= days)
  //     return i;
  // }
  // return -1;
  // this eill give TLE as the TC is : O(n * (sum - max + 1));

  // optimised method ==> Binary Search
  while(l <= h){
    int mid = (l + h) >> 1;

    // if the val of the mid in funct gives <= days then the right half will also give as we have to find the min one, so eliminate the right half
    if(tot_days(weights, mid) <= days) h = mid - 1;
    // else eliminate the left half
    else l = mid + 1;
  } 
  return l;
}
int main() 
{
  vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
  int days = 5;
  cout << "The minimum capacity reqd is: " << mincap(weights, days);
  return 0;
}
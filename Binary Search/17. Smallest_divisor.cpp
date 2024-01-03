//  to find the smallest divisor which on dividing the elements will give values which after summing will lend a result <= given threshold
#include <bits/stdc++.h>
using namespace std;

// function to count the total sum of the quotients
int quo_sum(vector<int>& num, int d){
  int n = num.size(), total = 0;
  for(int i = 0; i < n; ++i){
    // to calculate the total sum of the quotients
    total += ceil((double)num[i]/(double)d);
  }
  return total;
}

// function to calculate the smallest divisor
int sd(vector<int>& nums, int threshold){
  // edge case
  // if threshold > size od array then ret -1;
  if(threshold < nums.size()) return -1;

  // the search space would be from 1 to max(nums);
  int l = 1, h = *max_element(nums.begin(), nums.end());
  // naive approach
  // // just iterate over the search space and check which is the smallest one and return it
  // for(int i = l; i <= h; ++i){
  //   if(quo_sum(nums, i) <= threshold)
  //     return i;
  // }

  // optimised approach ==> Binary search

  while(l <= h){
    int mid = (l + h) >> 1;

    // if mid gives total val <= threshold
    // the eliminate the right half
    if(quo_sum(nums, mid) <= threshold){
      h = mid - 1;
    }
    // else eliminate the right half;
    else l = mid + 1;
  }
  return l;
}
int main() {
  vector<int> nums = {1,2,5,9};
  int threshold = 6;
  cout << "The samllest divisor is: " << sd(nums, threshold);
}
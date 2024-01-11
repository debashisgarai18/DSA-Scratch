// split the array in to k subarrays such that the largest sum among the subarrays is minimum
#include <bits/stdc++.h>
using namespace std;

// function to count the no of subarrays such that sum(subarray) <= sum
int calc(vector<int> nums, int s){
  int k = 1, sum = 0;
  for(int i = 0; i < nums.size(); ++i){
    // now to check that if the sum + curr_element <= sum or not
    // if so, then we can add more to
    if(sum + nums[i] <= s){
      sum += nums[i];
    }
    // else need to increase the count of the subarry
    // and assign the sum to the curr_element
    else{
      k++;
      sum = nums[i];
    }
  }
  return k;
}

int larg_sum(vector<int> nums, int k){
  // the search space should be from the max(nums) to sum(nums)
  // coz it will not exceed this range
  int l = *max_element(nums.begin(), nums.end());
  int h = accumulate(nums.begin(), nums.end(), 0);

  // naive approach
  // as min(largest) sum is reqd, so we'll check from the first to the last in the search space
  // if func(idx) <= k, then return that idx
  // for(int i = l; i <= h; ++i){
  //   if(calc(nums, i) <= k) return i;
  // }
  // return - 1;

  // this approach will give TLE as TC : O(n * (sum - max + 1))

  // optimised approach ==> Binary Search
  while(l <= h){
    int mid = (l + h) >> 1;

    // just check that func(mid) <= k or not
    // if so then trim the right search space coz we need to find the min(largest) sum 
    if(calc(nums, mid) <= k) h = mid - 1;
    // else just trim the left search space
    else l = mid + 1;
  }
  return l;
}
int main() {
  vector<int> nums = {7,2,5,10,8};
  int k = 2;
  cout << "The min(largest) subarray sum is : " << larg_sum(nums, k);
  return 0;
}
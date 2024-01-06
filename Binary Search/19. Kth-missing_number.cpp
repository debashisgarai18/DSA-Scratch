// to find the k-th missing number from a given array

#include <bits/stdc++.h>
using namespace std;

// function to calculate the k-th missing number
int find_miss(vector<int>& nums, int k){
  // naive based approach
  for(int i = 0; i < nums.size(); ++i){
    if(nums[i] <= k) k = k + 1;
    else break;
  }
  return k;
  // it will give TLE as TC is: O(N)
  // optimised approach
  // we need to find closest two missing(indexes) to k
  // such that idx1 < k < idx2
  int l = 0, h = nums.size() - 1;
  while(l <= h){
    int mid = (l + h) >> 1;
     // now to find the missing number at each index
    int missing = nums[mid] - (mid + 1);

    // now to check that the missing val is < k or not 
    // if it is < k then trim the left search space
    if(missing < k) l = mid + 1;
    else h = mid - 1;
  }
  // l = h + 1
  // the missing(l) = 6 and missing(h) = 3 are the two indx that are closest such that h < k < l
  // find the missing(h) & the more needed to form k, thus more_needed = k - missing(h)
  // final val = arr[h] + more_needed
  // formula = arr[h] + (k - (arr[h] - (h + 1))
  //         = arr[h] + (k - arr[h] + h  + 1)
  //         = k + l (final result)

  return k + l;

  // TC : O(log n)
}

int main() {
  vector<int> nums = {2,3,4,7,11};
  int k = 5;
  cout << "The " << k << "th missing number is: " << find_miss(nums, k) << endl;
  return 0;
}
// in this problem we hae to find the possible combinations from the given array such that they sum upto the target
// catch is : we can pick one idx only once and then we cannot have repeated combinations and the combinations should be sorted.

// brute force : same thing as combination sum 1
// only in place of vector<vector<>>, we need to use set so that the entries are unique
// and we have to increment the idx, while taking the idx also
// TC : 2^n * k * logn => logn extra for SET ds

// TC in optimised approach: 2^n * k, no extra logn needed for set DS

#include <bits/stdc++.h>
using namespace std;

void func(int idx, int target, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res){
  // base case
  // we'll iterate till the target becomes 0
  // push the temp into the res
  if(target == 0){
    res.push_back(temp);
    return;
  }

  // optimised approach : subsequences method of recursions in arrays
  // each place can have n options, so we have to pick elements b/w them
  // loop thru the array from curr idx to n-1 and do some checks
  for(int i = idx; i < nums.size(); ++i){
    // check - if the curr nums > target, break. coz there is no point of checking as the target will become -ve
    if(nums[i] > target) break;
    // here we'll not pick the elements which are repeated, as they will give same array combination as they are sorted
    // for eg. if we are picking 0th idx, we'll not pick 1st nd 2nd
    if(i > idx && nums[i] == nums[i - 1]) continue;

    // else add the curr index to the temp array
    temp.push_back(nums[i]);
    func(idx + 1, target - nums[i], nums, temp, res);
    // just pop out the recently added elem as it should get carried while backtracking 
    temp.pop_back();
  }
}

int main() {
  vector<int> nums = {1,1,1,2,2};
  int target = 4; // res = [[1,1,2], [2,2]]

  vector<int> temp;
  vector<vector<int>> res;
  
  // we need to sort the giver vector as we need the results to be in the sorted order
  sort(nums.begin(), nums.end());

  func(0, target, nums, temp, res);
  
  for(int i = 0; i < res.size(); ++i){
    for(int j = 0; j < res[i].size(); ++j) cout << res[i][j] << " ";
    cout << endl;
  }

  return 0;
}
// TODO : Find the combinations from the given array, such that the combinations sum upto the given target
// catch : we can take one number from the array twice while making the combinations 
// example : arr : [2, 2, 3, 6, 7]
// res : [[2, 2, 3], [7]]

#include <bits/stdc++.h>
using namespace std;

// approach TBU : brute force
// using the pick and non pick method
// for each index there are two options to pick and not pick
// pick the element and add it in a resultant array and then reduce the picked elemnt from the target
// do this till the target becomes 0, and then go to other half
// while backtracking, do pop out the latest pushed element in the array

// in order to get the unique combinations we can use the the DS to store the values as Set
void solve(int idx, int target, vector<int> nums, vector<int>& temp, set<vector<int>>& res){
  // base case
  // this should be the case when the array is exhausted
  if(idx == nums.size()){
    // if the target becomes 0, then we should push the temp elements in the resultant array
    if(target == 0){
      res.insert(temp);
    }
    // everytime the control reaches here, we should return back
    return;
  }

  // if the target >= current nums
  // then have two options to pick and non pick the value
  if(nums[idx] <= target){
    // add the value to the temp array
    temp.push_back(nums[idx]);
    solve(idx, target - nums[idx], nums, temp, res);
    // popping back the lastly added value as it needs to be popped out while backtracking 
    temp.pop_back();
  }

  // this is the option to not pick the element in the temp array
  // in this case we should increment the idx value wihtout reducing the target
  solve(idx + 1, target, nums, temp, res);
}

int main() {
  vector<int> nums = {2,2,3,6,7};
  int target = 7;

  vector<int> temp;
  set<vector<int>> res;
  solve(0, target, nums, temp, res);

  vector<vector<int>> ans;
  // copying the values from the set to the resultant vector
  for(auto itr : res){
    vector<int> vec;
    for(int i = 0; i < itr.size(); ++i){
      vec.push_back(itr[i]);
    }
    ans.push_back(vec);
  }
  
  cout << "The combinations are:" << endl;
  for(int i = 0; i < ans.size(); ++i){
    for(int j = 0; j < ans[i].size(); ++j){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
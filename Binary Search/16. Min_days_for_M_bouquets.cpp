// to calculate the min days required to form the given no of bouquets with given number of adjacent flowers

#include <bits/stdc++.h>
using namespace std;

// function to calculate the bouquet count and check that whether it is >= the given number of bouquets
bool bou_check(vector<int>& bloom, int day, int m, int k){
  int n = bloom.size();
  int cnt = 0, tot_bouq = 0;
  for(int i = 0; i < n; ++i){
    // here we need to calculate the count
    // if specific day is >= bloom[i] then cnt++
    if(bloom[i] <= day) cnt++;
    // no we get the count, if it <= bloom[i]
    // then simple add the total bouquets and reset the counter
    else{
      tot_bouq += (cnt / k);
      cnt = 0;
    }
  }
  tot_bouq += (cnt / k);
  
  // to check if it matches the given m bouquets or not
  if(tot_bouq >= m) return true;
  else return false;
}

// function to apply the naive or binary search
int min_days(vector<int>& bloom, int m, int k){
  // here the lower lim = minele(bloom)
  // the higher lim = maxele(bloom)
  int l = *min_element(bloom.begin(), bloom.end());
  int h = *max_element(bloom.begin(), bloom.end());

  // naive approach => to simply iterate over the given search spce and find the day, TC = O(n*(l + h - 1));
  // for(int i = l; i <= h; ++i){
  //   if(bou_check(bloom, i, m, k)) return i;
  // }
  // return -1;

  // for optimised apprach we'll use binary search
  int ans = -1;
  while(l <= h){
    int mid = (l + h) >> 1;

    // to check whether the mid val is giving true or false
    // if it is giving true then the right half will also give true 
    // so eliminate the right half
    if(bou_check(bloom, mid, m, k)){
      ans = mid;
      h = mid - 1;
    }
    // else eliminate the left half
    else l = mid + 1;
  }
  return ans;
}

int main() {
  vector<int> bloom = {1,10,3,10,2};
  int k = 1, m = 3;
  cout << "Min no of days: " << min_days(bloom, m, k);
  return 0;
}
// we need to find the min value of k such that koko can eat all bananas in <= h hours
#include <bits/stdc++.h>
using namespace std;

// function to calculate the total time he can give to consume a specific number of bananas
long long int totf(vector<int>& piles, int mid){
  int n = piles.size();
  long long int total_time = 0;
  // to find the total time we need to calc the ceil of (piles[i] / mid)
  for(int i = 0; i < n; ++i){
    total_time += ceil((double)piles[i] / (double)mid);
  }
  return total_time;
}

// the bs will be simple
// we have to apply bs from 1 to max of pilee[i]
int bsf(vector<int>& piles, int k){
  int l = 1, h = *max_element(piles.begin(), piles.end());
  while(l <= h){
    int mid = (l + h) >> 1;

    // now to check that
    // if the mid is <= h then we need to eliminate the right half
    if(totf(piles, mid) <= k)
      h = mid - 1;
    // else we need to skip the left half and proced further
    else 
      l = mid + 1;
  }
  // here we can see that the prob of right half being the ans was greater
  // so after bs it inverses thus returning the "l" pointer
  return l;
}
int main() {
  vector<int> piles = {30,11,23,4,20};
  int h = 6;
  cout << "The min time is : " << bsf(piles, h);
  return 0;
}
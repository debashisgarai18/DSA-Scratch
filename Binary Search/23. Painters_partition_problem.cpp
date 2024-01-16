// to find the min time to get all the n boards painted
// 1 unit area takes 1 unit of time to paint
#include <bits/stdc++.h>
using namespace std;

// function to check that the the given number of k painters 
// will be able to paint all the boards in given amount of time
int fnc(vector<int>& boards, int minT, int k){
  int sum = 0, wrks = 1;
  for(int i = 0; i < boards.size(); ++i){
    // here to check if the curr board + the sum exceeds the min time or not
    // if so just inc the workers count and assign sum to the curr elem
    if(sum + boards[i] > minT){
      wrks++;
      sum = boards[i];
    }
    // else just increase the sum
    else sum += boards[i];
  }
  if(wrks <= k) return true;
  else return false;
}

// function for getting the minimum time
int getMinTime(vector<int>& boards, int k){
  // here, the search space will be from the max of the array to the sum of all the elems of the array
  int l = *max_element(boards.begin(), boards.end());
  int h = accumulate(boards.begin(), boards.end(), 0);

  // naive based :- 
  // just iterate over the search space nd check the value which is min and return it;
  // for(int i = l; i <= h; ++i){
  //   if(fnc(boards, i, k)) return i;
  // }
  // return -1;

  // This will give TLE as TC : O(n * (sum - max +1))

  // optimised approach: Binary Search
  while(l <= h){
    int mid = (l + h) >> 1;
    // just check that the curr mid is giving true or not
    // if true then ignore the right half as it will be also true;
    if(fnc(boards, mid, k)) h = mid - 1;
    // else ignore the left half
    else l = mid + 1;
  }
  // return the l pointer as the h was giving true earlier
  return l;

  // TC : n * log(sum - max + 1)
}
int main() {
  vector<int> boards = {2, 1, 5, 6, 2, 3};
  int k = 2;
  cout << "The min time required is : " << getMinTime(boards, k) << endl;
  return 0;
}
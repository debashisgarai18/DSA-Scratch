// allocate books to students such that each student gets book and the max number of pages allocated is min
// constraints ==> should be assigned - in contiguous order and each should get >= 1 book

#include <bits/stdc++.h>
using namespace std;

// function to find the number of pages allocated to a student and check that the pages are allocated to all students 
int func(vector<int> arr, int pages){
  int sum_p = 0, stu = 1;
  for(int i = 0; i < arr.size(); ++i){
    if(arr[i] + sum_p <= pages) sum_p += arr[i];
    else{
      stu++;
      sum_p = arr[i];
    }
  }
  return stu;
}

// to find the min pages assigned
int min_pages(vector<int> arr, int s){
  // the search space is => max(arr) to sum(arr)
  int l = *max_element(arr.begin(), arr.end());
  int h = accumulate(arr.begin(), arr.end(), 0);

  // naive based
  // just iterate and the idx which return the value return that idx;
  // for(int i = l; i <= h; ++i){
  //   if(func(arr, i) == s) return i;
  // }
  // return -1;
  // this will give TLE as the TC : O(n * (sum - max + 1))

  // optimised approach ==> using Binary Search
  while(l <= h){
    int mid = (l + h) >> 1;
    // if the mid val <= s, then the right side of the array is needed to be eliminated as the other vales will also be <= s except mid;
    if(func(arr, mid) <= s) h = mid - 1;
    else l = mid + 1;
  }
  return l;

  // for the BS, the TC is : O(n * log(sum - max + 1))
}
int main() {
  vector<int> arr = {12, 34, 67, 90};
  int s = 2;
  cout << "The max pages assigned i.e. min is:" << min_pages(arr, s) << endl;

  return 0;
}
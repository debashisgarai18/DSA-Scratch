// to find the peak element in an array

#include <bits/stdc++.h>
using namespace std;

int peak_elem(vector<int> vv, int n){
  // to check if the array contains single element or not
  if(n == 1) return vv[0];

  // check for the first and the last element
  if(vv[0] > vv[1]) return vv[0];
  if(vv[n - 1] > vv[n -2]) return vv[n - 1];

  // run the binary search from 1st elem to n - 2 elem
  int l = 1, h = n - 2;
  while(l <= h){
    int mid = (l + h) >> 1;

    // check if the mid is the peak element or not
    if(vv[mid] > vv[mid - 1] && vv[mid] > vv[mid + 1]) return vv[mid];

    // if not, then we have to check where the mid lies
    // if it lies in the progressing graph then we have to search in the right half
    if(vv[mid] > vv[mid - 1]) l = mid + 1;

    // else it lies in the decreasing half, that means we have to remove the right half and search in the left
    else h = mid - 1;
  }
  return -1;
}

int main() {
  vector<int> vv = {1 , 2, 3, 4, 5, 3, 2, 1};
  int n = vv.size();
  cout << "The Peak element is: " << peak_elem(vv, n);
  return 0;
}
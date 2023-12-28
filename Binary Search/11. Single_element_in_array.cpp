// To find the single element in a sorted array

#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& vv, int n){
  // to check if the array conatains single element or not
  if(n == 1) return vv[0];

  // to check if the first and the last elemets are the single elemnts or not
  // for the first element
  if(vv[0] != vv[1]) return vv[0];
  // for the last element
  if(vv[n - 1] != vv[n - 2]) return vv[n - 1];

  int l = 1, h = n - 2;
  while(l <= h){
    // to find the mid of the array
    int mid = (l + h) >> 1;
    // to check if the left is the single number or not
    if(vv[mid] != vv[mid - 1] && vv[mid] != vv[mid + 1]) return vv[mid];

    // if mid is not the single number then
    // if the orientation of the ind of mid is (even, odd) || either even or odd
    // eliminate the left half
    if((mid % 2 == 0 && vv[mid] == vv[mid + 1]) || (mid % 2 == 1 && vv[mid] == vv[mid - 1])) l = mid + 1;
    // else the orientation will be (odd, even)
    // so eliminate the right half
    else h = mid - 1;
  }
  return -1;
}

int main() {
  vector<int> vv = {1,1,2,3,3,4,4,8,8};
  int n = vv.size();
  cout << "The single element is : " << f(vv, n);
}
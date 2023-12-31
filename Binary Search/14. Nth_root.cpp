// to find the nth root of a number
// Expected Time Complexity: O(log n)
// Expected Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

// here, it is nth root of m
// function to calculate the mid^n
// if it is == m return 0
// if it is > m return 1
// if it is < m return 2 
int calc(int mid, int n, int m){
  long long ans = 1;
  for(int i = 1; i <= n; ++i){
    ans *= mid;
    if(ans > m) return 1;
  }
  if(ans == m) return 0;
  return 2;
}
int f(int n, int m){
  int l = 1, h = m;
  while(l <= h){
    int mid = (l + h) >> 1;
    // take the value retured by the function
    int val = calc(mid, n, m);
    // if the function return val == 0
    // the simply return the mid val
    if(val == 0) return mid;
    // else we have to trim the search space if it is > m, from the right half as the other vals will be greater
    if(val == 1) h = mid - 1;
    // else trim the left half
    else l = mid + 1;
  }
  return -1;
}
int main() {
  int n = 3;
  int m = 27;
  cout << "For m:" << m << " and n:" << n <<", val for m^(1/n): " << f(n , m);
}
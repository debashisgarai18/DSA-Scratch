// to find the square root of a number with using square root function
// and also in O(log n) TC

#include <bits/stdc++.h>
using namespace std;

int sq_root(int n){
  int l = 1, h = n;
  while(l <= h){
    int mid = (l + h) >> 1;

    if(mid * mid > n) h = mid - 1;
    else l = mid + 1;
  }
  return h;
}

int main() {
  int n = 49;
  cout << "Square root: " << sq_root(n) << endl;
  return 0;
}
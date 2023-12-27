// this is the Simple binary search using recursion
#include <iostream>
using namespace std;

// bs using recursion
int bs(int arr[], int l, int h, int x){
  if(l > h) return -1;

  int mid = l - (l - h) / 2;
  if(arr[mid] == x) return mid;
  else if(x > arr[mid]) return bs(arr, mid + 1, h, x);

  return bs(arr, l, mid - 1, x);
}

int main() {
  int arr[] = {9, 7, 5, 4, 29, 66};
  cout << bs(arr, 0, 5, 99);
}
#include <bits/stdc++.h>
using namespace std;

// to implement quick sort algorithm

int partition(vector<int> &vv, int low, int high){
  int pivot = vv[low];
  int i = low, j = high;
  while(i < j){
    while(vv[i] <= pivot && i <= high - 1) i++;
    while(vv[j] > pivot && j >= low + 1) j--;

    if(i < j) swap(vv[i], vv[j]);
  }
  swap(vv[low], vv[j]);
  return j;
}
void qsort(vector<int> &vv, int low, int high){
  if(low < high){
    int part = partition(vv, low, high);
    qsort(vv, low, part-1);
    qsort(vv, part+1, high);
  }
}

int main() {
  vector<int> vv = {3, 6, 5, 6, 7, 9, 1};
  qsort(vv, 0, vv.size() - 1);
  for(auto i : vv) cout << i << " ";
}
#include <bits/stdc++.h>
using namespace std;

// implement min-stack
// the main task is to prepare a stack which will eventually represent the min element in the stack

class minStack{
// here, well store the stack elements in the pair of the curr value and the min at that moment
public:
  stack<pair<int,int>> st;

  // the functions to implement the min-stack
  void push(int val){
    if(st.empty()) st.push({val, val});
    else st.push({val, min(st.top().second, val)});
  }
  // function to pop the element
  void pop() {st.pop();}
  int getMin() {return st.top().second;}

  // TC : O(n), SC : O(n)
};

int main() {
  minStack obj1;
  obj1.push(20);
  obj1.push(25);
  obj1.push(19);
  obj1.push(22);
  obj1.pop();
  obj1.push(18);
  cout << "The min is:" << obj1.getMin() << endl;
  obj1.pop();
  cout << "The min is:" << obj1.getMin() << endl;
  return 0;
}
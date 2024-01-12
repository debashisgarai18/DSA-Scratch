// to convert a given array to a SLL

#include <bits/stdc++.h>
using namespace std;

// class to store all the node values
// and the constructor also to store the dtypes
class Node{
  public:
  int data;
  Node* next;

  // constructor
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};

// function to convert an array to SLL
Node* conArray2SLL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  // the iterator to move whenever a new node is created for a new value of the array
  Node* itr = head;
  for(int i = 1; i < arr.size(); ++i){
    // tmp node to store the value of the new idx of the array 
    Node* tmp = new Node(arr[i]);
    itr -> next = tmp;
    // itr = itr -> next;
    itr = tmp;
  }
  return head;
}

int main() {
  vector<int> arr = {89, 2, 3, 4, 5};
  Node* res = conArray2SLL(arr);
  cout << "The head of SLL is: " << res -> data << endl;

  // traversal of the SLL
  // never ever move the head, place tmp and move the tmp
  Node* temp = res;
  while(temp){
    cout << temp -> data << " ";
    temp  = temp -> next;
  }
  return 0;
}
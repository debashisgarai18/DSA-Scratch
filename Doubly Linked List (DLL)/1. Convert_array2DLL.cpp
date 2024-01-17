// to convert an array to a doubly linked list

#include <bits/stdc++.h>
using namespace std;

// class to store the data, previous and the next node of the DLL
class Node{
  public:
  int data;
  Node* next;
  Node* back;

  // constructor
  Node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
  }

  Node(int data1, Node* next1, Node* back1){
    data = data1;
    next = next1;
    back = back1;
  }
};

// fucntion to convert array to DLL
Node* convert_arr2DLL(vector<int> &vv){
  Node* head = new Node(vv[0]);
  Node* prev = head;
  for(int i = 1; i < vv.size(); ++i){
    Node* temp = new Node(vv[i], nullptr, prev);
    prev -> next = temp;
    prev = temp;
  }
  return head;
}

// to print the vals
void print(Node* head){
  while(head != NULL){
    cout << head -> data << " ";
    head = head -> next;
  }
}
int main() {
  vector<int> vv = {12, 5, 7, 8};
  Node* head = convert_arr2DLL(vv);
  print(head);
  return 0;
}
// to delete the head and the tail node from the SLL

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

// function to delete the head of the SLL
Node* delHead(Node* head){
  Node* temp = head;
  // just point the head to the next node
  head = head -> next;
  // delete existing node
  delete temp;
  return head;
}

// function to delete the tail node
// for this we need ot move the temp directing to the head to the node befor the last one
Node* delTail(Node* head){
  if(head == NULL) return head;
  Node* temp = head;
  while(temp -> next -> next != NULL){
    temp  = temp -> next;
  }
  // once the temp is reached to specific location
  // joint point it towards NULL
  delete temp -> next -> next;
  temp -> next = NULL;
  return head;
}

int main() {
  vector<int> arr = {89, 2, 3, 4, 5};
  Node* res = conArray2SLL(arr);
  // Node* head1 = delHead(res);
  Node* head2 = delTail(res);
  // traversal of the SLL
  // never ever move the head, place tmp and move the tmp
  Node* temp = head2;
  while(temp){
    cout << temp -> data << " ";
    temp  = temp -> next;
  }
  return 0;
}
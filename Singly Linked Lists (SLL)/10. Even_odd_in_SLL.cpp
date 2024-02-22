// TODO : Segregate the odd indexes followed by even indexes in the SLL and return the head
// eg : LL: 2 3 4 5 6, resLL : 2 4 6 3 5

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

// function to append the even idxs to the odd idxs
Node* even2odd(Node* head){
  // Brute force : TC : O(2n), SC : O(n)
  // we'll make a dummy array containing of the odd idx values followed by the even idxs valus
  // then we'll replace the values in the original LL and return the head

  vector<int> dummyArray;
  Node* temp = head; // for odd idxs
  
  // loop condition
  while(temp != nullptr && temp -> next != nullptr){
    dummyArray.push_back(temp -> data);
    temp = temp -> next -> next;
  }
  // check for the element at the last node (if exists)
  if(temp) dummyArray.push_back(temp -> data);

  temp = head -> next; // for even idxs
  // loop condition
  while(temp != nullptr && temp -> next != nullptr){
    dummyArray.push_back(temp -> data);
    temp = temp -> next -> next;
  }
  // check for the element at the last node (if exists)
  if(temp) dummyArray.push_back(temp -> data);

  // now replacing the values in the array with the values in the original list
  int i = 0;
  temp = head;
  while(temp != nullptr){
    temp -> data = dummyArray[i];
    i++;
    temp = temp -> next;
  }
  return head;
}

int main() {
  vector<int> arr1 = {2, 3, 4, 5, 6};
  Node* head1 = conArray2SLL(arr1);

  // traversal of the SLL
  // never ever move the head, place tmp and move the tmp
  Node* temp = even2odd(head1);
  while(temp){
    cout << temp -> data << " ";
    temp  = temp -> next;
  }
  return 0;
}
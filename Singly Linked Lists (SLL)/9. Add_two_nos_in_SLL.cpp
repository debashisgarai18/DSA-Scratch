// TODO : To add the given numbers in a LL and find the result
// for eg: ll1 = 7 8 9, ll2 = 6 8 2 1, res = 3 7 2 2

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

// function to add two SLLs
Node* add2nos(Node* head1, Node* head2){
  // we will create a new dummy list to store the results
  // create a current pointing to the current node of the result
  // add the current head nodes and store the sum % 10 to the current
  // store the sum / 10 to the carry 
  // return dummyNode->next (as it ts the head of the new list)

  Node* temp1 = head1;
  Node* temp2 = head2;
  Node* dummyNode = new Node(-1);
  Node* curr = dummyNode;
  int carry = 0;
  
  // stop when both becomes nullptr
  while(temp1 != nullptr || temp2 != nullptr){
    int sum = carry;
    // if temmp1 exists the  do the sum
    if(temp1) sum += temp1 -> data;
    if(temp2) sum += temp2 -> data;

    // create the new node for the sum
    Node* newNode = new Node(sum % 10);
    carry = sum / 10;
    curr -> next = newNode;
    curr = curr -> next;

    // increment the temps if they are not null
    if(temp1) temp1 = temp1 -> next;
    if(temp2) temp2 = temp2 -> next;
  }
  // return the head of the new LL
  return dummyNode -> next;
}
int main() {
  vector<int> arr1 = {7, 8, 9};
  vector<int> arr2 = {6, 8, 2, 1};
  Node* head1 = conArray2SLL(arr1);
  Node* head2 = conArray2SLL(arr2);
  
  // traversal of the SLL
  // never ever move the head, place tmp and move the tmp
  Node* temp = add2nos(head1, head2);
  while(temp){
    cout << temp -> data << " ";
    temp  = temp -> next;
  }
  return 0;
}
// to delete kth node from the SLL

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

// function to delete the node in the Kth posiiton
Node* delKPos(Node* head, int k){
  if(head == NULL) return head;
  // to check if the node is the first or not
  if(k == 1){
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
  }
  Node* temp = head;
  Node* prev = NULL;
  int cnt = 0;
  while(temp){
    // just count the position of the nodes
    cnt++;
    // if the count is mnatching the val of k
    if(cnt == k){
      // just point the previous pointer to the next node of the curr temp
      prev -> next = temp -> next;
      delete temp;
      break;
    }
    // else just assign prev to the current temp and move temp to the next position
    prev = temp;
    temp = temp -> next;
  }
  return head;
}

int main() {
  vector<int> arr = {89, 2, 3, 4, 5};
  Node* res = conArray2SLL(arr);
  Node* head = delKPos(res, 5);
  // traversal of the SLL
  // never ever move the head, place tmp and move the tmp
  Node* temp = head;
  while(temp){
    cout << temp -> data << " ";
    temp  = temp -> next;
  }
  return 0;
}
// to insert element before the node with value k in the SLL

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

  Node(int data1, Node* next1){
    data = data1;
    next = next1;
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

// function to insert before the node with k value
Node* insBefKVal(Node* head, int k, int ele){
  if(head == NULL) return new Node(ele);
  Node* temp = head;
  while(temp -> next != NULL){
    // just chechk that the data next to the temp node equals the val of k or not
    if(temp -> next -> data == k){
      // then just create the new node and link it to the next of the temp and link the curr temp to the new node
      Node* newNode = new Node(ele, temp -> next);
      temp -> next = newNode;

      break;
    }
    // else just increment the temp pointer to the next
    temp = temp -> next;
  }
  return head;
}

int main() {
  vector<int> arr = {89, 2, 3, 4, 5};
  Node* res = conArray2SLL(arr);
  Node* head = insBefKVal(res, 89, 22);
  // traversal of the SLL
  // never ever move the head, place tmp and move the tmp
  Node* temp = head;
  while(temp){
    cout << temp -> data << " ";
    temp  = temp -> next;
  }
  return 0;
}
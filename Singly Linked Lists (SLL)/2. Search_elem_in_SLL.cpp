// to search an element from a linked list and return the position of that element
#include <bits/stdc++.h>
using namespace std;

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


// function to search element in a SLL
// return the position also
int Lsearch(Node* head, int target){
  Node* temp = head;
  int pos = 1;
  while(temp){
    if(temp -> data == target) return pos;
    temp = temp -> next;
    pos++;
  }
  return -1;
}

int main() {
  vector<int> arr = {89, 2, 3, 4, 5};
  Node* res = conArray2SLL(arr);
  cout << "The element is present in: " << Lsearch(res, 89);
  return 0;
}
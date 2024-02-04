// to insert a node before the node in the doubly linked list
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

// to insert before the head of DLL
Node* insertBefHead(Node* head, int val){
  Node* newNode = new Node(val, head, nullptr);
  head -> back = newNode;
  return newNode;
}

// to insert before the tail of DLL
Node* insertBefTail(Node* head, int val){
  if(head == nullptr){
    return insertBefHead(head, val);
  }

  Node* tail = head;
  while(tail -> next != nullptr){
    tail = tail -> next;
  }
  Node* prev = tail -> back;
  Node* newNode = new Node(val, tail, prev);
  prev -> next = newNode;
  tail -> back = newNode;

  return head;
}

// to insert before kth node
Node* insertBefKth(Node* head, int val, int k){
  if(head == nullptr) return new Node(val);
  if(k == 1) return insertBefHead(head, val);
  int cnt =0;
  Node* temp = head;
  while(temp != nullptr){
    cnt++;
    if(cnt == k) break;
    temp = temp -> next;
  }

  Node* prev = temp -> back;
  Node* front = temp -> next;
  if(front == nullptr) return insertBefTail(head, val);

  Node* newNode = new Node(val, front, prev);
  front -> back =  newNode;
  prev -> next = newNode;
  
  return head;
}

// to insert before k node
// cannot insert before the head as if it is then the head will change
void insertBefKNode(Node* temp, int val){
  Node* prev = temp -> back;

  Node* newNode = new Node(val, temp, prev);
  prev -> next = newNode;
  temp -> back = newNode;
}

// to print the vals
void print(Node* head){
  while(head != NULL){
    cout << head -> data << " --> ";
    head = head -> next;
  }
}

int main() {
  vector<int> vv = {1, 2, 4, 7, 8};
  Node* head = convert_arr2DLL(vv);
  // head = insertBefHead(head, 100); // to insert before head node
  // head = insertBefTail(head, 100); // to insert before tail node
  // head = insertBefKth(head, 100, 5); // toi insert before kth node
  insertBefKNode(head -> next, 100); // to insert before node k
  print(head);
  return 0;
}
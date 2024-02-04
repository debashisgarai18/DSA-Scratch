// to delete a node from the doubly linked list
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

// delete the head of the DLL
Node* deleteHead(Node* head){
  if(head == NULL || head -> next == NULL) return NULL;

  Node* temp = head;
  head = head -> next;

  head -> back = nullptr;
  temp -> next = nullptr;
  
  delete temp;
  return head;
}

// delete the tail of the DLL
Node* deleteTail(Node* head){
  // tocheck if the DLL has empty or only 1 node
  if(head == NULL || head -> next == NULL) return NULL;

  Node* tail = head;
  while(tail -> next != nullptr){
    tail = tail -> next;
  }
  Node* prev = tail -> back;
  prev -> next = nullptr;
  tail -> next = nullptr;
  tail -> back = nullptr;

  delete tail;
  return head;
}


// delete the kth element of the DLL
Node* delKElem(Node* head, int k){
  if(head == NULL) return NULL;
  int cnt = 0;
  Node* temp = head;
  while(temp != nullptr){
    cnt++;
    if(cnt == k) break;

    temp = temp -> next;
  }
  // get the previuos and the next ponters of the temp node
  Node* prev = temp -> back;
  Node* after = temp -> next;

  // edge cases
  // 1. if the DLL has only 1 element
  if(prev == NULL && after == NULL){
    delete temp;
    return nullptr;
  }
  // 2. if k = 1 --> head node
  else if(prev == NULL){
    return deleteHead(head);
  }
  // 3. if k == n --> tail node
  else if(after == NULL){
    return deleteTail(head);
  }

  prev -> next = after;
  after -> back = prev;

  temp -> next = nullptr;
  temp -> back = nullptr;

  delete temp;
  return head;
}

// delete the node K from the DLL
// condition : we cannot delete the head 
void deleteKNode(Node* temp){
  Node* prev = temp -> back;
  Node* front = temp -> next;

  // condiiton if the k node is the last node
  if(front == nullptr){
    prev -> next = nullptr;
    temp -> back = nullptr;
    delete temp;
  } 

  prev -> next = front;
  front -> back = prev;

  temp -> next = temp -> back = nullptr;
  delete temp;
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
  // head = deleteHead(head); // to delete Head of DLL
  // head = deleteTail(head); // to delete Tail of DLL
  // head = delKElem(head, 3); // to delete kth element
  deleteKNode(head -> next -> next); // to delete the k node
  print(head);
  return 0;
}
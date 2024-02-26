// to sort the given SLL into 0s, 1s and 2s
// for eg : given sll = 0, 2, 1, 1, 0, 2, 2, 0, res sll = 0, 2, 1, 1, 0, 2, 2, 0

#include <bits/stdc++.h>
using namespace std;

// class to store all the node values
// and the constructor also to store the dtypes
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// function to convert an array to SLL
Node *conArray2SLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    // the iterator to move whenever a new node is created for a new value of the array
    Node *itr = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        // tmp node to store the value of the new idx of the array
        Node *tmp = new Node(arr[i]);
        itr->next = tmp;
        // itr = itr -> next;
        itr = tmp;
    }
    return head;
}

// function to sort the given sll
Node *sort012(Node *head)
{
    // brute force: by taking the values and storing into the array
    // we'll store the 0s first followed by 1s and then 2s and then replace the values of the sll by the arrays
    vector<int> vv;
    Node *temp = head;
    // to store the 0s
    while (temp != nullptr)
    {
        if (temp->data == 0)
            vv.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    // to store the 1s
    while (temp != nullptr)
    {
        if (temp->data == 1)
            vv.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    // to store the 2s
    while (temp != nullptr)
    {
        if (temp->data == 2)
            vv.push_back(temp->data);
        temp = temp->next;
    }

    // to replace the vals in the sll with those of the sll
    int i = 0;
    temp = head;
    while (temp != nullptr)
    {
        temp->data = vv[i];
        i++;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr1 = {0, 2, 1, 1, 0, 2, 2, 0};
    Node *head1 = conArray2SLL(arr1);

    // traversal of the SLL
    // never ever move the head, place tmp and move the tmp// to sort the given SLL into 0s, 1s and 2s
    // for eg : given sll = 0, 2, 1, 1, 0, 2, 2, 0, res sll = 0, 2, 1, 1, 0, 2, 2, 0

#include <bits/stdc++.h>
    using namespace std;

    // class to store all the node values
    // and the constructor also to store the dtypes
    class Node
    {
    public:
        int data;
        Node *next;

        // constructor
        Node(int data1)
        {
            data = data1;
            next = nullptr;
        }
    };

    // function to convert an array to SLL
    Node *conArray2SLL(vector<int> & arr)
    {
        Node *head = new Node(arr[0]);
        // the iterator to move whenever a new node is created for a new value of the array
        Node *itr = head;
        for (int i = 1; i < arr.size(); ++i)
        {
            // tmp node to store the value of the new idx of the array
            Node *tmp = new Node(arr[i]);
            itr->next = tmp;
            // itr = itr -> next;
            itr = tmp;
        }
        return head;
    }

    // function to sort the given sll
    Node *sort012(Node * head)
    {
        // brute force: by taking the values and storing into the array
        // we'll store the 0s first followed by 1s and then 2s and then replace the values of the sll by the arrays
        // vector<int> vv;
        // Node* temp = head;
        // // to store the 0s
        // while(temp != nullptr){
        //   if(temp -> data == 0) vv.push_back(temp -> data);
        //   temp = temp -> next;
        // }
        // temp = head;
        // // to store the 1s
        // while(temp != nullptr){
        //   if(temp -> data == 1) vv.push_back(temp -> data);
        //   temp = temp -> next;
        // }
        // temp = head;
        // // to store the 2s
        // while(temp != nullptr){
        //   if(temp -> data == 2) vv.push_back(temp -> data);
        //   temp = temp -> next;
        // }

        // // to replace the vals in the sll with those of the sll
        // int i = 0;
        // temp = head;
        // while(temp != nullptr){
        //   temp -> data = vv[i];
        //   i++;
        //   temp = temp -> next;
        // }

        // This is not optimal as the TC : O(4n), SC: O(n);
        // better solution with TC : O(2n), SC : O(1)

        Node *temp = head;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        // to count the no of 0s, 1s and 2s
        while (temp)
        {
            if (temp->data == 0)
                cnt0++;
            else if (temp->data == 1)
                cnt1++;
            else
                cnt2++;

            temp = temp->next;
        }

        // now put those count of 0s, 1s and 2s in order in the SLL;
        temp = head;
        while (temp)
        {
            if (cnt0)
            {
                temp->data = 0;
                cnt0--;
            }
            else if (cnt1)
            {
                temp->data = 1;
                cnt1--;
            }
            else
            {
                temp->data = 2;
                cnt2--;
            }
            temp = temp->next;
        }
        return head;
    }

    int main()
    {
        vector<int> arr1 = {0, 2, 1, 1, 0, 2, 2, 0};
        Node *head1 = conArray2SLL(arr1);

        // traversal of the SLL
        // never ever move the head, place tmp and move the tmp
        Node *temp = sort012(head1);
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        return 0;
    }
    Node *temp = sort012(head1);
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
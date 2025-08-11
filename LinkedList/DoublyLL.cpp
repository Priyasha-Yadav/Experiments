#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {};
};

// Printing the linked list
void PrintList(Node *head)
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " <-> ";
        ptr = ptr->next;
    };
    cout<< "nullptr" << endl;
}

// Insertion at the end of the doubly linked list
void insertionAtEnd(Node*&head, int val){
Node* ptr = head;
Node* newNode = new Node(val);
while(ptr->next != nullptr){
    ptr= ptr->next;
}
ptr->next=newNode;
newNode->prev = ptr;
return;
}

// Insertion at the beginning of the doubly linked list
void InsertionAtBeginning(Node*&head, int val){
    Node* newNode = new Node(val);
    head->prev = newNode;
    newNode->next= head;
    head = newNode;
    return;
}

// Insertion at a specific position in the doubly linked list
void InsertionAtPosition(Node*&head, int val, int pos ){
    Node* newNode = new Node(val);
    Node* ptr = head;
    if(pos == 0){
        InsertionAtBeginning(head, val);
        return;
    }
    for(int i = 1; i < pos-1; i++){
        ptr = ptr->next;
    };

        newNode->prev = ptr;
        newNode->next = ptr->next;
        ptr->next->prev = newNode;
        ptr->next = newNode;
    return;

}

// Deletion at the end of the doubly linked list
void DeletionAtEnd(Node*&head){
    if(!head) return;
    Node* ptr = head;
    if(ptr->next == nullptr){
        delete ptr;
        head = nullptr;
        return;
    };
    while(ptr->next != nullptr ){
        ptr = ptr->next;
    }
    Node* temp = ptr->prev;
    delete ptr;
    temp->next = nullptr;
    return;

}

// Deletion at the beginning of the doubly linked list
void DeletionAtBeginning(Node*&head){
    Node* ptr = head;
    head->next->prev = nullptr;
    head = head->next;
    delete ptr;
    return;

}

// Deletion at a specific position in the doubly linked list
void DeletionAtPosition(Node*&head, int pos){
    Node* ptr = head;
    if(!head) return;
    if(ptr->next == nullptr){
        delete ptr;
        head = nullptr;
        return;
    }
    for(int i = 1; i < pos-1; i++){
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
    delete ptr->next->prev;
    ptr->next->prev = ptr;
    return;

}


int main()
{

    vector<int> vec = {1, 2, 3, 4, 5, 6};
    Node *head = new Node(vec[0]);
    Node *ptr = head;
    for (int i = 1; i < vec.size(); i++)
    {
        Node *newNode = new Node(vec[i]);
        ptr->next = newNode;
        newNode->prev = ptr;
        ptr = newNode;
    }
    InsertionAtBeginning(head, 0);
    insertionAtEnd(head, 7);
    InsertionAtPosition(head, 4, 4);
    DeletionAtEnd(head);
    DeletionAtBeginning(head);
    DeletionAtPosition(head, 3);
    countNodes(head);
    PrintList(head);
    return 0;
}

// Write a function to traverse the list forward and backward.

// Write a function to search for a value in the doubly linked list.

// Write a function to count the number of nodes.
int countNodes(Node*&head){
    int count = 0;
    Node* ptr = head;
    while(ptr!=nullptr){
        ptr= ptr->next;
        count++;
    };
    return count;
}

// Write a function to reverse a doubly linked list.

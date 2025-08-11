#include <iostream>
#include <vector>
using namespace std;

// Node class definition
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {};
};

// Insertion at the end of the linked list
void insertionAtEnd(Node *&head, int val)
{
    Node *ptr = head;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    };
    Node *newNode = new Node(val);
    ptr->next = newNode;
}

// Insertion at the beginning of the linked list
void insertionAtBegiinning(Node*&head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return;
}

// Insertion at a specific position in the linked list
void insertionAtPosition(Node *&head, int val, int pos)
{
    if (pos == 0)
    {
        insertionAtBegiinning(head, val);
        return;
    }
    Node *ptr = head;
    Node* newNode = new Node(val);
    for ( int i = 1; i < pos-1; i++){
        ptr= ptr->next;

    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return;
  
}

// Deletion at the end of the linked list
void DeletionAtEnd(Node*&head){
    if(!head)  return;
    Node* ptr = head;
    while(ptr->next->next != nullptr){
        ptr = ptr->next;
    }
    delete ptr->next;
    ptr->next = nullptr;
    return;
}

// Deletion at the beginning of the linked list
void DeletionAtBeginning(Node*&head){
    if(!head) return;
    Node* ptr = head;
    head = head-> next;
    delete ptr;
    return;
}

// Deletion at a specific position in the linked list
void DeletionAtPostion(Node*&head, int pos){
    if(!head) return;

    if(pos==0){
        DeletionAtBeginning(head);
        return;
    }

    Node*ptr = head;
    for(int i = 1; i < pos-1; i++){
        ptr=ptr->next;
        Node* toDelete = ptr->next;
        if(toDelete == nullptr) return; 
        ptr->next = toDelete->next;
        delete toDelete;
        return;
    }

}

// Function to print the linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "nullptr" << endl;
    return;
}

int main()
{
// Implementation of the linked list using a vector
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    Node *head = new Node(vec[0]);
    Node *ptr = head;
    for (int i = 1; i < vec.size(); i++)
    {
        Node *newNode = new Node(vec[i]);
        ptr->next = newNode;
        ptr = newNode;
    };

    insertionAtEnd(head, 7);
    insertionAtPosition(head, 0, 3);
    insertionAtBegiinning(head, 0);
    DeletionAtEnd(head);
    DeletionAtBeginning(head);
    DeletionAtPostion(head, 3);
    printList(head);
    return 0;
}

// How do you count the number of nodes in a linked list?

int countNodes(Node*&head){
    int count = 0;
    Node* ptr = head;
    while(ptr!=nullptr){
        ptr= ptr->next;
        count++;
    };
    return count;
}

// Write a function to reverse a linked list.

// How do you detect a loop in a linked list? (Floyd’s algorithm)

// Write a function to search an element in a linked list.
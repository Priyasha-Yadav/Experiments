#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

int main(){
    vector<int> vec = {1,2,3,4,5,6};
    Node* head = new Node(vec[0]);
    Node* ptr = head;

    for(int i = 1; i < vec.size(); i++){
        Node* newNode = new Node(vec[i]);
        ptr->next = newNode;
        ptr = ptr->next;
    }
    ptr->next = head;
    
     Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;

    
    return 0;
}

   
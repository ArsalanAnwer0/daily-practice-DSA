// linked list
// stack
// queue
// tree
// BST
// heap
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val):data(val),next(nullptr){}
    
};

void insertAtHead(node* &head,node* &tail,int d){
    // when list is empty
    if(head == nullptr){
        node* newNode = new node(d);
        head = newNode;
        tail = newNode;
        return;
    }
    // when list is not empty
    node* newNode = new node(d);
    newNode->next =  head;
    head = newNode;
}

void insertAtTail(node* &head,node* &tail,int d){
    // checking if the list is empty
        if(head == nullptr){
        node* newNode = new node(d);
        head = newNode;
        tail = newNode;
        return;
    }
    // if the list is not empty
    node* newNode = new node(d);
    tail->next = newNode;
    tail = newNode;
}

// lets try to insert at any position

void insertAtAnyPosition(node* &head,node* &tail,int pos, int d){
    //if our list is empty
    if(head == nullptr){
        node* newNode = new node(d);
        tail = newNode;
        head = newNode;
        return;
    }
    // if our list is not empty
    int count = 1;
    node* temp = head;
    while(count < pos - 1){
        count++;
        temp = temp -> next;
    }
    // we are where we want to insert
    node* newNode = new node(d);
    


}

void printLL(node* head,node* tail){
    node* temp = head;
    cout << "Linked List: ";
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
}



int main(){
    node* head = nullptr,* tail = nullptr;
    insertAtHead(head,tail,55);
    insertAtHead(head,tail,45);
    insertAtHead(head,tail,35);
    insertAtHead(head,tail,25);
    insertAtTail(head,tail,99);
    printLL(head,tail);
}
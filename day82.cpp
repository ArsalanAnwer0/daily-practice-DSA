// linked list
// stacks
// queue
// tree
// BST
// Graph
// Heap

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next,* prev;

    // constructor

    node(int val): data(val),next(nullptr),prev(nullptr){
        // hehe
    }
    ~node(){
        int val = this->data;
        if(this->next!=nullptr){
            delete this->next;
            this->next = nullptr;
        }
        cout << "Memory free of " << val << endl;   
    }
};



    void insertAtHead(node* &head,node* &tail,int d);
    void insertAtTail(node* &head,node* &tail, int d);
    void insertAtAnyPosition(node* &head,node* &tail,int pos,int d);
    void printLL(node* head,node* tail);
    void deleteNode(node* &head,node* &tail,int pos);

class heap{
    public:
    int* arr;
    int capacity;
    int size;

    // constructor
    heap(int capacity){
        arr = new int[capacity];
        size = 0;
    }
    void insertInHeap(int element);
    void deleteInHeap();
    void heapify(int index);
    void whatToHeapify();
    void heapSort();
};





int main(){

    node* head = nullptr;
    node* tail = nullptr;
    insertAtHead(head,tail,5);
    insertAtHead(head,tail,4);
    insertAtHead(head,tail,3);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,7);
    insertAtTail(head,tail,8);
    insertAtAnyPosition(head,tail,7,0);
    deleteNode(head,tail,7);
    printLL(head,tail);



    return 0;
}



// inserting in doubly linked list
    // I also make a tail hehe
    void insertAtHead(node* &head,node* &tail,int d){
        // check if list is empty
        if(head == nullptr){
            // create node
            node* newNode = new node(d);
            head = newNode;
            tail = newNode;
            return;
        }
        // if list is not empty
        node* newNode =  new node(d);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    // inserting at tail
    void insertAtTail(node* &head,node* &tail, int d){
        // check if list is empty
        if(tail == nullptr){
            // create node
            node* newNode = new node(d);
            head = newNode;
            tail = newNode;
            return;
        }
        // if list is not empty
        node* newNode =  new node(d);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    // insert at any position
    void insertAtAnyPosition(node* &head,node* &tail,int pos,int d){
        // if pos 1 meaning we want to insert at head
        if(pos == 1){
            insertAtHead(head,tail,d);
            return;
        }
        node* temp=head;
        int cnt = 1;
        while(cnt < pos - 1){
            temp = temp->next;
            cnt++;
        }
        // inserting at last position
        if(temp->next == nullptr){
            node* newNode = new node(d);
            temp->next = newNode;
            newNode->prev = temp;
            tail = newNode;
        }
        else{
        // we are at the position where we have to insert
        // inserting at mid position
        node* newNode = new node(d);
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        }
    }
    // printing list
    void printLL(node* head,node* tail){
        node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "Head: " << head->data <<  endl;
        cout << "Tail: " << tail->data << endl;
    }
    // delete in linked list
    void deleteNode(node* &head,node* &tail,int pos){
        if(pos == 1){
            node* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            return;
        }
        int cnt = 1;
        node* temp = head;
        while(cnt < pos){
            temp = temp->next;
            cnt++;
        }
        // handling this case for last node deletion
        if(temp->next == nullptr){
            tail = temp->prev;
            tail->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }

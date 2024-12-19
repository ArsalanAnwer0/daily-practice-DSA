#include <iostream>
using namespace std;
// Linear Searching
// Binary Search
// Tree
// BST
// Heap
// Linked List
// Stack
// Queue
// BFS & DFS

class tree{

    public:
    int data;
    tree* right,*left;

    tree(int val): data(val),right(nullptr),left(nullptr) {}
};

class node
{
public:
    int data;
    node *next;

    node(int value) : data(value), next(nullptr) {}
    ~node(){

        int val =  this->data;
        if(this->next!=nullptr){
            delete this->next;
            this->next=nullptr;
        }
        cout << endl << "Memory free of " << val << endl; 
    }
};

void insertAtHead(node *&head, node *&tail, int val)
{
    if (head == nullptr)
    {
        node *newNode = new node(val);
        head = newNode;
        tail = newNode;
        return;
    }
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
}
void insertAtTail(node *&head, node *&tail, int val)
{

    if (tail == nullptr)
    {

        node *newNode = new node(val);
        tail = newNode;
        head = newNode;
        return;
    }
    node *newNode = new node(val);
    tail->next = newNode;
    tail = newNode;
}
void print(node *&head, node *&tail)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
}
void insertAtAnyPosition(node *&head, node *&tail, int pos, int val)
{
    if (head == nullptr)
    {

        node *newNode = new node(val);
        head = newNode;
        tail = newNode;
        return;
    }
    if(pos == 1){
        insertAtHead(head,tail,val);
        return;
    }
    int count = 1;
    node *temp = head;
    while (count < pos - 1 )
    {
        count++;
        temp = temp->next;
    }
    node *newNode = new node(val);
    if (temp->next == nullptr)
    {

        tail = newNode;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(node* &head,node* &tail,int pos){

    if(head == nullptr){
        cout << "Nothing to delete" << endl;
        return;
    }
    if(pos == 1){
        node* temp = head;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
        return;
    }
    int count = 1;
    node* curr = head;
    node* prev = nullptr;
    while(count < pos){
        prev = curr;
        curr = curr -> next;

        count ++;
    }
    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
}
int main()
{

    node *head = nullptr;
    node *tail = nullptr;
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 24);
    insertAtTail(head, tail, 4);
    print(head, tail);
    cout << endl;
    insertAtAnyPosition(head,tail,3,99);
    print(head,tail);
    deleteNode(head,tail,3);
    print(head,tail);


    return 0;
}
// Linked List
// Stack
// Queue
// Tree
// Tree traversal
// Binary Search Tree
// Heap

#include <iostream>
using namespace std;
// Singly
class node
{
public:
    int data;
    node *next;
    node* prev;

    node(int value) : data(value), next(nullptr) , prev(nullptr) {}
};
void print(node *&head, node *&tail)
{

    node *temp = head;
    while (!(!temp))
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
}
void insertAtHead(node *&head, node *&tail, int d)
{
    // If linked list is empty
    if (head == nullptr)
    {
        node *newNode = new node(d);
        head = newNode;
        tail = newNode;
        return;
    }
    // if linked list if not empty
    node *newNode = new node(d);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAtTail(node *&head, node *&tail, int d)
{
    // If linked list is empty
    if (tail == nullptr)
    {
        node *newNode = new node(d);
        head = newNode;
        tail = newNode;
        return;
    }
    node *newNode = new node(d);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
// insertAtAnyPosition
void insertAtAnyPosition(node *&head, node *&tail, int pos, int d)
{
    if (pos == 0)
    {
        insertAtHead(head, tail, d);
        return;
    }
    int count = 1;
    node *temp = head;
    while (count < pos)
    {

        temp = temp->next;
        count++;
    }

    // at this point we will know where the temp is and where we need to insert
    // code for handling insertion at last node
    node *newNode = new node(d);
    if (temp->next == nullptr)
    {
        tail = newNode;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(node* &head, node* &tail, int pos){

    // give  pos is 1
    if(pos == 1){

        node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return;

    }


    int count = 1;
    node* current = head;
    node* previous = NULL;
    while(count < pos){

        previous = current;
        current = current->next;
        count ++;

    }
    // we have reach the node we want to delete
    if(current->next == NULL){

        tail = previous;

    }
    previous->next = current->next;
    current->next = NULL;
    current->prev = NULL;
    delete current;
}

int main()
{

    node *head = nullptr, *tail = nullptr;
    insertAtTail(head, tail, 5);
    insertAtHead(head, tail, 3);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 8);
    insertAtAnyPosition(head, tail, 4, 9);
    deleteNode(head,tail,5);
    print(head, tail);

    return 0;
}

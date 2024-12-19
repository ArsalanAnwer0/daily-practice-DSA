// Learning linked list
#include <iostream>
using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int value) : data(value), next(nullptr) {}
//     // Destructor
//     ~Node()
//     {

//         int value = this->data;
//         if (this->next != NULL)
//         {
//             delete this->next;
//             this->next = nullptr;
//         }
//         cout << "Memory free of " << value << endl;
//     }
// };

// void insertAtHead(Node *&head, int d)
// {

//     // new node create
//     Node *temp = new Node(d);
//     temp->next = head;
//     head = temp;
// }

// void insertAtTail(Node *&tail, int d)
// {

//     Node *temp = new Node(d);
//     tail->next = temp;
//     tail = temp;
// }

// void insertAtPosition(Node *&head, Node *&tail, int position, int d)
// {

//     if (position == 1)
//     {
//         insertAtHead(head, d);
//         return;
//     }
//     Node *temp = head;
//     int count = 1;
//     Node *nodeToInsert = new Node(d);
//     while (count < position - 1)
//     {
//         count++;
//         temp = temp->next;
//     }
//     if (temp->next == NULL)
//     {
//         tail = nodeToInsert;
//     }
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {

//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void deleteNode(Node *&head, Node *&tail, int position)
// {
//     // if linked list is empty
//     if (head == NULL)
//     {
//         cout << "Linked List is empty!" << endl;
//         return;
//     }
//     // if we are deleting first node
//     if (position == 1)
//     {
//         Node *temp = head;
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//         return;
//     }
//     int count = 1;
//     Node *curr = head, *prev = NULL;
//     while (count < position)
//     {
//         // Position not found
//         if (curr != NULL && prev != NULL)
//         {
//             prev = curr;
//             curr = curr->next;
//             count++;
//         }
//         else{
//             cout << "Position not found!";
//             return;
//         }
//     }
//     if (curr->next == NULL)
//     {
//         tail = prev;
//     }
//     prev->next = curr->next;
//     curr->next = NULL;
//     delete curr;
// }

// int main()
// {

//     Node *node1 = new Node(10);

//     // cout << node1 -> data << endl;
//     // cout << node1 -> next << endl;

//     Node *head = node1, *tail = node1;
//     insertAtTail(tail, 12);
//     insertAtTail(tail, 15);
//     insertAtPosition(head, tail, 4, 13);
//     deleteNode(head, tail, 5);
//     cout << endl;
//     print(head);
//     cout << endl;
//     cout << "Head: " << head->data << endl;
//     cout << "Tail: " << tail->data;

//     return 0;
// }


// Doubly Linked List
// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *previous;

//     // constructur
//     Node(int value) : data(value), next(NULL), previous(NULL)
//     {
//     }
// };

// void print(Node *head,Node* tail)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout <<  endl << "Head: " << head->data << endl;
//     cout << "Tail: " << tail->data << endl;
// }
// int getLength(Node *&head)
// {

//     Node *temp = head;
//     int length = 1;
//     while (temp != head)
//     {
//         length++;
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     return length;
// }

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     Node *temp = head;
//     Node *newNode = new Node(d);
//     newNode->next = temp;
//     temp->previous = newNode;
//     head = newNode;
// }

// void insertAtTail(Node *&head, Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     tail->next = temp;
//     temp->previous = tail;
//     tail = temp;
// }

// void insertAtPosition(Node *&head, Node *&tail, int position, int d)
// {

//     if (position == 1)
//     {
//         insertAtHead(head, tail, d);
//         return;
//     }
//     Node *temp = head;
//     int count = 1;
//     Node *nodeToInsert = new Node(d);
//     while (count < position - 1)
//     {
//         count++;
//         temp = temp->next;
//     }
//     if (temp->next == NULL)
//     {
//         insertAtTail(head,tail,d);
//         return;
//     }
//     nodeToInsert->next = temp->next;
//     temp->next->previous = nodeToInsert;
//     temp->next = nodeToInsert;
//     nodeToInsert->previous = temp;
// }

// void deleteNode(Node *&head, Node *&tail, int position)
// {
//     // if linked list is empty
//     if (head == NULL)
//     {
//         cout << "Linked List is empty!" << endl;
//         return;
//     }
//     // if we are deleting first node
//     if (position == 1)
//     {
//         Node *temp = head;
//         head = head->next;
//         head->previous = NULL;
//         temp->next = NULL;
//         delete temp;
//         return;
//     }
//     int count = 1;
//     Node *curr = head, *prev = NULL;
//     while (count < position)
//     {
//         // Position not found
//         if (curr != NULL)
//         {
//             prev = curr;
//             curr = curr->next;
//             count++;
//         }
//         else{
//             cout << "Position not found!";
//             return;
//         }
//     }
//     if (curr->next == NULL)
//     {
//         tail = prev;
//         prev->next = NULL;
//         curr->previous = NULL;
//         delete curr;
//         return;
//     }
//     else{
//     prev->next = curr->next;
//     curr->next->previous = prev;
//     curr->next = NULL;
//     curr->previous = NULL;
//     delete curr;
//     }
// }

// int main()
// {
//     Node *newNode = new Node(1);
//     Node *head = newNode, *tail = newNode;
//     insertAtHead(head, tail, 5);
//     insertAtTail(head, tail, 10);
//     insertAtTail(head, tail, 15);
//     insertAtTail(head, tail, 125);
//     print(head,tail);
//     cout << endl << endl;
//     deleteNode(head,tail,4);
//     print(head,tail);

//     return 0;
// }


// Circular Linked List

class Node{
public:
int data;
Node* next;

Node(int value): data(value),next(nullptr){

}

~Node(){
    int value = this->data;
    if(this->next != NULL){
        delete this->next;
        this->next = NULL;
    }
    cout << "Memory free of " << value << endl;
}
};

void insertAtHead(Node* &head,Node* &tail,int d){

    // Creating a new node
    Node* newNode = new Node(d);
    newNode->next = head;
    head->next = newNode;
    head = newNode;
}
void insertAtTail(Node* &head,Node* &tail,int d){

    Node* newNode = new Node(d);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;

}
void insertAtPosition(){

}
void deleteNode(){
    
}
void print(Node* &head,Node* &tail){

    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp =  temp->next;

    }while(temp!=head);
    cout << endl;
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data; 
}

int main(){
    
    Node* newNode = new Node(3);
    Node* head = newNode,*tail = newNode;
    insertAtHead(head,tail,2);
    insertAtTail(head,tail,5);
    print(head,tail);
    return 0;
}
// Reverse Linked List

#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;


    node(int val): data(val),next(nullptr){};

};

void insertAtHead(node* &head,node* &tail, int d){
    if(head == nullptr){
        node* newNode = new node(d);
        head = newNode;
        tail = newNode;
        return;
    }
    node* newNode = new node(d);
    newNode->next = head;
    head = newNode;
}
// iterative
node* reverseLL(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* prev = nullptr;
    node* curr = head;
    node* forward = NULL;

    while(curr!=NULL){
        forward = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}


// recursively
void reverseLL(node* &head, node* curr,node* prev){

    // base case
    if(curr == NULL){
        head = prev;
        return;
    }
    reverse(head,curr -> next,curr);
    curr->next = prev;
}



void printLL(node* head, node* tail){
    node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Head: " << head->data << " ";
    cout << "Tail: " << tail->data <<  " ";
}

int main(){
    node* head = nullptr,*tail = nullptr;
    insertAtHead(head,tail,55);
    insertAtHead(head,tail,45);
    insertAtHead(head,tail,35);
    insertAtHead(head,tail,25);
    insertAtHead(head,tail,15);
    printLL(head,tail);
    return 0;
}

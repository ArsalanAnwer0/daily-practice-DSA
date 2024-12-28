#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

// implementation of linked list

class node{
	public:
	int data;
	node* next;
	
	// constructor
	node(int value): data(value), next(nullptr){
		
	}
	
};
// inserting node at head

void insertAtHead(node* &head,node* &tail,int d){	
	if(head ==  nullptr){
	node* newNode = new node(d);
	head = tail = newNode;
	return;
	}
	node* newNode = new node(d);
	newNode->next = head;
	head= newNode;
}
void insertAtTail(node* &head,node* &tail,int d){
	if(head == nullptr){	
		node* newNode = new node(d);
		head = tail = newNode;
		return;
	}
	node* newNode = new node(d);
	tail->next = newNode;
	tail = newNode;
}
void insertAtPosition(node* &head,node* &tail, int position, int d){
        if(head == nullptr){
                node* newNode = new node(d);
                head = tail = newNode;
                return;
        }
	// if we are inserting at first position
	else if(position == 1){
	insertAtHead(head,tail,d);
	return;
	}
	// case where we are inserting at middle or at last node
	node* temp = head;
	int count = 1;
	while(count < position - 1){
		count++;
		temp = temp->next;
	}
	// Now we are where we want to insert
	node* newNode = new node(d);
	if(temp ->next == nullptr){
	tail = newNode;
	}
	newNode->next = temp->next;
	temp->next = newNode;
 }
// deleting node in LL
void deleteLL(node* &head,node* &tail,int position){
	if(head == nullptr){
	cout << "Nothing to delete! " << endl;
	return;
	}
	
}
// printing linked list
void printLL(node* head,node* tail){
	node* temp = head;
	while(temp){
	cout << temp->data << " ";
	temp = temp->next;
	}
	cout << endl << "Head: " << head->data << endl;
	cout << "Tail: " << tail->data << endl;
}
// 
int main(){
	node* head = nullptr,*tail = nullptr;
	insertAtHead(head,tail,5);
	insertAtTail(head,tail,10);
	insertAtTail(head,tail,15);
	insertAtTail(head,tail,20);
	insertAtPosition(head,tail,2,99);
	printLL(head,tail);
	return 0;
}

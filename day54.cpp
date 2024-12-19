// Again same practice all over again
// Linked List
// Stack
// Queue
// Tree
// BST
// Heap
// Graph
// DFS and BFS
// HashMaps

#include<iostream>
//#include<stack>
#include<queue>
#include<vector>
#include<unordered_map>
#include<utility>

using namespace std;

class node{
public:
int data;
node* next;

// constructor

node(int value): data(value),next(nullptr){}


// destructor

~node(){
        int value = this->data;
        if(this->next != nullptr){     
        delete this->next;
        this->next = nullptr;
        }
        cout << "Memory free of " << value << endl;
}

};




// how to insert at head

void insertAtHead(node* &head,node* &tail,int d){
	// if we are inserting in an empty linked list
	if(head == nullptr){	
	node* newNode = new node(d);
	head = tail = newNode;
	return;
	}
	// if linked list is not empty	
	node* newNode = new node(d);
	newNode->next = head;
	head = newNode;
	}
void insertAtTail(node* &head,node* &tail, int d){
	if(tail == nullptr){	
	node* newNode = new node(d);
	head = tail = newNode;
	return;
	}
	node* newNode = new node(d);
	tail->next = newNode;
	tail = newNode;
	}
void insertAtAnyPosition(node* &head,node* &tail,int pos,int d){
	// if we have to insert at 1 position
	if(pos ==  1){	
	insertAtHead(head,tail,d);
	return;
	}
	int count = 1;
	node* temp = head;
	while(count < pos){
	count ++;
	temp = temp->next;
	}
	node* newNode = new node(d);
	// checking if we are inserting at last node
	if(temp->next == nullptr){	
	tail = newNode;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	}
void deleteNode(node* &head,node* &tail,int pos){	
	// we will be doing the same thing we did in the insert position function
	// just that we will be writing our own destructor
	if(pos == 1){	
	node* temp = head;
	head = head->next;
	temp -> next = nullptr;
	delete temp;
	return;
	}
	int count = 1;
	node* curr = head;
	node* prev = curr;
	while(count < pos - 1){
	prev = curr;
	curr = curr -> next;
	count ++;
	}
	// when we come here we know where to delete so 
	// lets first check if we are deleting the last node
	if(curr -> next == nullptr){	
		tail = prev;	
	} 
	// this is where we delete the middle or last element
	prev->next = curr->next;
	curr -> next = nullptr;
	delete curr;	
}
void printLL(node* head,node* tail){	
	cout << "Printing Linked List: ";
	node* temp = head;
	while(temp!=nullptr){	
	cout << temp->data << " ";
	temp = temp->next;
	}
	cout << endl;
	cout << "Head: " << head->data << endl;	
	cout << "Tail: " << tail->data <<  endl;
}
// implementation of stacks
class stack{
public:
int* arr;
int size;
int top;

// constructor
stack(int size){	
this->size = size;
top = -1;
arr = new int[size];
}
// 4 methods: push,pop,isEmpty,peek
void push(int element){
	if(top < size - 1){
	top++;
	arr[top] = element;	
	}
	else{
	cerr << "Stack overflow! " << endl;
	}
	}
void pop(){
	if(!isEmpty()){	
	// this wil not remove the element but it will just decrease the size so we cannot access it
	top --;
	}
	else{	
	cerr << "Stack is empty " << endl;
	}
}
void peek(){	
	if(!isEmpty()){
	cout << arr[top] << " ";
	}
	else{	
	cerr << "Stack is empty! ";
	}
}
bool isEmpty(){	
	if(top == -1){	
	return true;
	}
	else{	
	return false;
	}
}
};
// queue implementation
class queue2{
public:
	int* arr;
	int front,rear,size;
// constructor
queue2(int size){
	this->size = size;
	rear = front = 0;
	arr = new int[size];
	}	
// 4 methods: enqueue,dequeue,front,isEmpty
void push(int element){
	if(rear != size){	
	arr[rear] = element;
	rear++;
	}
	else{
	cerr << "queue is full!";
	}	
}
void pop(){	
	if(rear > 0){
		arr[front] = -1;
		front++;
	}
	else{	
	cerr << "Queue is empty! ";
	}
}
void frontFunction(){	
	if(rear>0){	
	cout << arr[front];
	}
	else{	
	cerr << "Queue is empty! ";
	}
}
bool isEmpty(){
	if(rear == front){
	return true;		
	}
	else{	
	return false;
	}	
	}
};
// Main Data structures

// Traversals
class tree{
public:
int data;
tree* left,* right;

// constructor
tree(int value): data(value), left(nullptr), right(nullptr){	
}
};
// how to create a tree
// i) iteratively
// ii) recursively

tree* iterative(){
int rootValue,leftChild,rightChild;
queue<tree*> q;
cout << "Enter root value: ";
cin >> rootValue;
if(rootValue == -1){
 return nullptr;	
}
tree* root = new tree(rootValue);
q.push(root);

while(!q.empty()){
	tree* temp = q.front();
	q.pop();
	
	cout << "Enter left child value of " << temp->data << ": ";
	cin >> leftChild;
	if(leftChild != -1){
	temp -> left = new tree(leftChild);
	q.push(temp->left);
	}
	cout << "Enter right child value of " << temp->data << ": ";
	cin >> rightChild;
	if(rightChild != -1){	
	temp -> right = new tree(rightChild);
	q.push(temp->right);
	}
}
return root;
}

tree* recursive();
// lets create a tree using recursion
tree* helperFunction1(){	
tree* root = nullptr;
cout << "Enter root value: ";
root = recursive();
return root;
}
tree*  recursive(){	
	int d;
	cin >> d;
	if(d == -1){	
	return nullptr;
	}
	tree* root = new tree(d);
	cout << "Enter leftChild of " << root->data << ": ";
	root -> left = recursive();
	cout << "Enter rightChild of " << root->data << ": ";
	root -> right = recursive();

	return root;
	
}

void inOrder(tree* root){	

	if(root == nullptr){	
	return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
	
}
// BST 

// How to build a BST

// How to search in a BST

// How to delete in a BST

int main(){
	tree* root = nullptr;
	root = helperFunction1();
	inOrder(root);
	return 0;
}


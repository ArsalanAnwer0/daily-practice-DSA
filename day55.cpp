/*Todays session
revising the basics again
linked list
stacks
queue
tree
BST
Heap
Graph
Hash Maps
*/

#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<list>
#include<unordered_map>

using namespace std;


// Singly linked list
class node{
public:
int data;
node* next;
// constructor
node(int value): data(value), next(nullptr){
} 
// destructor
~node(){
int value = this->data;
if(this->next!=nullptr){
	delete this->next;
	this->next = nullptr;
	}
cout << "Memory free of " << value << endl;
}
};
void insertAtHead(node* &head,node* &tail,int data){
	if(head == nullptr){	
	node* newNode = new node(data);
	head = tail = newNode;
	return;
	}
	node* newNode = new node(data);
	newNode->next = head;
	head = newNode;	
}
void printLL(node* &head,node* &tail){	
	node* temp = head;
	while(temp!=nullptr){
	cout << temp->data << " ";
	temp =  temp->next;
	}
	cout << endl;
	cout << "Head: " << head->data << endl << "Tail: " << tail->data << endl;
}
void insertAtTail(node* &head,node* &tail,int d){
	if(tail == nullptr){	
	node* newNode = new node(d);
	head = tail = newNode;
	tail = newNode;
	return;
	}
	node* newNode = new node(d);
	tail->next = newNode;
	tail = newNode;
}	
void insertAtAnyPosition(node* &head,node* &tail, int pos, int data){
	if(pos == 0){
	insertAtHead(head,tail,data);
	return;
	}
	int count = 1;
	node* temp = head;
	while(count < pos - 1){
	count ++;
	temp = temp->next;
	}
	node* newNode = new node(data);
	if(temp->next == nullptr){
	tail = newNode;
	}
	newNode->next = temp->next;	
	temp->next = newNode;
	}
void deleteNode(node* &head,node* &tail,int pos){
	if(pos == 1){
	node *temp = head;
	head = temp->next;
	temp->next = nullptr;
	delete temp;
	return;
	}
	else if(head == tail){
		node* temp = head;
		temp->next = nullptr;
		delete temp;
		cout << "Linked list is now empty!" << endl;
		return;
	}
	else if(head == nullptr){	
		cout << "Nothing to delete, LL empty!";
		return;
	}
	else{
		node* curr = head;
		node* prev = nullptr;
		int count = 1;
		while(count < pos){	
		prev = curr;
		curr = curr->next;
		count ++;
		}
		if(curr->next == nullptr){	
		tail = prev;
		}
		prev->next = curr->next;
		curr->next =  nullptr;
		delete curr;	
	}
	}

class tree{
public:

int data;
tree* left,*right;

tree(int value): data(value),left(nullptr),right(nullptr) {}

};

// using iteration to create a tree

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
	cout << "Enter left child of " << temp->data << ": ";
	cin >> leftChild;
	if(leftChild!=-1){
	temp->left = new tree(leftChild);
	q.push(temp->left);
	}
	cout << "Enter right child of " << temp->data << ": ";
	cin >> rightChild;
	if(rightChild!=-1){	
	temp->right = new tree(rightChild);
	q.push(temp->right);
	}
	}
	return root;
}

// now lets do the same thing recusively
tree* recursively(){
	int d;
	cin >>  d;
	if(d == -1){
	return nullptr;
	}
	tree* root = new tree(d);
	cout << "Enter left child of " << root->data << ": ";
	root->left = recursively();
	cout << "Enter right chlid of " << root->data << ": ";
	root->right = recursively();
	return root;
}
// traversal
void inOrder(tree* root){
	if(root == nullptr){
	return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
	}
// BST
tree* BST(tree* root, int value);
// Writing Helper function
tree* helperFunction(tree* root){
	int value,childValue;
	cout << "Enter root value: ";
	cin >> value;
	if(value != -1){
	root = BST(root,value);
	while(true){	
		cout  << "Enter the child value : ";	
		cin >> childValue;
		if(childValue != -1){
		root = BST(root,childValue);
		}
		else{
		break;
		}
	}
	}
	return root;
	}
// How we can insert in a Binary Search Tree
tree* BST(tree* root, int value){
	// if user enters -1
	if(value == -1){	
	return nullptr;

	}
	// if we get to the point where root is nullptr
	else if(root == nullptr){
	return new tree(value);
	}

	// searching where to insert
	if(value < root->data){
	root->left = BST(root->left,value);
	}
	else if(value > root->data){
	root->right = BST(root->right,value);
	}
	return root;
}
// how to search in a BST
tree* searchInBST(tree* root,int value){
	// if nothing was found
	if(root == nullptr){
	return nullptr;
	}
	// if we found the value
	if(value == root->data){
	return root;
	}
	// search for the element maybe it is in the lft or right sub tree
	if(root->data > value){
	return searchInBST(root->left,value);
	}
	if(root->data < value){
	return searchInBST(root->right,value);
	}
	return nullptr;
	}
// delete in BST
tree* deleteInBST(){
	
	}


int main(){
	int value=12;
	tree* root = nullptr;
	root = helperFunction(root);
	inOrder(root);
	tree* temp = searchInBST(root,value);
	if(temp!= nullptr){
	cout << endl << "Address: " << temp << endl;
	cout << "Value: " << temp->data << endl;
	}
	else{
	cout << endl << value << " Not found! " << endl;
	}
	return 0;
}

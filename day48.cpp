// today I will code for three hours straight Let me first get up and freshen up
// Linked List
// Stack 
// Queue not for integer but for integer type pointer
// Tree
// BST
// Heap
// Graph
// Hashmaps
#include<iostream>
#include<utility>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class node{
public:
int data;
node* next;
// constructor
node(int value): data(value), next(nullptr){}
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
// inserting at head
void insertAtHead(node* &head, node* &tail, int d){
if(head == nullptr){
	node* newNode = new node(d);
	head = tail = newNode;
	return;
	}	
node* newNode = new node(d);
newNode->next = head;
head = newNode;
}
// inserting at tail
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
// printing linked list
void printLL(node* head,node* tail){
node* temp = head;
while(temp!=nullptr){
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
cout << "Head: " << head->data << endl;
cout << "Tail: " << tail->data << endl;
}
// inserting at any position
void insertAtAnyPosition(node* &head,node* &tail, int pos, int d)
{
	if(pos==1){
	insertAtHead(head,tail,d);
	return;
	}
	node* temp = head;
	int count = 1;
	while(count < pos - 1){
	count ++;
	temp = temp->next;
	}
	node* newNode = new node(d);
	if(temp->next == nullptr){
	tail = newNode;	
	}
	newNode->next = temp->next;
	temp->next = newNode;
}
// deleting in a linked list
void deleteNode(node* &head,node* &tail, int pos){
if(pos == 1){
// if we are deleting head
node* temp = head;
head = temp->next;
temp->next = nullptr;
delete temp;
return;
}
// if we are deleting middle or last node
node* curr = head;
node* prev = nullptr;
int count = 1;
while(count < pos){
prev = curr;
curr=curr->next;
count++;
}
// if we are deleting last node
if(curr->next == nullptr){
tail = prev;
}
prev->next = curr->next;
curr->next = nullptr;
delete curr;
}
class stack{
public:
int* arr;
int top;
int size;
// constructor
stack(int size){
	this->size = size;
	arr = new int[size];
	top = -1;
}
// methods or functions
	// insertion
	void push(int element){
	if(top < size){
	top++;
	arr[top] = element;
	}
	else{
	cout << "Stack overflow! " << endl;
	}
	}
	// removing element from stack
	void pop(){
	if(top!=-1){
	top--;
	}
	else{
	cout << "Stack is empty!" << endl;
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
	void peek(){
	if(!isEmpty()){
	cout << "Top: " << arr[top] << endl;
	}
	else{
	cout << "Stack is empty! " << endl;
	}
}
};
// will be creating 
class tree{
public:
int data;
tree* left,*right;

// constructor
tree(int value): data(value),left(nullptr),right(nullptr){}


};

// iteratively
tree* iteratively(){
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
cout << "Enter left child of " << temp->data <<  ": ";
cin >> leftChild;
	if(leftChild !=-1){
	temp->left = new tree(leftChild);
	q.push(temp->left);
	}
	cout << "Enter right child " << temp->data << ": ";
	cin >> rightChild;
	if(rightChild!=-1){
	temp->right = new tree(rightChild);
	q.push(temp->right);	
	}
}	 
	return root;
}
tree* recursively(){
	int d;
	cin >> d;
	// base case
	if(d == -1)
	{
	return nullptr;	
	}
	tree* root = new tree(d);
	cout << "Enter left child of " << root->data << ": ";
	root->left = recursively();
	cout << "Enter right child of " << root->data << ": ";
	root->right = recursively();
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

tree* BST(tree* root,int value);

// lets see Binary Search Tree
// we will be using the same tree class for this
// helper function for BST
tree* helperFunction(){
tree* root = nullptr;
int rootValue,value;
cout << "Enter root value: ";
cin >> rootValue;
if(rootValue!=-1){
root = BST(root,rootValue);
while(true){
cout << "Enter child value: ";
cin >> value;
if(value!=-1){
root = BST(root,value);
}
else{
break;
}
}
}
return root;
}
tree* BST(tree* root, int value){

// base case
if(root == nullptr){
return new tree(value);
}

if(root->data > value){
root->left  = BST(root->left,value); 
}
if(root->data < value){
root->right = BST(root->right,value);
}
return root;
}
// searching in a BST
tree* searchBST(tree* &root,int value){
// base case
// what if element is not found
if(root == nullptr){
	return nullptr;
}
// we found the element we were looking for
if(root->data == value){
return root;
}
// searching for the element
if(root->data > value){
return searchBST(root->left,value);
}
if(root->data < value){
return  searchBST(root->right,value);
}
return root;
}
// finding inorder successor
tree* minValue(tree* root){
tree* temp = root;
while(temp->left != nullptr){
temp = temp->left;
}
return temp;
}
// deletion in BST
tree* deleteNodeBST(tree* &root,int value){
// if value is in BST
if(root == nullptr){
cout << "Value not found!" << endl;
return nullptr;
}
if(root->data == value){
// 0 child case
if(root->left == nullptr && root->right == nullptr)
{
delete root;
return nullptr;
}
// 1 child case
if(root->left != nullptr && root->right == nullptr){
tree* temp =  root->left;
delete root;
return temp;
}
if(root->left == nullptr && root->right != nullptr){
tree* temp = root->right;
delete root;
return temp;
}
// 2 child case
if(root->left != nullptr && root->right != nullptr){
int value = minValue(root->right) -> data;
root->data = value;
root->right = deleteNodeBST(root->right,value);
return root;
}
}
// searching for value
if(root->data > value){
root->left = deleteNodeBST(root->left,value);
}
if(root->data < value){
root->right = deleteNodeBST(root->right,value);
}
return root;
}
// lets code heap
class heap{
public:
int* arr;
int size;
int capacity;
heap(int capacity){
this->capacity = capacity;
arr = new int[capacity];
size = 0;
}
// building a max-heap method
void insertHeap(int element){
	size++;
	int index = size;
	arr[index] = element;
	
	while(index > 1){
	int parent = index / 2;
	if(arr[index] > arr[parent]){
	swap(arr[index],arr[parent]);
	index = parent;
	}
	else{
	// nothing to arrange
	break;	
	}
	}
}
void deleteInHeap(){
	// check if heap is not empty
	if(size==-1){
	cout << "Heap is empty! " << endl;
	return;
	}
	// the delete method delete just the root and rearranges
	arr[1] = arr[size];
	size--;

	int index = 1;
	while(index < size){
	int leftChild = 2*index;
	int rightChild = 2*index+1;
	int largest = index;
	if(arr[index] < arr[leftChild]){
	largest = leftChild;
	}
	if(arr[index] < arr[rightChild]){	
	largest = rightChild;
	}
	if(largest!=index){	
	swap(arr[largest],arr[index]);
	index = largest;
	}
	else{
	break;
	}
	}
	}
	void printHeap(){
	cout << "Printing Heap: ";
	for(int i=1;i<=size;i++){
	cout << arr[i] << " ";
	}
	cout << endl;
	}
};
#include <iostream>
using namespace std;

class Heap {
public:
    int* arr;
    int size;
    int capacity;

    // Constructor
    Heap(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }

    // Insert into max-heap
    void insertHeap(int element) {
        if (size >= capacity - 1) {
            cout << "Heap is full!" << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = element;

        while (index > 1) {
            int parent = index / 2;
            if (arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Delete root from the heap
    void deleteInHeap() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        // Replace root with last element
        arr[1] = arr[size];
        size--;

        // Reheapify
        int index = 1;
        while (index <= size) {
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            int largest = index;

            if (leftChild <= size && arr[largest] < arr[leftChild]) {
                largest = leftChild;
            }
            if (rightChild <= size && arr[largest] < arr[rightChild]) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(arr[largest], arr[index]);
                index = largest;
            } else {
                break;
            }
        }
    }

    // Heapify function for a specific index
    void heapify(int index) {
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int largest = index;

        if (leftChild <= size && arr[largest] < arr[leftChild]) {
            largest = leftChild;
        }
        if (rightChild <= size && arr[largest] < arr[rightChild]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapify(largest);
        }
    }

    // Heapify the entire heap (build-heap)
    void buildHeap() {
        for (int i = size / 2; i >= 1; i--) {
            heapify(i);
        }
    }

    // Heapsort implementation
    void heapsort() {
        buildHeap();
        int originalSize = size;
        for (int i = size; i > 1; i--) {
            swap(arr[1], arr[i]);
            size--;
            heapify(1);
        }
        size = originalSize;
    }

    // Print the heap
    void printHeap() {
        cout << "Heap elements: ";
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~Heap() {
        delete[] arr;
    }
};

int main() {
    Heap h(11); // Initialize heap with capacity of 10 elements
    h.insertHeap(3);
    h.insertHeap(5);
    h.insertHeap(10);
    h.insertHeap(1);
    h.insertHeap(8);
    h.printHeap();

    cout << "After deleting root: " << endl;
    h.deleteInHeap();
    h.printHeap();

    cout << "Heap sort in progress..." << endl;
    h.heapsort();
    h.printHeap();

    return 0;
}

// Linked List
// Stack
// Queue
// Tree
// BST
// Heap
// Graph
// Hash Map

#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>

using namespace std;


// implementing a singly linked list
class node{
    public:
    int data;
    node* next;

    // constructor
    node(int val): data(val),next(nullptr){}

};

void insertAtHead(node* &head,node* &tail, int d){
    if(head == nullptr){
        node* newNode = new node(d);
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        node* newNode = new node(d);
        newNode -> next = head;
        head = newNode;
    }
}

void insertAtTail(node* &head,node* &tail,int d){
    if(head == nullptr){
    node* newNode = new node(d);
    head = newNode;
    tail = newNode;
    return;
    }
    else{
        node* newNode = new node(d);
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtAnyPosition(node* &head,node* &tail, int pos, int d){
    if(head == nullptr){
    node* newNode = new node(d);
    head = newNode;
    tail = newNode;
    return;
    }
    else if(pos == 1){
        insertAtHead(head,tail,d);
        return;
    }
    node* temp =  head;
        int count = 1;
        
        while(count < pos - 1){
            count ++;
            temp = temp -> next;
        }
    
    node* newNode = new node(d);
    if(temp->next == nullptr){
        tail = newNode;
    }
    newNode->next = temp->next;
    temp->next =  newNode;
}

void printLL(node* head,node* tail){
    node*  temp =  head;
    cout << "Linked List: ";
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
}   

void reverseLL(node* head){
    node* prev = nullptr;
    node* curr = head;
    node* forward =  nullptr;
    
    while(curr){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
}

// Stack

class Stack{
    public:
    int* arr;
    int size;
    int top;

    Stack(int size){
        top = -1;
        cout << "Enter stack size:";
        cin >> size;
        this->size = size;
        arr = new int[size];
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack overflow!" << endl;

        }
    }
    void pop(){
        if(top >  1){
            top--;
        }
        else{
            cout << "Stack is empty!" << endl;
        }
    }
    bool isEmpty(){
        if(top == size){
            return true;
        }
        else{
            return false;
        }
    }
    void peek(){
        if(!isEmpty()){
            cout << arr[top] << " " << endl; 
        }
        else{
            cout << "Stack is empty" << endl;
        }
    }
};

// tree
class tree{
    public:
    int data;
    tree* leftChild,*rightChild;

    tree(int val): data(val),leftChild(nullptr),rightChild(nullptr){}
};

// building tree iteratively

tree* iterative(){
    int rootValue,leftValue,rightValue;
    queue<tree*> q;
    cout << "Enter root data: ";
    cin >> rootValue;
    if(rootValue == -1){
        return nullptr;
    }
    tree* root = new tree(rootValue);
    q.push(root);

    while(!q.empty()){
        tree* temp = q.front();
        q.pop();
        cout << "Enter left value of " << temp -> data << ": ";
        cin >> leftValue;
        if(leftValue!=-1){
            root->leftChild = new tree(leftValue);
            q.push(root->leftChild);
        }
        cout << "Enter right value of " << temp -> data << ": ";
        cin >> rightValue;
        if(rightValue != -1){
            root->rightChild = new tree(rightValue);
            q.push(root->rightChild);
        }
    }
    return root;
}

// building tree recursively

tree* recursive();

tree* recursiveHelper(tree* root){
    cout << "Enter root data : ";
    root = recursive();
    return root;
}

tree* recursive(){
    int d;
    cin >> d;
    if(d==-1){
        return nullptr;
    }
    tree* root = new tree(d);
    cout << "Enter left node of " << root->data << ": ";
    root->leftChild = recursive();
    cout << "Enter right node of " << root->data << ": ";
    root->rightChild =  recursive();

    return root; 
}

// tree traversals using recursion

void inOrder(tree* root){
    if(root == nullptr){
        return;
    }
    inOrder(root->leftChild);
    cout << root -> data << " ";
    inOrder(root->rightChild);
} 
void preOrder(tree* root){
    if(root == nullptr){
        return;
    }
    cout << root -> data << " ";
    inOrder(root->leftChild);
    inOrder(root->rightChild);
} 
void postOrder(tree* root){
    if(root == nullptr){
        return;
    }
    inOrder(root->leftChild);
    inOrder(root->rightChild);
    cout << root -> data << " ";
} 

// lets use tree class for BST

// creating a BST (inserting)

tree* BST(tree* &root, int val);

tree* helper(tree* &root){
    int value;
    cout << "Enter root data: ";
    cin >> value;
    if(value != -1){
        root = BST(root,value);
        while(value!=-1){
        root = BST(root,value);
        cout << "Enter child value: ";
        cin >> value;
    }
    }
    return root;
    }

tree* BST(tree* &root, int val){
    if(root == nullptr){
        return new tree(val);
    }
    if(root->data > val){
        root->leftChild = BST(root->leftChild,val);
    }
    if(root->data < val){
        root->rightChild = BST(root->rightChild,val);
    }
    return root;
}

// searching data address in BST

tree* Search(tree* &root,int d){

    if(root == nullptr){
        return root;
    }
    if(root->data == d){
        return root;
    }
    if(root->data < d){
        return Search(root->rightChild);
    }
    if(root -> data > d){
        return Search(root->leftChild);
    }
    return nullptr;
}

// Delete in BST

// minimum value in tree

tree* minValue(tree* root){
    tree* temp = root;
    while(temp->next !=  nullptr){
        temp = temp->left;
    }
    return temp;
}

tree* deleteBST(tree* &root, int value){
    
    if(root == nullptr){
        cout << "Nothing to delete!" << endl;
        return nullptr;
    }
    if(root->data == value){
        // 0 child
        if(root->leftChild == nullptr && root->rightChild == nullptr)
        {
            delete root;
            return nullptr;
        }
        // 1 child
            // left child
            if(root->leftChild != nullptr && root->rightChild == nullptr){
                tree* temp = leftChild;
                delete root;
                return temp;
            }
            // right child
            if(root->leftChild == nullptr && root->rightChild != nullptr){
                tree* temp = rightChild;
                delete root;
                return temp;
            }
        // 2 child   
        if(root->leftChild != nullptr && root->rightChild != nullptr){
            int min = minValue(root->right) -> data;
            root->data = min;
            root -> right = deleteBST(root->right,min);
        }
    }
    // search 
    if(root->data < value){
        root->rightChild = deleteBST(root->rightChild,value);
    }
    if(root->data > value){
        root->leftChild = deleteBST(root->leftChild,value);
    }
    return root;
}

// Heap

class heap{
    public:
    int* arr;
    int size;

    heap(){
        size = 0;
        arr = new int[size];
    }
    // inserting in heap
    void insertHeap(int val){
    // step 1: insert val at last
    size++;
    int index = size;
    arr[index] = val;

    // step 2: take inserted element to its correct position

    while(index > 1){
        int parent = index/2;
        if(arr[parent] < arr[index]){
            swap(arr[parent],arr[index]);
            index = parent;
        }
        else{
            return;
        }
    }
    }

    // deleting in heap

    void deleteHeap(){
        // step 1: swap the root element with last;
        arr[1] = arr[size];
        size--;
        // step 2: take 1 index element to its right position
        int index = 1;
        while(index <=size){
            int largest = index;
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;

            if(leftChild < size && arr[largest] < arr[leftChild]){
                largest = leftChild;
            }
            if(rightChild < size && arr[largest] < arr[rightChild]){
                rightChild = rightChild;
            }
            if(largest != index){
                swap(arr[largest],arr[index]);
                index =  largest;
            }
            else{
                return;
            }
        }
    }

// heapify function
void heapify(int index) {
    int largest = index;
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;

    if (leftChild < size && arr[largest] < arr[leftChild]) {
        largest = leftChild;
    }
    if (rightChild < size && arr[largest] < arr[rightChild]) {
        largest = rightChild;
    }
    if (largest != index) {
        swap(arr[largest], arr[index]);
        heapify(largest);
    }
}

// build heap
void buildHeap() {
    for (int i = size / 2; i >= 1; i--) {  // Start from the last non-leaf node
        heapify(i);
    }
}

// heap sort helper function
void heapSort() {
    while (size > 1) {
        swap(arr[1], arr[size]); // Swap the root with the last element
        size--;                  // Reduce the heap size
        heapify(1);              // Re-heapify the root
    }
}

// heap sort driver
void heapSortHelper() {
    buildHeap();
    int originalSize = size; // Save the original size
    heapSort();
    size = originalSize; // Restore the size
}

};

int main(){

    tree* root = nullptr;
    root = helper(root);
    Search(root,5);
    inOrder(root);

    return 0;
}
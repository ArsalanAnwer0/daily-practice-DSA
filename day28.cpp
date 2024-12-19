#include <iostream>
#include <vector>
using namespace std;

// Linear Searching
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
// Binary Search
int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            end = mid - 1;
        }
        if (arr[mid] > key)
        {
            start = mid + 1;
        }
    }
    return -1;
}
// Tree
class tree
{
public:
    int data;
    tree *left, *right;

    tree(int value) : data(value), left(nullptr), right(nullptr) {}
};
// queue
class queue
{
public:
    int front, rear;
    tree **arr;
    int size;

    queue(int size)
    {
        this->size = size;
        arr = new tree *[size];
        front = rear = 0;
    }
    void push(tree *element)
    {

        if (rear == size)
        {
            cerr << "Queue is full!" << endl;
        }
        else
        {
            arr[rear] = element;
            rear++;
        }
    }
    bool empty()
    {
        if (rear == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    tree *frontFunction()
    {
        if (empty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            return arr[front];
        }
        return nullptr;
    }
    void pop()
    {
        if (!empty())
        {
            arr[front] = nullptr;
            front++;
        }
        else
        {
            cerr << "Queue is empty!" << endl;
        }
    }
};
// functions for Binary Tree
// creating a tree iteratively
tree *iterative()
{
    int rootValue, leftChild, rightChild;
    queue q(100);
    cout << "Enter root value: ";
    cin >> rootValue;
    if (rootValue == -1)
    {
        return nullptr;
    }
    tree *root = new tree(rootValue);
    q.push(root);

    while (!q.empty())
    {
        tree *temp = q.frontFunction();
        q.pop();

        cout << "Enter left child of " << temp->data << ": ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            temp->left = new tree(leftChild);
            q.push(temp->left);
        }
        cout << "Enter right child of " << temp->data << ": ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            temp->right = new tree(rightChild);
            q.push(temp->right);
        }
    }
    return root;
}
// creating a tree using recursion
tree *recursiveHelper()
{
    cout << "Enter root node: ";
    return recursion();
}
tree *recursion()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }
    tree *root = new tree(d);

    cout << "Enter left child value of " << root->data << ": ";
    root->left = recursion();
    cout << "Enter right child value of " << root->data << ": ";
    root->right = recursion();

    return root;
}
// BST
// helping function to create a BST
tree *BSThelper()
{
    tree *root = nullptr;
    int rootValue, value;
    cout << "Enter root value: ";
    cin >> rootValue;
    if (rootValue != -1)
    {
        root = BST(root, rootValue);
        while (true)
        {
            cout << "Enter child value: ";
            cin >> value;
            if (value != -1)
            {
                root = BST(root, value);
            }
            else
            {
                break;
            }
        }
    }
    return root;
}
tree *BST(tree *root, int value)
{
    if (root == nullptr)
    {
        return root = new tree(value);
    }
    if (root->data < value)
    {

        root->right = BST(root->right, value);
    }
    if (root->data > value)
    {
        root->left = BST(root->left, value);
    }
    else
    {
        cout << "Duplicates not allowed!" << endl;
    }
    return root;
}

// Heap
class heap
{
public:
    int *arr;
    int capacity, size;

    heap(int capacity) : capacity(capacity)
    {
        arr = new int[capacity];
        size = 0;
    }

    void maxHeap(int element)
    {
        if (size >= capacity)
        {
            cerr << "Heap is full!" << endl;
            return;
        }
        // insert index
        size++;
        arr[size] = element;
        int index = size;

        // taking index to its right position
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }
    // deleting in a heap
    // note that we only delete root node of a heap
    void deleteNode()
    {

        // deleting root node;
        arr[1] = arr[size];
        size--;

        // taking new root node to its right position
        int index = 1;
        while (index <= size / 2)
        {
            int largest = index;
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            if (leftChild < size && arr[index] < arr[leftChild])
            {
                largest = leftChild;
            }
            if (rightChild < size && arr[index] < arr[rightChild])
            {
                largest = rightChild;
            }
            if (largest != index)
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }
    // heapify
    void heapifyHelper(int arr[], int size)
    {

        for (int i = size / 2; i > 0; i--)
        {

            heapify(arr, size, i);
        }
    }

    void heapify(int arr[], int size, int index)
    {

        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int largest = index;

        if (leftChild <= size && arr[index] < arr[leftChild])
        {
            largest = leftChild;
        }
        if (rightChild <= size && arr[index] < arr[rightChild])
        {
            largest = rightChild;
        }
        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(arr, size, largest);
        }
    }
    void heapSort(int arr[], int size)
    {

        heapifyHelper(arr, size);

        for (int i = size; i > 1; i--)
        {
            swap(arr[i], arr[1]);
            size--;
            heapify(arr, size, 1);
        }
    }
};
// Linked List
class node
{
public:
    int data;
    node *next;

    node(int value) : data(value), next(nullptr) {}
    ~node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete this->next;
            this->next = nullptr;
        }
        cout << "Memory free of  " << value << endl;
    }
    void insertAtHead(node *&head, node *&tail, int d)
    {
        if (head == nullptr)
        {
            node *newNode = new node(d);
            head = tail = newNode;
            newNode->next = nullptr;
            return;
        }

        node *newNode = new node(d);
        newNode->next = head;
        head = newNode;
    }
    void insertAtAnyPosition(node *&head, node *&tail, int pos, int d)
    {
        if (pos == 1)
        {
            insertAtHead(head, tail, d);
            return;
        }
        int count = 1;
        node *temp = head;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        node *newNode = new node(d);
        if (temp->next == nullptr)
        {
            tail = newNode;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void deleteNode(node *&head, node *&tail, int pos)
    {
        if (pos == 1)
        {
            node *temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            return;
        }
        int count = 1;
        node *curr = head;
        node *prev = nullptr;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (curr->next == nullptr)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }
};
// Stack
class stack{
    public:
    int *arr;
    int top;
    int size;

    stack(int size):size(size){
        arr = new int[size];
        top = -1;
    }

    void push(int element){ 
        
        
    }
    void pop(){

    }
    bool isEmpty(){

    }
    void top(){

    }


};
// Queue
// graph representation
// BFS & DFS

int main()
{
}

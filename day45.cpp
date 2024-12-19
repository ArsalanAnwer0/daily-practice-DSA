// Hi Today I will again be doing all the concepts of DSA I know so far
// Linked List
//  Singly/Doubly/Circular
// Stacks
// Queue
// Tree
// BST
// Heap
// Graph
// HashMap
// Linear/Binary Search

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *next, *prev;

    // constructor
    node(int d)
    {
        this->data = d;
        next = prev = nullptr;
    }

    // destructor
    ~node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete this->next;
            this->next = nullptr;
        }
        cout << "Memory free of " << value << endl;
    }
};
void insertAtHead(node *&head, node *&tail, int data)
{
    if (head == nullptr)
    {
        node *newNode = new node(data);
        head = tail = newNode;
        return;
    }
    node *newNode = new node(data);
    newNode->next = head;
    newNode->prev = nullptr;
    head = newNode;
}
void insertAtTail(node *&head, node *&tail, int data)
{
    if (tail == nullptr)
    {
        node *newNode = new node(data);
        tail = head = newNode;
        return;
    }
    node *newNode = new node(data);
    tail->next = newNode;
    newNode->next = nullptr;
    tail = newNode;
}
void printLL(node *head, node *tail)
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
void insertAtAnyPosition(node *&head, node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *newNode = new node(data);
    if (temp->next == nullptr)
    {
        newNode->prev = tail;
        tail = newNode;
        temp->next = newNode;
        return;
    }
    else
    {
        temp->next->prev = newNode;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
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
class stack
{
public:
    int *arr;
    int top;
    int size;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cerr << "Stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top != -1)
        {
            top--;
        }
        else
        {
            cerr << "Stack is empty!" << endl;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void peek()
    {
        if (!isEmpty())
        {
            cout << arr[top] << endl;
        }
        else
        {
            cerr << "Stack is empty!" << endl;
        }
    }
};
// class queue
// {
// public:
//     int *arr;
//     int size;
//     int rear;
//     int front;

//     queue(int size)
//     {
//         this->size = size;
//         front = rear = 0;
//         arr = new int[size];
//     }

//     void push(int element)
//     {
//         if (rear != size)
//         {
//             arr[rear] = element;
//             rear++;
//         }
//         else
//         {
//             cerr << "queue is full!" << endl;
//         }
//     }
//     void pop()
//     {
//         if (front != rear)
//         {
//             front++;
//         }
//         else
//         {
//             cerr << "Queue is empty!" << endl;
//         }
//     }
//     bool isEmpty()
//     {
//         if (front == rear)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     void frontFunction()
//     {
//         if (!isEmpty())
//         {
//             cout << arr[rear-1] << endl;
//         }
//         else
//         {
//             cerr << "queue is empty!" << endl;
//         }
//     }
// };
class tree
{
public:
    int data;
    tree *left, *right;

    tree(int value) : data(value), left(nullptr), right(nullptr)
    {
    }
};

// creating a tree iteratively
tree *iteratively()
{
    int rootValue, leftChild, rightChild;
    queue<tree *> q;
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
        tree *temp = q.front();
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
// creating a tree recursively
tree *recursive()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }
    tree *root = new tree(d);
    cout << "Enter left child of " << root->data << ": ";
    root->left = recursive();
    cout << "Enter right child of " << root->data << ": ";
    root->right = recursive();

    return root;
}
// creating recursive helper
tree *recursiveHelper()
{
    tree *root = nullptr;
    cout << "Enter root node: ";
    root = recursive();
    return root;
}

void inOrder(tree *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
// inserstion in a BST
tree *insertBST(tree *root, int value)
{
    if (root == nullptr)
    {
        return new tree(value);
    }
    if (root->data > value)
    {
        root->left = insertBST(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = insertBST(root->right, value);
    }
    else
    {
        cout << "Duplicates not allowed!" << endl;
    }
    return root;
}
// helper function to creat a BST
tree *BSThelper()
{
    tree *root = nullptr;
    int value, childValue;
    cout << "Enter root value: ";
    cin >> value;
    if (value != -1)
    {
        root = insertBST(root, value);
        while (true)
        {
            cout << "Enter child node: ";
            cin >> childValue;
            if (childValue != -1)
            {
                root = insertBST(root, childValue);
            }
            else
            {
                break;
            }
        }
    }
    return root;
}
// searching in a BST
bool search(tree *root, int value)
{

    // nothing was found
    if (root == nullptr)
    {
        return false;
    }
    // key value found
    if (root->data == value)
    {
        return true;
    }
    // we want to search for the value
    if (root->data > value)
    {
        return search(root->left, value);
    }
    if (root->data < value)
    {
        return search(root->right, value);
    }
    return false;
}
tree *minValue(tree *root)
{
    tree *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}
// delete in a BST
tree *deletion(tree *&root, int value)
{
    // base cases
    if (root == nullptr)
    {
        cerr << "Value does not exist" << endl;
        return nullptr;
    }
    if (root->data == value)
    {
        // 0 child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // 1 child
        // left
        if (root->left != nullptr && root->right == nullptr)
        {
            tree *temp = root->left;
            delete root;
            return temp;
        }
        // right
        if (root->left == nullptr && root->right != nullptr)
        {
            tree *temp = root->right;
            delete root;
            return temp;
        }
        // two child
        if (root->left != nullptr && root->right != nullptr)
        {
            int temp = minValue(root->right)->data;
            root->data = temp;
            root->right = deletion(root->right, temp);
            return root;
        }
    }
    // searching for the value
    if (root->data > value)
    {
        root->left = deletion(root->left, value);
    }
    if (root->data < value)
    {
        root->right = deletion(root->right, value);
    }
    return root;
}
// heap
class heap
{
public:
    int *arr;
    int capacity;
    int size;

    heap(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        int size = 0;
    }
    void insert(int element)
    {
        size++;
        arr[size] = element;
        int index = size;

        while (true)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {

                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }
    void deleteHeap()
    {
        // inserting last element in root node
        arr[1] = arr[size];
        size--;

        // taking new root element to its right position
        int index = 1;
        while (true)
        {
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            int largest = index;

            if (leftChild < size && arr[index] < arr[leftChild])
            {
                largest = leftChild;
            }
            if (rightChild < size && arr[index] < arr[rightChild])
            {
                largest = rightChild;
            }
            if (index != largest)
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
};
// Graph
// Adjancency List representation in graph
// DFS
// BFS
// Prims Algorithms (Minimum Spanning Tree)
// Kruskals Algorithms (Minimum Spanning Tree)
// Dikjstras Algorithm (Shortest Path finding)
// Bellman Ford
// hashmaps
// insertion deletion searching O(1) -> constant time
// linear probing/ quadratic probing
// chaining problems 
// longest common subsequence
// lowest common ancestor


int main()
{
    tree *root = nullptr;
    root = BSThelper();
    inOrder(root);
    root = deletion(root, 15);
    cout << endl;
    inOrder(root);
    return 0;
}
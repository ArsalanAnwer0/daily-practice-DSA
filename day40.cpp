// Learning
// linked list
// stack
// queue
// binary tree
// binary search tree
// heap
// graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// implementing singly linked list
class node
{
public:
    int data;
    node *next;

    node(int value) : data(value), next(nullptr)
    {
    }
    // my destructor
    ~node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete this->next;
            this->next = nullptr;
        }
        cout << endl
             << "Memory free of " << value << endl;
    }
};
void insertAtHead(node *&head, node *&tail, int d)
{
    if (head == nullptr)
    {
        node *newNode = new node(d);
        tail = head = newNode;
        return;
    }
    node *newNode = new node(d);
    newNode->next = head;
    head = newNode;
}
void insertAtTail(node *&head, node *&tail, int d)
{
    if (tail == nullptr)
    {
        node *newNode = new node(d);
        tail = head = newNode;
        return;
    }
    node *newNode = new node(d);
    tail->next = newNode;
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
    cout << endl
         << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
}

// sorting a linked list in ascending order

void sorting(node *&head)
{
    node *temp = head;
    node *temp2 = head->next;

    while (temp != nullptr)
    {

        while (temp2 != nullptr)
        {

            if (temp->data > temp2->data)
            {
                int tempData = temp->data;
                temp->data = temp2->data;
                temp2->data = tempData;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
        if (temp->next != nullptr)
        {
            temp2 = temp->next;
        }
        else
        {
            return;
        }
    }
}

void insertAtPosition(node *&head, node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    // we have reached the correct place to insert
    // inserting at last position
    node *newNode = new node(d);
    if (temp->next == nullptr)
    {
        tail = newNode;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// deleting node from a linked list
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
    // delete middle or last nodes
    int count = 1;
    node *prev = nullptr;
    node *curr = head;
    while (count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    // if we are at last node
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
    int size;
    int top;
    stack(int size)
    {
        this->size = size;
        arr = new int[100];
        top = -1;
    }
    // methods push,pop,isEmpty,peek
    void push(int element)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cerr << "Stack overflow! " << endl;
        }
    }
    void pop()
    {
        if (top > -1)
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
        if (top != -1)
        {
            cout << arr[top] << endl;
        }
        else
        {
            cerr << "Stack is empty!" << endl;
        }
    }
};
class queue1
{
public:
    int *arr;
    int front, rear, size;
    queue1(int size)
    {
        front = rear = 0;
        arr = new int[100];
    }
    // methods push, pop, isempty, peek

    void push(int element)
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
    void pop()
    {
        if (front == rear)
        {
            cerr << "Queue is empty!" << endl;
        }
        else
        {
            front++;
        }
    }
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void frontElement()
    {
        if (front != rear)
        {
            cout << arr[rear - 1] << endl;
        }
        else
        {
            cerr << "Queue is empty!" << endl;
        }
    }
};
class tree
{
public:
    int data;
    tree *left, *right;

    tree(int value) : data(value), left(nullptr), right(nullptr)
    {
    }
};
// using iterative way to build tree
tree *iterative()
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
// creating a tree using recursion
tree *recursive()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }
    tree *root = new tree(d);
    cout << "Enter left child value of " << root->data << ": ";
    root->left = recursive();
    cout << "Enter right child value of " << root->data << ": ";
    root->right = recursive();
    return root;
}
// traversing the tree using inOrder traversal LNR
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
tree *BST(tree *root, int value)
{
    if (root == nullptr)
    {
        return new tree(value);
    }
    if (root->data > value)
    {
        root->left = BST(root->left, value);
    }
    if (root->data < value)
    {
        root->right = BST(root->right, value);
    }
    return root;
}
// how to create a BST iteratively
tree *helper()
{
    tree *root = nullptr;
    int value;
    cout << "Enter root value: ";
    cin >> value;
    if (value != -1)
    {
        root = BST(root, value);
        while (true)
        {
            cout << "Enter value:";
            cin >> value;
            if (value == -1)
                break;
            root = BST(root, value);
        }
    }
    else
    {
        return nullptr;
    }
    return root;
}
// how do we search in a BST
bool search(tree *root, int value)
{
    // if root is nullptr nothing to search tree is empty
    if (root == NULL)
    {
        return false;
    }
    if (root->data == value)
    {
        return true;
    }
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

// finding minvalue
tree *minValue(tree *root)
{
    tree *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return root;
}

// how do we delete in a BST
tree *deleteInBST(tree *root, int value)
{

    // checking if root is nullptr if so we will return nullptr
    if (root == nullptr)
    {
        return nullptr;
    }
    // if root data is equal to value
    if (root->data == value)
    {
        // check how many nodes are there and on which side before deleting
        // if it is a child node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // if 1 node is there but on which side?
        if (root->right != nullptr && root->left == nullptr)
        {
            tree *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != nullptr && root->right == nullptr)
        {
            tree *temp = root->left;
            delete root;
            return temp;
        }
        // if node has two childs
        if (root->right != nullptr && root->left != nullptr)
        {
            // learn the concept of inorder predecessor and inorder successor
            int value = minValue(root->right)->data;
            root->data = value;
            root->right = deleteInBST(root->right, value);
        }
    }
    if (root->data > value)
    {
        root->left = deleteInBST(root->left, value);
    }
    if (root->data < value)
    {
        root->right = deleteInBST(root->right, value);
    }
    return root;
}
// we represent heap in the form of array
class heap
{
public:
    int *arr;
    int capacity;
    int size;
    heap(int capacity)
    {
        arr = new int[100];
        this->capacity = capacity;
        size = 0;
    }

    void insertion(int element)
    {
        // inserted element at the end of the array
        size++;
        arr[size] = element;
        int index = size;

        // taking element to its right position.
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
    void deleteHeap(int index)
    {

        // deleting root node
        arr[1] = arr[size];
        size--;

        // taking root element to its position
        int temp = 1;
        while (temp < size)
        {
            // we delete the root element
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;
            // Check if the left child exists and is greater than the current largest
            if (left < size && arr[left] > arr[largest])
            {
                largest = left;
            }

            // Check if the right child exists and is greater than the current largest
            if (right < size && arr[right] > arr[largest])
            {
                largest = right;
            }

            // If the largest is not the current index, swap and continue
            if (largest != index)
            {
                swap(arr[index], arr[largest]);
                index = largest; // Move down to the largest child's index
            }
            else
            {
                return; // If the heap property is satisfied, exit
            }
        }
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h1(5);
    h1.insertion(10);
    h1.insertion(20);
    h1.insertion(30);
    h1.insertion(40);
    h1.insertion(50);
    h1.printHeap();
    return 0;
}
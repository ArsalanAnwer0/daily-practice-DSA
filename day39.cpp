#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class list
{
public:
    int data;
    list *next;

    list(int value) : data(value), next(nullptr) {}
    ~list()
    {
        int val = this->data;
        if (this->next != nullptr)
        {
            delete this->next;
            this->next = nullptr;
        }
        cout << "Memory free of " << val << endl;
    }
};
class tree
{
public:
    int data;
    tree *left, *right;

    tree(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BST
{
public:
    int data;
    BST *right, *left;

    BST(int value) : data(value), right(nullptr), left(nullptr) {}
};
class graph
{
public:
    int V; // number of vertices
    vector<vector<int>> adj;

    graph(int v) : V(v)
    {

        adj.resize(v);
    }
};
class heap
{
public:
    int *arr;     // Array to store heap elements
    int capacity; // Maximum size of the heap
    int size;     // Current size of the heap

    heap(int capacity) // Constructor
    {
        arr = new int[capacity];   // Allocate memory for the heap
        this->capacity = capacity; // Set the maximum capacity
        this->size = 0;            // Initialize size to 0
    }

    ~heap() // Destructor to free allocated memory
    {
        delete[] arr; // Free the allocated memory
    }

    void insertInHeap(int element); // Function to insert an element
    void displayHeap();             // Function to display the heap
    void deleteHeap();
    void heapify(int arr[], int size, int i);
};

// Graph
void addEdge(graph &g, int v, int w);
void display(graph &g);
void BFS(graph &g, int start);
void DFS(graph &g, int start);
// BST
BST *insertBST(BST *root, int value);
BST *helperFunction();
BST *deleteNode(BST *&root, int val);
BST *minValue(BST *root);
// tree
tree *iterative();
tree *recursively();
void inOrder(BST *root);
// linked list
void insertAtHead(list *&head, list *&tail, int d);
void printList(list *head, list *tail);
void insertAtTail(list *&head, list *&tail, int d);
void insertAtPosition(list *&head, list *&tail, int pos, int d);
void deleteNode(list *&head, list *&tail, int pos);
int main()
{
    heap h(5);
    h.insertInHeap(10);
    h.insertInHeap(20);
    h.insertInHeap(30);
    h.insertInHeap(40);
    h.insertInHeap(50);
    h.displayHeap();
}
void printList(list *head, list *tail)
{
    list *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
}
void insertAtHead(list *&head, list *&tail, int d)
{
    if (head == nullptr)
    {
        list *newNode = new list(d);
        tail = newNode;
        head = newNode;
        return;
    }
    list *newNode = new list(d);
    newNode->next = head;
    head = newNode;
}
void insertAtTail(list *&head, list *&tail, int d)
{
    if (tail == nullptr)
    {
        list *newNode = new list(d);
        tail = newNode;
        head = newNode;
        return;
    }
    list *newNode = new list(d);
    tail->next = newNode;
    tail = newNode;
}
void insertAtPosition(list *&head, list *&tail, int pos, int d)
{
    // case handling

    // if inserting a node at head
    if (pos == 1)
    {
        // calling insertAtHead function
        insertAtHead(head, tail, d);
        return; // returning to stop flow
    }
    // taking pointer to right pos
    list *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        count++;
        temp = temp + 1;
    }
    // now we should be at the right position
    // creating the node to insert
    list *newNode = new list(d);
    // checking if we are inserting at last node
    if (temp->next == nullptr)
    {
        tail = newNode;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(list *&head, list *&tail, int pos)
{
    // list is empty
    if (head == nullptr && tail == nullptr)
    {

        cout << "List is empty!" << endl;
        return;
    }
    // if one element is present
    if (head == tail)
    {
        list *temp = head;
        delete temp;
        head = tail = nullptr;
        cout << "List is now empty!" << endl;
        return;
    }
    // if we want to delete the first element
    if (pos == 1)
    {
        list *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }
    // if elements are present in list
    int count = 1;
    list *curr = head;
    list *prev = nullptr;
    while (count < pos)
    {
        count++;
        prev = curr;
        curr = curr->next;
    }
    // we are deleting last node
    if (curr->next == nullptr)
    {
        tail = prev;
    }
    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
}
// iteratively
tree *iterative()
{

    int rootValue, leftChild, rightChild;
    cout << "Enter root value: ";
    cin >> rootValue;
    if (rootValue == -1)
    {
        return nullptr;
    }
    tree *root = new tree(rootValue);
    queue<tree *> q;
    q.push(root);

    while (!q.empty())
    {
        tree *temp = q.front();
        q.pop();
        cout << "Enter left child of " << temp->data << " ";
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
tree *recursively()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }
    tree *temp = new tree(d);
    cout << "Enter the left value of " << temp->data << ": ";
    temp->left = recursively();
    cout << "Enter the right value of " << temp->data << ": ";
    temp->right = recursively();
    return temp;
}
void inOrder(BST *root)
{

    if (root == nullptr)
    {
        return;
    }
    BST *temp = root;
    inOrder(root->left);
    cout << temp->data << " ";
    inOrder(root->right);
}
// creating a BST
BST *insertBST(BST *root, int value)
{
    if (root == nullptr)
    {
        return new BST(value);
    }
    if (value < root->data)
    {
        root->left = insertBST(root->left, value);
    }
    if (value > root->data)
    {
        root->right = insertBST(root->right, value);
    }
    return root;
}
BST *helperFunction()
{
    BST *root = nullptr;
    int value;
    cout << "Enter root value: ";
    cin >> value;
    root = insertBST(root, value);
    while (true)
    {
        cout << "Enter value: ";
        cin >> value;
        if (value != -1)
        {
            root = insertBST(root, value);
        }
        else if (value == -1)
        {
            break;
        }
    }
    return root;
}
// find min value in BST
BST *minValue(BST *root)
{

    BST *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}
// delete in BST
BST *deleteNode(BST *&root, int val)
{

    // in case BST is empty
    if (root == nullptr)
    {
        return nullptr;
    }
    // if we are at the value
    if (val == root->data)
    {
        // 0 child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // 1 child
        // left child
        if (root->left != nullptr && root->right == nullptr)
        {
            BST *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == nullptr && root->right != nullptr)
        {
            BST *temp = root->right;
            delete root;
            return temp;
        }
        // two child
        if (root->left != nullptr && root->right != nullptr)
        {
            int val = minValue(root->right)->data;
            root->data = val;
            root->right = deleteNode(root->right, val);
        }
    }
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    return root;
}
// undirected graph
void addEdge(graph &g, int v, int w)
{

    g.adj[v].push_back(w);
    g.adj[w].push_back(v);
}
// display adj list
void display(graph &g)
{
    for (int v = 0; v < g.V; v++)
    {
        cout << "Vector: " << v << ": ";
        for (int w : g.adj[v])
        {
            cout << " --> " << w << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void BFS(graph &g, int start)
{
    vector<bool> visited(g.V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int w : g.adj[v])
        {
            if (!visited[w])
            {
                visited[w] = true;
                q.push(w);
            }
        }
    }
}
void DFS(graph &g, int start)
{
    vector<bool> visited(g.V, false);
    stack<int> s;
    visited[start] = true;
    s.push(start);

    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        cout << v << " ";
        for (int w : g.adj[v])
        {
            if (!visited[w])
            {
                visited[w] = true;
                s.push(w);
            }
        }
    }
}
// how to insert in heap
void heap::insertInHeap(int element)
{
    if (size >= capacity) // Check if the heap is full
    {
        cout << "Heap is full!" << endl;
        return;
    }

    // Insert the new element at the end of the heap
    arr[size] = element;
    size++; // Increment size after insertion

    // Bubble up the new element to maintain heap property
    int index = size - 1; // Adjust index to the last inserted element
    while (index > 0)
    {
        int parent = (index - 1) / 2; // Correct parent index calculation
        if (arr[parent] < arr[index]) // If the new element is greater than its parent
        {
            swap(arr[parent], arr[index]); // Swap with parent
            index = parent;                // Move up to the parent's index
        }
        else
        {
            return; // If the heap property is satisfied, exit
        }
    }
}
void heap::displayHeap()
{
    for (int i = 0; i < size; i++) // Iterate from 0 to size - 1
    {
        cout << arr[i] << " "; // Print each element
    }
    cout << endl; // New line after displaying the heap
}
void heap::deleteHeap()
{
    if (size == 0) // Check if the heap is empty
    {
        cout << "Nothing to delete" << endl;
        return;
    }

    // Replace the root of the heap with the last element
    arr[0] = arr[size - 1]; // Move the last element to the root
    size--;                 // Decrease the size of the heap

    // Restore the heap property by bubbling down the new root
    int index = 0; // Start from the root
    while (index < size)
    {
        int left = 2 * index + 1;  // Left child index
        int right = 2 * index + 2; // Right child index
        int largest = index;       // Assume the current index is the largest

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
void heap::heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check if right child exists and is greater than largest so far
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}
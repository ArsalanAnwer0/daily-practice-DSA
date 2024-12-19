#include <iostream>
#include <queue>
using namespace std;
// Linear Searching
// Binary Search
// Tree
// BST
// Heap
// Linked List
// Stack
// Queue
// BFS & DFS
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
        else if (arr[mid] < key)
        {

            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
class node
{
public:
    int data;
    node *left, *right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};
// implementing tree using iteration
node *tree()
{
    int rootValue, leftChild, rightChild;
    cout << "Enter root value: ";
    cin >> rootValue;
    if (rootValue == -1)
    {
        return nullptr;
    }
    node *root = new node(rootValue);
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        cout << "Enter left child of " << temp->data << ": ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            root->left = new node(leftChild);
            q.push(root->left);
        }
        cout << "Enter right child of " << temp->data << ": ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            root->right = new node(rightChild);
            q.push(root->right);
        }
    }
    return root;
}
// implementing tree using recursion
node *recursive()
{
    int d;
    cin >> d;
    // base case
    if (d == -1)
    {
        return nullptr;
    }
    node *root = new node(d);
    cout << "Enter left child of " << root->data << ": ";
    root->left = recursive();
    cout << "Enter right child of " << root->data << ": ";
    root->right = recursive();

    return root;
}
// traversals
void inOrder(node *root)
{

    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
// BST
// implementing BST using recursion
// code to insert node in bst
node *BST(node *root, int value)
{

    // if root reaches nullptr create a node
    if (root == nullptr)
    {

        return new node(value);
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
node *helper(node *root)
{

    int value;
    cout << "Enter root value: ";
    cin >> value;
    if (value != -1)
    {
        root = BST(root, value);
        while (true)
        {
            cout << "Enter value: ";
            cin >> value;
            root = BST(root, value);
        }
    }
    return root;
}
// min value
node *minValue(node *root)
{

    node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}
// deletion in a BST
node *deleteInBST(node *root, int value)
{

    // if tree is empty
    if (root == nullptr)
    {
        cout << "Tree is empty, Nothing to delete." << endl;
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

        // is it left child?
        if (root->left != nullptr && root->right == nullptr)
        {

            node *temp = root->left;
            delete root;
            return temp;
        }

        // is it right child?
        if (root->left == nullptr && root->right != nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != nullptr && root->right != nullptr)
        {
            int val = minValue(root->right)->data;
            root->data = val;
            root->right = deleteInBST(root->right, val);
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
class heap
{
public:
    int *arr;
    int size;

    heap()
    {
        size = 0;
        arr = new int[100];
    }
    void insertInHeap(int value)
    {

        // insert the value
        size++;
        int index = size;
        arr[index] = value;

        // take it to its right position.
        while(index > 1){
            int parent = index/2;

            if(arr[index] > arr[parent]){
                
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else{
                break;
            }
        }

    }
    void deleteInHeap(){

        arr[1] = arr[size];
        size--;

        // take it to its right position

        int i = 1;
        while(i < size){

            int left = 2*i;
            int right = 2*i+1;
            int largest = i;

            if(arr[largest] < arr[left]){
                largest = left;
            }
            if(arr[largest] < arr[right]){
                largest = right;
            }
            if(largest!=i){
                swap(arr[largest],arr[i]);
                i = largest;
            }
            else{
                break;
            }

        }
    }
};

int main()
{

    // node* root = nullptr;
    // cout << "Enter root value: ";
    // root = recursive();

    // cout << "In Order: ";
    // inOrder(root);
    // int key;
    // int arr[5] = {5,10,15,20,25};
    // int size = 5;
    // cout << "Enter key:";
    // cin >> key;
    // cout << binarySearch(arr, size, key);
}
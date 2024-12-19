#include <iostream>
#include <queue>
using namespace std;
// Tree
class node
{
public:
    int data;
    node *right, *left;

    node(int value) : data(value), right(nullptr), left(nullptr) {}
};

// recursive

node *tree2()
{

    int d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }
    node *root = new node(d);
    cout << "Enter left child of " << root->data << ": ";
    root->left = tree2();
    cout << "Enter right child of " << root->data << ": ";
    root->right = tree2();
    return root;
}

// Iteratively
node *tree()
{
    int rootValue, leftChild, rightChild;
    queue<node *> q;
    cout << "Enter root node value: ";
    cin >> rootValue;
    if (rootValue == -1)
    {
        return nullptr;
    }
    node *root = new node(rootValue);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter value of left child of " << temp->data << ": ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            temp->left = new node(leftChild);
            q.push(temp->left);
        }
        cout << "Enter value of right child of" << temp->data << ": ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            temp->right = new node(rightChild);
            q.push(temp->right);
        }
    }
    return root;
}

// inOrder Traversal
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
// Binary Search Tree

node *BST(node *root, int value)
{

    if (root == NULL)
    {
        root = new node(value);
        return root;
    }
    else if (value < root->data)
    {
        root->left = BST(root->left, value);
    }
    else
    {
        root->right = BST(root->right, value);
    }
    return root;
}

// search in a BST
// using recursive way:
bool search(node *root, int value)
{
    // base case
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == value)
    {
        return true;
    }
    else if (root->data > value)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

// using iterative way
bool search2(node *root, int value)
{

    node *temp = root;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return true;
        }
        else if (temp->data > value)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}
// minvalue
node *minValue(node *root)
{
    node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}
// maxValue
node *maxValue(node *root)
{
    node *temp = root;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp;
}
// number of leaf node in a tree
void leafNode(node *root, int &count)
{
    if (root == nullptr)
    {
        return;
    }
    // using inOrder Traversal
    leafNode(root->left, count);
    if (root->left == nullptr && root->right == nullptr)
    {

        count++;
    }
    leafNode(root->right, count);
}

int main()
{

    node *root;
    root = tree();
    int count = 0;
    leafNode(root, count);
    cout << endl
         << count << endl;
    return 0;
}
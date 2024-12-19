#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

// inserting into BST (one base case)
node *insertIntoBST(node *&root, int data)
{

    // base case
    if (root == nullptr)
    {
        root = new node(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

// searching in a BST

// recursive

bool searchInBST(node *root, int x)
{

    // base case we element not found
    if (root == nullptr)
        return false;

    // base case if element found
    if (root->data == x)
        return true;

    if (root->data > x)
    {
        // left part;
        return searchInBST(root->left, x);
    }
    else
    {
        return searchInBST(root->right, x);
    }
}

// iterative

bool searchInBST(node *root, int x)
{

    node *temp = root;
    while (temp != nullptr)
    {
        if (root->data == x)
            return true;

        if (root->data > x)
        {
            temp = temp->left;
        }
        if (root->data < x)
        {
            temp = temp->right;
        }
    }
    return false;
}

// min value in a BST

node *minValue(node *root)
{

    node *temp = root;

    while (temp != nullptr)
    {

        temp = temp->left;
    }
    return temp;
}
// max value in a BST
node *maxValue(node *root)
{

    node *temp = root;

    while (temp != nullptr)
    {

        temp = temp->right;
    }
    return temp;
}
// Deleting in a BST
node *deleteNode(node *root, int val)
{

    // base case
    if (root == nullptr)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 chlid
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // 1 child
        // left child
        if (root->left != nullptr && root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->right != nullptr && root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != nullptr && root->right != nullptr)
        {
            int mini = minValue(root->right) -> data;
            root->data = mini;
            root->right = deleteNode(root->right,mini);
        }
    }

    else if (root->data > val)
    {
        root->left = deleteNode(root->left, val);
    }
    else
    {
        root->right = deleteNode(root->right, val);
    }
    return root;
}

void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

int main()
{

    node *root = nullptr;

    cout << "Enter data to creat BST: ";
    takeInput(root);
}
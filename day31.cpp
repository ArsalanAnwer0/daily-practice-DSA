#include <iostream>
using namespace std;
// implementing Binary Search Tree

class node
{

public:
    int data;
    node *right, *left;

    node(int value) : data(value), right(nullptr), left(nullptr) {}
};

node *BST(node *root, int value)
{

    // base case
    if (root == nullptr)
    {

        return new node(value);
    }
    if (root->data < value)
    {
        root->right = BST(root->right, value);
    }
    if (root->data > value)
    {

        root->left = BST(root->left, value);
    }

    return root;
}

node *helper(node *root, int value)
{
    while (true)
    {

        if (value == -1)
        {

            break;
        }
        else
        {
            root = BST(root, value);
            cout << "Enter node value: ";
            cin >> value;
        }
    }

    return root;
}

void inOrder(node *root, int value)
{

    if (root == nullptr)
    {

        return;
    }

    inOrder(root->left, value);
    cout << root->data << " ";
    inOrder(root->right, value);
}
// searching in a BST

bool search(node *root, int value)
{

    // base case
    if (root == nullptr)
    {

        return false;
    }

    if (root->data > value)
    {
        return search(root->left, value);
    }
    else if (root->data < value)
    {
        return search(root->right, value);
    }

    return true;
}

node* minValue(node *root)
{
    node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}

node *deleteNode(node *root, int value)
{

    // base case
    if (root == nullptr)
    {
        cout << "Nothing to delete " << endl;
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
            node *temp = root->left;
            delete root;
            return temp;
        }
        // right
        if (root->left == nullptr && root->right != nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != nullptr && root->right != nullptr)
        {
            int num = minValue(root)->data;
            root->data = num;
            root->right = deleteNode(root->right,num);
        }
    }
    if (root->data > value)
    {
        root->left = deleteNode(root->left, value);
    }
    if (root->data < value)
    {
        root->right = deleteNode(root->right, value);
    }
    return root;
}

int main()
{

    node *root = nullptr;
    int value;
    cout << "Enter root value:";
    cin >> value;
    root = helper(root, value);

    inOrder(root, value);

    cout << endl
         << boolalpha << search(root, 41);

    return 0;
}
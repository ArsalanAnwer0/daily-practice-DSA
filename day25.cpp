#include <iostream>
using namespace std;
// implementing Binary Search Tree
class node
{
public:
    int data;
    node *left, *right;

    node(int value) : data(value), right(nullptr), left(nullptr) {}
};
node *insertAtTree(node *root, int value)
{

    if (root == nullptr)
    {
        return new node(value);
    }
}

// searching in  BST

bool search(node *root, int value)
{
    // first base case
    if (root == nullptr)
    {

        return false;
    }
    // second base case
    if (root->data == value)
    {

        return true;
    }

    if (value < root->data)
    {
        return search(root->left, value);
    }
    else if (value > root->data)
    {

        return search(root->right, value);
    }
}

node* minValue(node* root){
    node* temp = root;
    while(temp->left != nullptr){

        temp = temp -> left;
    }
    return temp;
}
node *deleteNode(node *root, int value)
{

    // base cases
    // I did not find the element
    if (root == nullptr)
    {
        cout << "Value not found";
        return nullptr;
    }
    // I found the element
    if (value == root->data)
    {

        // 0 child

        if (root->right == nullptr && root->left == nullptr)
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
            root->right = deleteNode(root->right,val);
        }
    }
    // finding the value
    if (value < root->data)
    {

        // left side
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {

        root->right = deleteNode(root->right, value);
    }
    return root;
}
node *helper()
{

    node *root = nullptr;
    int value;
    if (value == -1)
    {
        return nullptr;
    }
    root = insertAtTree(root, value);
    while (true)
    {
        int value;
        cout << "Enter node: ";
        cin >> value;
        if (value == -1)
        {
            break;
        }
        else
        {
            root = insertAtTree(root, value);
        }
    }
    return root;
}
int main()
{

    node *root = nullptr;

    root = helper();

    return 0;
}
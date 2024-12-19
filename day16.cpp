// Binary Search Tree
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// inserting in a BST
node *insert(node *root, int value)
{

    if (root == nullptr)
    {
        return root = new node(value);
    }

    if (value > root->data)
    {

        root->right = insert(root->right, value);
    }
    if (value < root->data)
    {

        root->left = insert(root->left, value);
    }
    return root;
}

bool searchInBST(node *root, int value)
{

    if (root == nullptr)
    {
        return false;
    }
    if (value == root->data)
    {

        return true;
    }
    if (value > root->data)
    {

        return searchInBST(root->right, value);
    }
    if (value < root->data)
    {
        return searchInBST(root->left, value);
    }

    return false;

}

node* minValue(node* node1){
    node* temp = node1;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}

node *deleteMe(node *node1, int value)
{
    // base case
    if (node1 == nullptr)
    {
        return node1;
    }
    // base case
    if (node1->data == value)
    {

        // 0 child
        if (node1->left == nullptr && node1->right == nullptr)
        {
            delete node1;
            return nullptr;
        }

        // 1 child
        // left child
        if (node1->left != nullptr && node1->right == nullptr)
        {
            node *temp = node1->left;
            delete node1;
            return temp;
        }
        // right child
        if (node1->right != nullptr && node1->left == nullptr)
        {
            node* temp = node1->right;
            delete node1;
            return temp;
        }

        // 2 child
        if(node1->right != nullptr && node1->left != nullptr){
            node* mini = minValue(node1->right);
            node1->data = mini->data;
            node1->right = deleteMe(node1->right,mini->data);
        }
    }

    if (node1->data > value)
    {

        node1->left = deleteMe(node1->left, value);
    }
    if (node1->data < value)
    {

        node1->right = deleteMe(node1->right, value);
    }
        return node1;
}


int main()
{

    return 0;
}
// Binary Search Tree
// recursion is important
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *right, *left;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

node *BST(node *root, int value)
{

    // base case
    if (root == nullptr)
    {
        return new node(value);
    }
    if (value < root->data)
    {

        root->left = BST(root->left, value);
    }
    else if (value > root->data)
    {

        root->right = BST(root->right, value);
    }
    return root;
}

node* helper()
{
    node *root = nullptr;
    int value;
    cout << "Enter root node: ";
    cin >> value;
    root = BST(root,value);
    while (true)
    {
        cout << "Enter node(-1 to stop) : ";
        cin >> value;
        if (value == -1)
        {

             break;
        }
        else{
            root = BST(root,value);
        }
    }
    return root;
    
}

void inOrder(node* root){
    if(root == nullptr){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);


}

int main()
{

    node* root;
    root = helper();
    cout << endl << "Inorder: ";
    inOrder(root);

    

    return 0;
}
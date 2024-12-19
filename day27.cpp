#include <iostream>
#include <queue>
using namespace std;
// Binary Tree
class node
{
public:
    int data;
    node *left, *right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};
// iterative
node *iterative()
{

    int rootValue, leftChild, rightChild;
    queue<node *> q;

    cout << "Enter root value: ";
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

        cout << "Enter left child of " << root->data << ": ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            root->left = new node(leftChild);
            q.push(root->left);
        }
        cout << "Enter right child of  " << root->data << ": ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            root->right = new node(rightChild);
            q.push(root->right);
        }
    }

    return root;
}
// using recursion
node *recursion()
{

    int d;
    cin >> d;
    if (d == -1)
    {

        return nullptr;
    }
    node *root = new node(d);
    cout << "Enter left child of " << root->data << ": ";
    cin >> left;
    root->left = recursion();
    cout << "Enter right child of " << root->data << ": ";
    cin >> right;
    root->right = recursion();
    return root;
}
// counting leaf nodes
int leaf(node* root){
    int count=0;
    if(root == nullptr){
        return 0;
    }
    count+=leaf(root->left);
    if(root->left == nullptr && root->right == nullptr){
        count++;
    }
    count+=leaf(root->right);

    return count;
}
int main()
{

    node *root = nullptr;
    cout << endl;
    root = iterative();
    cout << leaf(root);

    return 0;
}
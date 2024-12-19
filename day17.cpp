// Tree
#include <iostream>
#include <queue>
using namespace std;
class node
{

public:
    int data;
    node *left, *right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// recursive

node *tree2(){

    int d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }
    node* temp =  new node(d);
    cout << "Enter left child of " << temp->data << ": ";
    temp->left = tree2();
    cout << "Enter right child of " << temp->data << ": ";  
    temp->right = tree2();

    return temp;
}

node *tree()
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

        cout << "Enter left child of " << temp->data << ": ";
        cin >> leftChild;
        if (leftChild != -1)
        {

            temp->left = new node(leftChild);
            q.push(temp->left);
        }
        cout << "Enter right child of  " << temp->data << ": ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            temp->right = new node(rightChild);
            q.push(temp->right);
        }
    }

    return root;
}

int main()
{

    node *root;
    cout << "Enter root value: ";
    root = tree2();

    return 0;
}
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *right, *left;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

node *tree(node *root, int value)
{

    if (root == nullptr)
    {
        return new node(value);
    }
    if (value < root->data)
    {
        root->left = tree(root->left, value);
    }
    if (value > root->data)
    {
        root->right = tree(root->right, value);
    }
    return root;
}

node *constructor()
{

    node *root = NULL;
    int d;
    while (true)
    {
        cin >> d;
        if (d == -1)
        {

            return nullptr;
        }
        else
        {
            tree(root, d);
        }
    }
}

int main()
{

    return 0;
}
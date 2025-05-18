// Learning Trees
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <utility>
#include <set>
#include <queue>
using namespace std;

// Linked List - linear data structure

// Tree - Non Linear Data Structure

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node *buildTree(node *root)
{
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left" << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right" << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *&root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// Reverse level order traversal

// In order traversal
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
// Post order traversal
void postOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Pre order traversal
void preOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// in order traversal using iteration
node *buildFromLevelOrder(node *root)
{
    queue<node *> q;
    int data, leftChild, rightChild;
    cout << "enter data for root";
    cin >> data;
    if (data != -1)
    {
        root = new node(data);
    }
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter left node for " << temp->data << endl;
        cin >> leftChild;
        if (leftChild != -1)
        {
            root->left = new node(leftChild);
            q.push(root->left);
        }
        cout << "Enter right node for " << temp->data << endl;
        cin >> rightChild;
        if (rightChild != -1)
        {
            root->right = new node(rightChild);
            q.push(root->right);
        }
    }
    return root;
}

// count leaf node

void inOrder(node *root, int &cnt)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left, cnt);
    if (root->left == nullptr && root->right == nullptr)
    {
        cnt++;
    }
    inOrder(root->right, cnt);
}

int noOfLeafNodes(node *root)
{
    int cnt = 0;
    inOrder(root, cnt);
    return cnt;
}

int main()
{
    // node *root = NULL;
    // root = buildTree(root);
    // levelOrderTraversal(root);
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL;
    root = buildFromLevelOrder(root);
    inOrder(root);
}

// Tree questions

// Height of binary tree

// Longest path between root node and leaf node

// recursion -> just do one, I will take care of the rest

// left subtree height and right sub tree height + 1

// Binary Search

// Sorted Array

//

class node2
{
public:
    int data;
    node2 *left;
    node2 *right;

    node2(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// using recursion
node2 *insertIntoData(node2 *root, int data)
{
    // base case
    if (root == nullptr)
    {
        root = new node2(data);
        return root;
    }
    if (data > root->data)
    {
        // insert in right part
        root->right = insertIntoData(root->right, data);
    }
    else
    {
        // insert in left part
        root->left = insertIntoData(root->left, data);
    }
}
// in order
// pre order
// post order

void takeInput(node2 *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoData(root, data);
        cin >> data;
    }
}

int main()
{
    node2 *root = nullptr;
    cout << "Enter data to create bst: ";
    takeInput(root);
}

// search in a bst
// recursive
bool searchInBST(node2 *root, int data)
{
    // base case
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (root->data > data)
    {
        return searchInBST(root->left,data);
    }
    if(root->data < data){
        return searchInBST(root->right,data);
    }
}

// iteration
bool searchInBST(node2 *root, int data)
{
    node2* temp = root;
    while(temp!=NULL){
        if (root->data == data)
        {
            return true;
        }
        if (root->data > data)
        {
            return searchInBST(root->left,data);
        }
        if(root->data < data){
            return searchInBST(root->right,data);
        }
    }
    return false;
}

// Deletion in a BST

node2* minValue(node2* root){
    node2* temp = root;
    while(temp->left!=nullptr){
        temp = temp->left;
    }
    return temp;
}
node2* maxValue(node2* root){
    node2* temp = root;
    while(temp->right!=nullptr){
        temp = temp->right;
    }
    return temp;
}

// in order predecessor previous one
// in order sucessor next one in line

// deletion

// reach the node you want to delete

// 0 child one child two child can be a two nodes or an entire subtree

node2* deleteFromBST(node2* root,int val){
    // base case
    if(root == nullptr){
        return root;
    }
    if(root->data == val){
        // 0 child
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        // 1 child
        // left child
        if(root->left != nullptr && root->right == nullptr){
            node2* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->left == nullptr && root->right != nullptr){
            node2* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left != nullptr && root->right != nullptr){
           int minVal = minValue(root->right)->data;
           root->data = minVal;
           root->right = deleteFromBST(root->right,minVal);
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right,val);
        return root;
    }
}

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left,*right;

    node(int value) : data(value), left(nullptr) , right(nullptr) {}
};

// Creating a binary search tree

node* BST(node* root, int value){

    if(root==NULL){
        return new node(value);
    }
    if(root->data > value){
        BST(root->left,value);
    }
    else if(root->data < value){
        BST(root->right,value);
    }
    return root;
}


// creating binary tree using iteration
node* iterative(){
    int rootValue,leftChild,rightChild;
    queue<node*> q;
    cout << "Enter root value: ";
    cin >> rootValue;
    if(rootValue == -1){
        return nullptr;
    }
    node* root = new node(rootValue);
    q.push(root);
    while(!q.empty()){
        node* temp =  q.front();
        q.pop();
        cout << "Enter left chid of " << temp->data<< ": ";
        cin >> leftChild;
        if(leftChild != -1){
            temp -> left = new node(leftChild);
            q.push(temp->left);
        }
        cout << "Enter right child of " << temp->data << ": ";
        cin >> rightChild;
        if(rightChild != -1){
            temp->right = new node(rightChild);
            q.push(temp->right);
        }
    }
    return root;
}
// creating binary tree using recursion
node* recursion(){
    int d;
    cin >> d;
    if(d == -1){
        return nullptr;
    }
    node* root = new node(d);
    cout << "Enter left child of " << root->data <<": ";
    root->left = recursion();
    cout << "Enter right child of  " << root->data << ": ";
    root->right = recursion();
    return root;
}

node* recursiveBuilder(){

    cout << "Enter root value: " ;
    node* root;
    root = recursion();
    return root;
}
void inOrder(node* root){
    if(root==nullptr){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main(){

    int value;
    node* root = nullptr;
    while(true){
        cin >> value;
        if(value==-1){
            break;
        }
        else{
            root = BST(root,value);
        }
    }
    inOrder(root);








    return 0;
}

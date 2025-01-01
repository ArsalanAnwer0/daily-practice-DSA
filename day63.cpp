// Tree
#include<iostream>
#include<queue>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    // constructor
    node(int d) : data(d),left(nullptr),right(nullptr){

    }
}
// recursive
node* buildTree(node* root){
    cout << "Enter the data: ";
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1){
        return nullptr;
    }
    cout << "Enter data for inserting in left: ";
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right: ";
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
             cout << temp->data << " ";
        if(temp -> left){
            q.push(temp->left);
        }
         if(temp -> right){
            q.push(temp->right);
        }
        }
    }
}

void inOrder(node* root){

    // base case
    if(root == nullptr){
        return;
    }
    inOrder(root->left);
    cout << root -> data << " ";
    inOrder(root->right);

}

void preOrder(node* root){
    // base case
    if(root == nullptr){
        return;
    }
    cout << root -> data << " ";
    preOrder(root->left);
    preOrder(root->right);   
}

void postOrder(node* root){
    // base case
    if(root == nullptr){
        postOrder(root->left);
        postOrder(root->right);    
        cout << root -> data << " ";
        }
}

int main(){

    node* root = nullptr;
    root = buildTree();

    // traversal

    // level order
    levelOrderTraversal(root);

    // pre order 
    preOrder(root);


    // post order
    postOrder(root);


    return 0;
}
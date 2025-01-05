// BST
#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* left,*right;

    // contructor
    node(int val): data(val),left(nullptr),right(nullptr){}

};

// creating a BST

node* BST(node* &root,int data){


    if(root == nullptr){
        root = new node(data);
    }

    // checking left and right
    if(root->data < data){
        root->right = BST(root->right,data);
    }
    if(root->data > data){
        root->left = BST(root->left,data);
    }
    return root;
}

node* takeInput(node* &root){
    int data;
    cin >> data;

    while(data!=-1){
        BST(root,data);
        cout << "Enter child value: ";
        cin >> data;
}
return root;
}
 
void inOrder(node*  root){
    if(!root){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    }
    // min val
    Node* minVal(node* root){
        node* temp = root;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }
    // max val
        Node* maxVal(node* root){
        node* temp = root;
        while(temp->right!=NULL){
            temp = temp->right;
        }
        return temp;
    }
    // deletion in BST
    node* deleteInBST(node* &root, int val){
        
        // if nothing is found or BST does not exist
        if(root == nullptr){
            return nullptr;
        }
        if(root->data == val){
            // check no child
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            // check one child
            // for left child exist
            if(root->left != nullptr && root->right == nullptr){
                node* temp = root->left;
                delete root;
                return temp;
            }
            // right child exist
                if(root->right != nullptr && root->left == nullptr){
                node* temp = root->right;
                delete root;
                return temp;
            }
            // check two child
            if(root->left != nullptr && root->right != nullptr){
                int temp = minVal(root->right) -> data;
                root->data = temp;
                root->right = deleteInBST(root->right,temp);
            }
        }
        // searching for val
        if(root->data < val){
            root->right = deleteInBST(root->right,val);
        }
        if(root->data > val){
            root->left = deleteInBST(root->left,val);
        }
        return root;
    }

int main(){

    node* root = nullptr;
    cout << "Enter data to create BST: ";
    root = takeInput(root);
    cout << endl;
    inOrder(root);
    
    return 0;
}


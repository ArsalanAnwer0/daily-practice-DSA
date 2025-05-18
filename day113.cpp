#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// Perfecting Tree data structure

class node{
    public:
    int data;
    node* left,*right;

    node(int value){
        data =  value;
        left = right = NULL;
    }

};

node* BinaryTree(){
    int x;
    cin >> x;
    if(x == -1){
        return NULL;
    }
    node* temp = new node(x);
    // left side create
    cout << "Enter left child of " << x << " ";
    temp->left = BinaryTree();
    // right side create
    cout << "Enter right child of " << x << " ";
    temp->right = BinaryTree();
    return temp;
}

void preOrder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data<< " ";
    preOrder(root->left);
    preOrder(root->right);


}
void postOrder(node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data<< " ";
}
void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data<< " ";
    inOrder(root->right);
}

void inOrder(node* &root,vector<int> &ans){
    if(root == nullptr){
        return;
    }
    inOrder(root->left,ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}

// Level Order traversal

vector<int> levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    vector<int> ans;
    node* temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        // left side
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return ans;
}

// tree sort

// implementing BST

// Insert into BST
node* insertBST(node* root, int value) {
    if (root == nullptr) {
        return new node(value);
    }
    if (value < root->data) {
        root->left = insertBST(root->left, value);
    } else if (value > root->data) {
        root->right = insertBST(root->right, value);
    }
    return root;
}

vector<int> BST(node* root, int arr[], int size) {
    // Create BST
    node* bstRoot = nullptr;
    for(int i = 0; i < size; i++) {
        bstRoot = insertBST(bstRoot, arr[i]);
    }
    
    // Get sorted array through inorder traversal
    vector<int> ans;
    inOrder(bstRoot, ans);
    return ans;
}

int main(){
    // level order traversal
    // int x;
    // cout << "Enter root element: ";
    // cin >> x;
    // int first,second;
    // queue<node*> q;
    // node* root = new node(x);
    // q.push(root);

    // while(!q.empty()){
    //     node* temp = q.front();
    //     q.pop();
    //     cout << "Enter the left value of " << temp->data << " ";
    //     cin >> first;
    //     // left node 
    //     if(first!=-1){
    //         temp->left =  new node(first);
    //         q.push(temp->left);
    //     }
                
    //     // right node
    //     cout << "Enter the right value of " << temp->data << " ";
    //     cin >> second;
        
    //     if(second!=-1){
    //         temp->right =  new node(second);
    //         q.push(temp->right);
    //     }
    // }
    // recursive way to build tree
    std::cout << "Enter the root node: ";
    node* root;
    root = BinaryTree();

    // Traversal in BST

    cout << "Pre order: ";
    preOrder(root);
    cout << "Post order: ";
    postOrder(root);
    cout << "In Order: ";
    inOrder(root);

    int arr[] = {5, 3, 7, 2, 4, 6, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> sortedArr = BST(nullptr, arr, size);
    cout << "\nSorted array: ";
    for(int i = 0; i < size; i++) {
        cout << sortedArr[i] << " ";
    }

    return 0;
}



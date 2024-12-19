#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left,*right;

    node(int value) :data(value), left(nullptr),right(nullptr){}
};
// creating tree using iterative way (Level Order)
node* tree(){

    int rootValue,rightChild,leftChild;
    cout << "Enter root value: ";
    cin >>  rootValue;
    if(rootValue == -1){
        return nullptr;
    }
    node* root = new node(rootValue);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout << "Enter left chlid of " << temp->data << ": ";
        cin >> leftChild;
        if(leftChild!=-1){
            temp->left = new node(leftChild);
            q.push(temp->left);
        } 
        cout << "Enter right child of  " << temp->data << ": ";
        cin >> rightChild;
        if(rightChild!=-1){
            temp->right = new node(rightChild);
            q.push(temp->right);
        } 
    }
    return root;
}

void inOrder(node* &root){
    if(root == nullptr){
        return;
    }
    node* temp = root;
    inOrder(temp->left);
    cout << temp->data  << " ";
    inOrder(temp->right);

}
int main(){

    node* root;
    root = tree();
    cout <<  endl << "Inorder: " << " ";
    inOrder(root);




    return 0;
}
// Tree
// Binary Tree
/*

void BFS(int start) {
    unordered_map<int, bool> visited;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjancencyList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
*/
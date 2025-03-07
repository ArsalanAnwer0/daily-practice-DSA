#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left,*right;

    node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
        int& operator*(){
        return data;
    }

    friend ostream& operator<<(ostream& os, const node& n){
        os << n.data;
        return os;
    }
};

    // print tree in order
    void inOrder(node* root){
        // base case
        if(root == nullptr){
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    // recursively
    node* tree(node* root){
         int d;
        cin >> d;
        if(d == -1){
            return nullptr;
        }
        root = new node(d);
        cout << "Enter left child node of " << root->data<<" ";
        root->left = tree(root->left);
        cout << "Enter right child node of " << root->data << " ";
        root->right = tree(root->right);

        return root;
    }

    // iteratively
    node* tree2(node* root){
        queue<node*> q;
        int rootData,leftData,rightData;
        cout << "Enter root data: ";
        cin >> rootData;
        if(rootData == -1){
            return nullptr;
        }
        root = new node(rootData);
        q.push(root);

        while(!q.empty()){
            node* temp = q.front();
            q.pop();

            cout << "Enter left child data of " << temp->data << " ";
            cin >> leftData;
            if(leftData != -1){
                root->left = new node(leftData);
                q.push(root->left);
            }
            cout << "Enter right child data of " << temp->data << " ";
            cin >> rightData;
            if(rightData != -1){
                root->right = new node(rightData);
                q.push(root->right);
            }
            
        }
        return root;
    }


    // coding binary search tree

    node* insertInBST(node* root,int data);

    node* helper(node* root){
        int d,c;
        cout << "Enter root node: ";
        cin >> d;
        if(d != -1){
            root = insertInBST(root,d);
            while(true){
                cout << "Enter child node: ";
                cin >> c;
                if(c != -1){
                    root = insertInBST(root,c);
                }
                else{
                    break;
                }
            }
        }
        return root;
    }

    // using recursion
    node* insertInBST(node* root,int data){
        // base case
        if(root == nullptr){
            return new node(data);
        }
        // search for the area
        if(root->data > data){
            root->left = insertInBST(root->left,data);
        }
        if(root->data < data){
            root->right = insertInBST(root->right,data);
        }
        return root;
    }

    node* searchInBST(node* root, int data){
        if(root == nullptr || root->data == data){
            // we did not find node
            return root;
        }
        // search
        if(root->data > data){
            return searchInBST(root->left,data);
        }
        if(root->data < data){
            return searchInBST(root->right,data);
        }
        return root;
    }

    // finding minimum value of tree for inorder predecessor
    node* minimumValue(node* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }

    // delete in BST
    node* deleteInBST(node* root,int data){

        if(root == nullptr){
            return root;
        }
        if(root->data == data){
            // 0 child
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            // 1 child
                // left child
            if(root->left != nullptr && root->right == nullptr){
                node* temp = root->left;
                delete root;
                return temp;
            }
                // right child
            if(root->left == nullptr && root->right != nullptr){
                node* temp = root->right;
                delete root;
                return temp;
            }
            // 2 child   
            if(root->left == nullptr && root->right == nullptr){
                node* temp = minimumValue(root->right);
                root->data = temp->data;
                root->right = deleteInBST(root->right,temp->data);
            } 
        }
        // searching for the node
        if(root->data > data){
                root->left = deleteInBST(root->left,data);
        }
        if(root->data < data){
            root->right = deleteInBST(root->right,data);
        }
        return root;
    }
int main(){

    node* root = nullptr;
    root = helper(root);
    inOrder(root);
    root = deleteInBST(root,5);
    cout << endl;
    inOrder(root);

    // node* hehe = searchInBST(root,5);
    // if(hehe != nullptr){
    //     cout << "Element found " << *hehe << endl;
    // }
    // else{
    //     cout << "Element not found!" << endl;
    // }
    return 0;
} 
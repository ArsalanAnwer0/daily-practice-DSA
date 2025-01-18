// solving some tree questions
#include<iostream>

// height of binary tree

// height is longest path between root node and left node

class tree{
    public:
    int data;
    tree* left,* right;

    // contructor
    tree(int value): data(value),left(nullptr),right(nullptr){}

};

class solution{
    public:

    int height(tree* treeOne){
        // base case
        if(treeOne == nullptr){
            return 0;
        }
        int left = height(treeOne->left);
        int right = height(treeOne->right);

        // returning recursion
        int ans = max(left,right) + 1;
        return ans;
    }
    // Diameter of binary tree = longest path between two nodes, no of nodes in that path is the diameter

    pair<int,int> diameterFast(tree* treeTwo){
        if(treeTwo == 0){
            pair<int,int> p = make_pair(0,0)
            return p;
        }
        pair<int,int> left = diameterFast(treeTwo->left);
        pair<int,int> right = diameterFast(treeTwo->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second +  1);
        return ans;
    }
    

    int diameter(tree* treeTwo){
        return diameterFast(treeTwo).first;
    }

    bool isBalanced(tree* root){
        if(root == NULL){
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool abs (diff = height(root->left) - height(root->right)) <= 1;

        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};




int main(){



}

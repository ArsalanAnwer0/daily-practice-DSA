// Learning Programming once again
// Trie

// Dictionary Words
// add word
// search word
// remove word

// Trie Data Structure

//  

#include<iostream>
using namespace std;

class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        // creating root node
        data = ch;
        // All children are null 
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        // There is no terminating node
        isTerminal = false;
    }

};

class trie{
    public:
    TrieNode* root;
    trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        // assumption our letters will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        // absent
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // RECURSION
        insertUtil(root,word.substr(1));

    }
    void insertWord(string word){
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode* root,string word){
        // base case
        if(word.length() == 0){
            // Terminal node?
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        //RECURSION
        return searchUtil(child,word.substr(1));
    }

    bool search(string word){
        return searchUtil(root,word);
    }
};

class Trie{
    public:
    Trie(){

    }
    void insert(string word){

    }
    bool search(string word){

    }
    bool startsWith(string prefix){

    }



};

int main(){
    return 0;
}

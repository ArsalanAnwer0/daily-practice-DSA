#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include<stack>
using namespace std;

class graph
{
private:
    // using unordered map to represent an adjacency list.
    unordered_map<int, vector<int>> adjacencyList;

public:
    void addEdge(int v, int w)
    {

        // connecting edges for an undirected graph.
        adjacencyList[v].push_back(w);
        adjacencyList[w].push_back(v);
    }
    void DFS(int startVertex){
         vector<bool> visited(adjacencyList.size(), false);
        stack<int> s;

        visited[startVertex] = true;
        s.push(startVertex);

        while (!s.empty())
        {

            int currentVertex = s.top();
            s.top();

            cout << currentVertex << " ";

            for (int neighbor : adjacencyList[currentVertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
    }
    void BFS(int startVertex)
    {

        vector<bool> visited(adjacencyList.size(), false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {

            int currentVertex = q.front();
            q.pop();

            cout << currentVertex << " ";

            for (int neighbor : adjacencyList[currentVertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

class node
{
public:
    int data;
    node *left, *right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// using iterative way to construct a tree
node *iterative()
{
    int rootValue, leftChild, rightChild;
    queue<node *> q;
    cout << "Enter rootValue: ";
    cin >> rootValue;
    if (rootValue == -1)
    {
        return nullptr;
    }
    node *root = new node(rootValue);
    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << ": ";
        cin >> leftChild;

        if (leftChild != -1)
        {
            temp->left = new node(leftChild);
            q.push(temp->left);
        }
        cout << "Enter right child of " << temp->data << ": ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            temp->right = new node(rightChild);
            q.push(temp->right);
        }
    }
    return root;
}

// inOrder traversal

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

// using recursive way to construct a tree

node *recursive()
{

    int data;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    node *root = new node(data);

    cout << "Enter left child of " << data << ": ";
    root->left = recursive();
    cout << "Enter right child of " << data << ": ";
    root->right = recursive();

    return root;
}

// creating a recursive builder

node *takeInput()
{

    cout << "Enter root value: ";
    node *root;
    root = recursive();

    return root;
}

int main()
{
    // node* root;
    // root = iterative();
    // inOrder(root);

    return 0;
}
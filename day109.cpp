#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <utility>
#include<vector>


using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;
};

// Breadth First Search
vector<int> BFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,
         int startVertex)
{
    vector<int> ans;
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto neighbor: adj[frontNode]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return ans;
}

// Depth First Search using recursion and also using stack
void dfs(int i,unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,vector<int>& component){
    component.push_back(i);
    visited[i] = true;
    for(auto neighbor: adj[i]){
        if(!visited[neighbor]){
            dfs(neighbor,adj,visited,component);
        }
    }   
}
vector<vector<int>>  dfsHelper(int vertices){
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    vector<vector<int>> components;

    // make sure all the vertices are checked

    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            vector<int> component;
           dfs(i,adj,visited,component); 
           components.push_back(component);
        }
    }
    return components;
}   
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
#include <list>
#include <utility>
#include <set>

using namespace std;

void dfs(int index,unordered_map<int,list<int>> &adj,unordered_map<int,bool>& visited,vector<int>& component){
    visited[index] = true;
    component.push_back(index);
    for(auto neighbors: adj[index]){
        if(!visited[neighbors]){
            dfs(neighbors,adj,visited,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges){
    // prepare adjacency list
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    vector<vector<int>> ans;
    for(int i=0;i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for disconnected components
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,adj,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main(){

}
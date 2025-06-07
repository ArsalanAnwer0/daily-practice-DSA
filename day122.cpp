// Cycle Detection in an directed graph using BFS
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>

using namespace std;

bool dfs(int index,unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsVisited){
    visited[index] = true;
    dfsVisited[index] = true;

    for(auto neighbors: adj[index]){
        if(!visited[neighbors]){
            bool ans = dfs(neighbors,adj,visited,dfsVisited);
            if(ans == 1){
                return true;
            }
        }
        // means that neighbor is visited
        else if(dfsVisited[neighbors] == true){
            return true;
        }
    }
    dfsVisited[index] = false;
    return false;
}

bool cycleDetection(int n,vector<pair<int,int>> &edges){
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    // create adjacency list
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // for disconnected components
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = dfs(i,adj,visited,dfsVisited);
            if(ans == 1){
                return true;
            }
        }
    }
    return false;
}

int main(){

    return 0;
}
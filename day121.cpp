// Cycle Detection in an undirected graph using BFS
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>

using namespace std;

bool bfs(int index,unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,vector<int>& parent){
    queue<int> q;
    q.push(index);
    visited[index] = true;
    parent[index] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto neighbors: adj[front]){
            if(!visited[neighbors]){
                q.push(neighbors);
                visited[neighbors] = true;
                parent[neighbors] = front;
            }
            // if we come here that means neighbors is visited
            else if(neighbors != parent[front]){
                return true;
            }
        }
    }
    return false;
}

bool CycleDetection(int vertices, int m, vector<vector<int>>& edges){
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    vector<int> parent(vertices,-1);
    // preparing adjancency list
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for disconnected components

    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            bool ans = bfs(i,adj,visited,parent);
            if(ans == 1){
                return true;
            }
        }
    }
    return false;
}


// Cycle detection of undirected graph using DFS

bool dfs(int index,unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,int parent){
    visited[index] = true;
        for(auto neighbors: adj[index]){
            if(!visited[neighbors]){
                bool ans = dfs(neighbors,adj,visited,index);
                if(ans == true){
                    return true;
                }
            }
            // if we come here that means neighbors is visited
            else if(neighbors != parent){
                return true;
            }
        }
    return false;
}

bool CycleDetection(int vertices, int m, vector<vector<int>>& edges){
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    vector<int> parent(vertices,-1);
    // preparing adjancency list
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for disconnected components

    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            bool ans = dfs(i,adj,visited,-1);
            if(ans == 1){
                return true;
            }
        }
    }
    return false;
}

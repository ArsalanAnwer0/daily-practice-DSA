#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<map>
#include<utility>
#include<queue>
#include<stack>
#include<set>

using namespace std;

// Cycle detection using BFS

bool isCycleBFS(int i, unordered_map<int,bool>&visited,unordered_map<int,list<int>>& adj){
    unordered_map<int,int> parent;
    queue<int> q;
    parent[i] = -1;
    visited[i] = true;
    q.push(i);

    while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neighbor : adj[front]){
                if(visited[neighbor] == true && neighbor != parent[front]){
                    return true;
                }
                else if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor];
                    parent[neighbor] = front;
                }
            }
    }
    return false;
}

bool isCycleDFS(int i,int parent, unordered_map<int,bool>&visited,unordered_map<int,list<int>>& adj){
    visited[i] = true;
    for(auto neighbor: adj[i]){
        if(!visited[neighbor]){
            bool cycle = isCycleDFS(neighbor,i,visited,adj);
            if(cycle){
                return true;
            }
        }
        else if(parent != neighbor){
            return true;
        }
    }    
    return false;
}

bool cycleDetection(vector<vector<int>> &edges, int n, int m){
    // create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    bool ans;
    // to handle disconnected components
    for(int i=0;i<n;i++){
        if(!visited[i]){
             ans = isCycleBFS(i,visited,adj);
        }
    }
    return ans;

}


int main(){

    return 0;
}
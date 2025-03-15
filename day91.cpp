#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

class graph{
    public:
    unordered_map<int,list<int> > adj;

    void addEdge(int u,int v, bool isDirected){
        adj[u].push_back(v);
        if(isDirected == 0){
            adj[v].push_back(u);
        }
    }
    bool isCyclicDFS(int node,int parent,unordered_map<int,bool>& visited,unordered_map<int,list<int> >&adj){
        visited[node] = true;
        for(auto neighbor: adj[node]){
            if(!visited[neighbor]){
                if(isCyclicDFS(neighbor,node,visited,adj)){
                    return true;
                }
                
            }
            else if(neighbor!=parent){
                    return true;
            }
        }
        return false;
    }
    bool isCyclicBFS(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int> >&adj){
        queue<int> q;
        unordered_map<int,int> parent;
        parent[node] = -1;
        visited[node] = true;
        q.push(node);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neighbor: adj[front]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                    parent[neighbor] = front;
                }
                // means neighbor is visited
                else if(parent[front] != neighbor){
                    return true;
                }
            }
        }
        return false;
    }
    // traversing all nodes
    bool isCyclic(int n,unordered_map<int,bool>& visited,unordered_map<int,list<int> >& adj){
        for(int i=0;i<n;i++){
            if(!visited[i]){
                //if(isCyclicBFS(i,visited,adj)){
                if(isCyclicDFS(i,-1,visited,adj)){
                    return true;
                }
            }
        }
        return false;
    }
    // cycle detection in direction graph using dfs


};
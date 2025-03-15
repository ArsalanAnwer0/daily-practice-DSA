#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>

using namespace std;

// Cycle detection using DFS

class graph{
    public:
    unordered_map<int,list<int> >adj;

    void addEdge(int u,int v,bool isDirected){
        adj[u].push_back(v);
        if(isDirected == 0){
            adj[v].push_back(u);
        }
    }
    // detect cycle in a directed graph
    bool cycleDFS2(int node,unordered_map<int,bool>& visited,
    unordered_map<int,bool>& dfsVisited,unordered_map<int,list<int> >&adj){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                if(cycleDFS2(neighbor,visited,dfsVisited,adj)){
                    return true;
                }
            }
             else if(dfsVisited[neighbor]){
                    return true;
                }
        }
        dfsVisited[node] = false;
            return false;
    }
    // detect cycle in a undirected graph
    bool cycleDFS(int node,int parent,unordered_map<int,bool>& visited,
    unordered_map<int,list<int> >&adj){
        visited[node] = true;
        for(auto neighbor: adj[node]){
            if(!visited[neighbor]){
                if(cycleDFS(neighbor,node,visited,adj)){
                    return true;
                }
                
            }
            // visited!
            else if(parent != neighbor){
                    return true;
                }   
        }
        return false;
    }
    // checking all nodes in the graph
    bool isCyclic(int node,unordered_map<int,bool> &visited,
    unordered_map<int,list<int> >&adj){
        for(int i=0;i<node;i++){
            if(!visited[i]){
                if(cycleDFS(i,-1,visited,adj)){
                    return true;
                }
            }
        }
        return false;
    }   
};



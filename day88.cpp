// cycle detection in directed graph using DFS

#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<list>

using namespace std;

bool checkCycleDFS(int node,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsVisited,unordered_map<int,list<int>>& adj){
    visited[node] =  true;
    dfsVisited[node] = true;

    for(auto neighbor: adj[node]){
        if(!visited[neighbor]){
            bool cycleDetected = checkCycleDFS(neighbor,visited,dfsVisited,adj);
            if(cycleDetected){
                return false;
            }
        }
        else if(dfsVisited[neighbor]){
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }

int detectCycleDirectedGraph(int n, vector<pair<int,int> >& edges){
    // create adjacency List
    unordered_map<int,list<int> > adj;
    for(int i = 0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        
    }

    // call dfs for all components
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    for(int i =1;i<=n;i++){
        if(!visited[i]){
            bool cycleFound = checkCycleDFS(i,visited,dfsVisited,adj);
            if(cycleFound){
                return true;
            }   
        }
    }
    return false;
}

int main(){
    return 0;
}
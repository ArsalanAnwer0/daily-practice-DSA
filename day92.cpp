#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>

using namespace std;

class graph{
    unordered_map<int,list<int> >adj;

    void addEdge(int u, int v, bool isDirected){
        adj[u].push_back(v);
        if(isDirected == 0){
            adj[v].push_back(u);
        }   
    }
    bool cycleBFS(int node,unordered_map<int,bool>&visited,
    unordered_map<int,list<int> >&adj){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        unordered_map<int,int> parent;
        parent[node] = -1;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neighbor : adj[front]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = front;
                }
                else if(parent[front] != neighbor){
                    return true;
                }
            }
        }
        return false;
    }
    // traversing all nodes
    bool IsCycle(int node,unordered_map<int,bool>& visited,
    unordered_map<int,list<int> >& adj){
        for(int i=0;i<node;i++){
            if(!visited[i]){
                if(cycleBFS(i,visited,adj)){
                    return true;
                }
            }
        }
        return false;
    }

};

int main(){
    return 0;
}
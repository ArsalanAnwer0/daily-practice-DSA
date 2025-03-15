#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<map>
using namespace std;

// topological sort

// DAG -> Directed Acyclic Graph

// Linear ordering of vertices such that for every edge u-v 
// u always appears before v in that ordering

// invalid topological sort

// topological acyclic can get valid sort and not cyclic

// using dfs

// we use visited ds and stack ds

// call and mark visited

// when returning insert that in stack from what we are returning from

// we check for more !visited mark visited and repeat

// topological sort function

// main processing function
void topoSort(int node,stack<int>& s,unordered_map<int,bool>& visited,unordered_map<int,list<int> >&adj){
        // marking node visited after its function call
        visited[node] = true;
        // check for the neighbor of the visited node
        for(auto neighbor: adj[node]){
            if(!visited[neighbor]){
                topoSort(neighbor,s,visited,adj);
            }
        }
        // while returning back
        s.push(node);
}

vector<int> topologicalSort(vector<vector<int> >& edges, int v,int e){


    // create adj list
    unordered_map<int,list<int> > adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // call dfs topological sort util fucntion for all components
    unordered_map<int,bool> visited;
    stack<int> s;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,s,visited,adj);
        }
    }

    // working on what we have to return
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
}

int main(){

    





    return 0;
}
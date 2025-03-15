#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<stack>
#include<vector>

using namespace std;


// Implementing Graph 

// code functions

unordered_map<int,list<int > > adj;



void addEdge(int u, int v,bool isDirected){
    adj[u].push_back(v);
    if(isDirected == 0){
        adj[v].push_back(u);
    }
}

bool DFS(int node,int parent, unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited){
    visited[node] = true;
   

    for(auto neighbors: adj[node]){
        if(!visited[neighbors]){
            if(DFS(neighbors,node,adj,visited)){
                return true;
            }
        }
        else if(parent != neighbors){
            return true;
        }
    }
    return false;
}   

// for traversing disconnected components

bool IsCycle(int n){
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool CycleDetected = DFS(i,-1,adj,visited);
            if(CycleDetected){
                return true;
            }
        }   
    }
    return false;
}




// class graph{
//     public:
//     unordered_map<int,list<int> > adj;

//     // printing graph
//     void printGraph(){
//         for(auto i : adj){
//             cout << i.first << "-->";
//             for(auto j:i.second){
//                 cout << j << ", "; 
//             }
//             cout << endl;
//         }
//     }

//     bool BFS(int n,unordered_map<int, list<int> >& adj, 
//     unordered_map<int,bool>& visited){
//         queue<int> q;
//         unordered_map<int,int> parent;
//         q.push(n);
//         visited[n] = true;
//         parent[n] = -1;
//         while(!q.empty()){
//             int current = q.front();
//             q.pop();

//             for(auto neighbor: adj[current]){
//                 if(!visited[neighbor]){
//                     q.push(neighbor);
//                     visited[neighbor] = true;
//                     parent[neighbor] = current;
//                 }
//                 else if(parent[current] != neighbor){
//                         return true;
//                 }
//             }
//         }
//         return false;
//     }
//     // for dis connceted nodes
//     bool CycleDetection(int n){
//         unordered_map<int,bool> visited;
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                bool cycleFound = BFS(i,adj,visited);
//                if(cycleFound){
//                 return true;
//                }
//                 //DFS();
//             }
//         }
//         return false;
//     }
// };

#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
#include<list>

using namespace std;
// Practicing Graphs Adjacency List Adjacency matrix 
// BFS and DFS 
// Dijkrats
// DFS Spanning Tree
// BFS Spanning Tree
// Minimum Spanning Tree
// Prims Algorithm
// MST find -> prims algorithm, kruskal algorithm

// prims algorithm for minimum spanning tree

// we need three things key visited and parent
// vector<pair<pair<int,int>, int>> calculatePrimsAlgorithm(int n, int m, vector<pair<pair<int,int>, int>> x){
//     // create adjancency list
//     unordered_map<int, vector<pair<int,int>>> adj;
//     for(int i = 0; i<x.size(); i++){
//         int u = x[i].first.first;
//         int v = x[i].first.second;
//         int w = x[i].second;
//         adj[u].push_back(make_pair(v,w));
//         adj[v].push_back(make_pair(u,w));

//     }

//     vector<int> key(n+1);
//     vector<bool> mst(n+1);
//     vector<int> parent(n+1);

//     for(int i = 0;i<=n;i++){
//         key[i] = INT_MAX; // to pick mininum key
//         parent[i] = -1;
//         mst[i] = false;
//     }
//     // lets start algo
//     key[1] = 0;
//     parent[1] = -1;
//     for(int i=1;i<n;i++){
//         int mini = INT_MAX;
//         int u;

//             // step 1
//         // checking all the indexes for minimum key
//         for(int v = 1; v<=n; v++){
//             if(mst[v] == false && key[v] < mini){
//                 u = v;
//                 mini = key[u];
//             }
//         }

//         // step 2 
//         // mark mini node as true
//         mst[u] = true;

//         // check its adjacent nodes

//         for(auto it: adj[u]){
//         int v = it.first;
//         int w = it.second; 
//         }
//     }

// }
// Graph
// Tree
// Heap   
// Is A Has A As A
vector<pair<pair<int,int>, int>> prims(int n, int m, vector<pair<pair<int,int>, int>>x){
    // step 1 minimum marking  find out minimum and not visited
    // step 2 true mark krdo
    // adjancent node lekr lao

    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<x.size();i++){
        int u = x[i].first.first;
        int v = x[i].first.second;
        int w = x[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    // adjacency list creation done

    vector<bool> mst(n+1);
    vector<int> key(n+1);
    vector<int> parent(n+1);

    // initialising data structures
    for(int i=0;i<=n;i++){
           mst[i] = false;
           key[i] =  INT_MAX;
           parent[i] = -1;
    }

    // lets start the algo

    key[1] = 0;
    parent[1]= -1;


    for(int i=1;i<n;i++){
        int mini = INT_MAX;
        int u;

        for(int v=1;v<=n;v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }   
        }
        // mark min node as true
        mst[u] = true;

        // find adjancent nodes of u
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;

            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int,int>, int>> result;
    for(int i=1;i<=n;i++){
        if(parent[i] != -1){
            result.push_back({{parent[i],i},key[i]});
        }
    }
    return result;
}


// dijkrstra algorithm

vector<int> dijkrstra(){
    // prepare adjancency list
    unordered_map<int,pair<int,int> > adj;

    // prepare adjancency list





}

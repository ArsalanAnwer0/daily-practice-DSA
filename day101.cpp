// minimum spanning tree
// prims algorithm
// key mst parent

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include<limits.h>

using namespace std;

// return type
vector<pair<pair<int, int>, int>>
    // function name
    prims
    // function parameters
    // number of nodes,number of edges,edgeList with weights ((1,2),5)
    (int nodeCount, int edgeCount, vector<pair<pair<int, int>, int>> &g)
{
    // create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // 3 data structures
    vector<int> key(nodeCount + 1);
    vector<bool> mst(nodeCount + 1);
    vector<int> parent(nodeCount + 1);

    for (int i = 0; i <= nodeCount; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // lets start the algo

    key[1] = 0;
    parent[1] = -1;
    // 
    for (int i = 1; i < nodeCount; i++)
    {
        int mini = INT_MAX;
        int u;

        // // finding mini node by travelling entire mst array and key array
        for (int v = 1; v <= nodeCount; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        // we can also use min heap instead of 0(n^2)

        // mark mini as true in mst
        mst[u] = true;

        // check its adjacent nodes
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for(int i = 2;i<=nodeCount;i++){
        result.push_back({{parent[i],i},key[i]});
    }
    return result;
}

// kruskal algorithm

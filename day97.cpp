// learning graph

#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
#include <list>

// adjacency matrix and adjacency list
// directed undirected weighted
// BFS (breadth first search)
// DFS (depth first search)
// Cycle detection -> undirected and directed graph
// Topological Sort
// Shortest Path Algorithms -> Dijkstra's
// Minimum Spanning Tree -> Prims,Kruskals
// Bridges
// Articulation Points
// Strongly connected components
// Bellman ford algorithm

// shortest path in undirected graph
// two nodes source and destination
// we can find shortest path for every node
// BFS adj list

using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool isDirected)
    {
        adjList[u].push_back(v);
        if (isDirected == 0)
            adjList[v].push_back(u);
    }

    void BFS(int startVertex)
    {
        queue<int> q;
        q.push(startVertex);
        unordered_map<int, bool> visited;
        visited[startVertex] = true;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto neighbor : adjList[front])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
    bool BFSUndirected(int node,unordered_map<int, bool> &visited,unordered_map<int, list<int>> &adjList)
    {
        queue<int>q;
        unordered_map<int,int> parent;
        q.push(node);
        parent[node] = -1;

        
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neighbor: adjList[front]){
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

    bool isCyclic(int n, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
    {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bool result = BFSUndirected(i, visited, adjList);
                if (result) {
                    return true;
                }
            }
        }
        return false;
    }

    


};

int main()
{
    graph g;
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 0, false);
    g.addEdge(3, 4, false);

    unordered_map<int, bool> visited;
    bool hasCycle = g.isCyclic(5, visited, g.adjList);

    if (hasCycle) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}

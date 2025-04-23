#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    // cycle detection in undirected graph
    // using dfs

    bool dfsCycle(int node, int parent, unordered_map<int, bool> visited,
                  unordered_map<int, list<int>> &adj)
    {
        visited[node] = true;

        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (dfsCycle(neighbor, node, visited, adj))
                {
                    return true;
                }
            }
            else if (parent != neighbor)
            {
                return true;
            }
        }
        visited[node] = false;
        return false;
    }

    // cycle detection in undirected graph
    // using bfs
    bool bfsCycle(int node, unordered_map<int, bool> &visited,
                  unordered_map<int, list<int>> &adj)
    {
        unordered_map<int, int> parent;
        visited[node] = true;
        parent[node] = -1;
        queue<int> q;
        q.push(node);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto neighbor : adj[front])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    parent[neighbor] = front;
                    visited[neighbor] = true;
                }
                // visited
                else if (parent[front] != neighbor)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // traversing all nodes in
    // disconnected graph

    bool isCyclic(int nodes, unordered_map<int, bool> &visited,
                  unordered_map<int, list<int>> adj)
    {
        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i])
            {
                // if (bfsCycle(nodes, visited, adj))
                if (dfsCycle(nodes,-1, visited, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
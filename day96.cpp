#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    // practicing to write a function that creates adj list
    // creating adj list
    vector<int> CreateList(int n, vector<vector<int>> &edges)
    {
        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    // printing graph adj list

    void adjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "-->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
        }
        cout << endl;
    }

    // BFS in graph
    vector<int> BFS(int startVertex)
    {
        vector<int> v;
        unordered_map<int, bool> visited;
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {
            int front = q.front();
            v.push_back(front);
            q.pop();

            for (auto neighbor : adj[front])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return v;
    }
    // DFS in graph
    vector<int> DFS(int startVertex)
    {
        stack<int> s;
        unordered_map<int, bool> visited;
        s.push(startVertex);
        visited[startVertex] = true;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            for (auto neighbor : adj[top])
            {
                if (!visited[neighbor])
                {
                    s.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
    // cycle detection in a undirected graph using DFS
    bool CycleDFSUndirected(int node,int parent,unordered_map<int,bool>& visited,unordered_map<int,list<int> >&adj)
    {
        visited[node] = true;

        for(auto neighbor: adj[node]){
            if(!visited[neighbor]){
                
                if(CycleDFSUndirected(neighbor,node,visited,adj)){
                    return true;
                }   

            }
            else if(parent!=neighbor){
                return true;
            }   
        }
        return false;
    }
    // cycle detection in an undirected graph using BFS
    bool CycleBFSUndirected(int node, unordered_map<int, bool> &visited,
                            unordered_map<int, list<int>> &adj)
    {
        unordered_map<int, int> parent;
        parent[node] = -1;
        queue<int> q;
        visited[node] = true;
        q.push(node);

        while (!q.empty())
        {
            int front = q.front();
            for (auto neighbor : adj[front])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = front;
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

    // traversing all nodes in graph
    bool IsCyclic(int n, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                // int ans = CycleBFSUndirected(i, visited, adj);
                int ans = CycleDFSUndirected(i,-1,visited,adj);
                if (ans)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
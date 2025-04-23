

// Shortest Path in a directed graph

#include <iostream>
#include <list>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

// Shortest Path in a Acyclic directed graph
// topological sort
// linear ordering
// distance array
// stack
// visited
// adjacency list with weights

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjlist;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adjlist[u].push_back(p);
    }
    void printAdj()
    {
        for (auto i : adjlist)
        {
            cout << i.first << "--> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[node] = true;
        for (auto neighbor : adjlist[node])
        {
            if (!visited[neighbor.first])
            {
                dfs(neighbor.first, visited, s);
            }
        }
        s.push(node);
    }
    void getShortestPath(int src, vector<int> &distance, stack<int> &s)
    {
        distance[src] = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            if (distance[top] != INT_MAX)
            {
                for (auto i : adjlist[top])
                {
                    if (distance[top] + i.second < distance[i.first])
                    {
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }
};



int main()
{
    graph g;
    unordered_map<int, bool> visited;
    stack<int> s;
    int n = 6;
    // topological sort
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }
    int src = 1;
    vector<int> distance(n);

    for(int i = 0;i<n;i++){
        distance[i]  = INT_MAX;
    }

    g.getShortestPath(src,distance,s);
    for (int i = 0; i < n; i++)
    {
        cout << distance[i] << " ";
    }
    

}




// Shortest Path in Undirected Graph
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // create an adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do bfs

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    parent[s] = -1;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }

    // preapare shortest path

    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);
    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    // reverse
    reverse(ans.begin(), ans.end());

    return ans;
}
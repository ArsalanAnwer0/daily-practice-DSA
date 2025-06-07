#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
#include <list>
#include <utility>
#include <set>

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << "-->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
    vector<vector<int>> printAdj(int n, int m, vector<vector<int>> &edges)
    {
        // create an adjacency list
        vector<int> ans[n];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        vector<vector<int>> adj;
        for (int i = 0; i < n; i++)
        {
            adj[i].push_back(i);

            for (int j = 0; j < ans[i].size(); j++)
            {
                adj[i].push_back(ans[i][j]);
            }
        }
        return adj;
    }
    // BFS -  Breadth First Search - Traversal Technique
    // visited
    // adj list
    // queue
    // multiple components
    //

    void prepareAdj(unordered_map<int, list<int>> &adj, vector<pair<int, int>> &edges)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void bfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            // check its neighbors
            for (auto neighbors : adj[front])
            {
                if (!visited[neighbors])
                {
                    visited[neighbors] = true;
                    q.push(neighbors);
                }
            }
        }
    }

    vector<int> BFS(int vertex, vector<pair<int, int>> &edges)
    {
        // create adjacency list
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;
        vector<int> ans;

        prepareAdj(adj, edges);

        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                bfs(i, adj, visited, ans);
            }
        }
        return ans;
    }
};



using namespace std;

int main()
{

    return 0;
}

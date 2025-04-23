// learning graph
// topological graph using dfs and backtracking
// Directed Acyclic Graph

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>
#include<queue>
using namespace std;

void topo(int i, vector<bool> visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[i] = true;
    for (auto neighbor : adj[i])
    {
        if (!visited[neighbor])
        {
            topo(neighbor, visited, s, adj);
        }
    }
    // push node when back tracking
    s.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // call dfs for all graph components
    vector<bool> visited(v);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topo(i, visited, s, adj);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}



// topological sort using kahns algorithm
// bfs
// linear ordering DAG
// in degree
// queue
// zero in degree insert in queue
// bfs in those zero in degree queue inserted

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // finding in degree of all nodes
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    // 0 degree push in queue
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // store ans
        ans.push_back(front);

        for(auto neighbor : adj[front]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
        }   
    }
    return ans;
}

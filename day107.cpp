#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
#include <stack>
using namespace std;

template <typename t>
class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printList()
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
};

int main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges " << endl;
    graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
}

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<int> ans[n];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);

        // entering neighbors
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}
// breadth first search - traversal technique
// visited data structure unordered_map<node,bool>
// queue first in first out FIFO
void prepareAdj(unordered_map<int, set<int>> &adj, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
}
void bfs(int i, unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        // store front Node into answer
        ans.push_back(frontNode);
        // traverse all neighbors of front node
        for (auto neighbor : adj[frontNode])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdj(adj, edges);

    // disconnected components
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(i, adj, visited, ans);
        }
    }
}
// Depth First Search

void dfs(int i, unordered_map<int, list<int>> adj, unordered_map<int, bool> visited, vector<int> &component)
{
    component.push_back(i);
    visited[i] = true;

    for (auto j : adj[i])
    {
        if (!visited[j])
        {
            dfs(j, adj, visited, component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // prepare adjList
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;

    unordered_map<int, bool> visited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }
    return ans;
}

// shortest path
// src node
// adj list
// priority queue - min heap
// set pair int-distance int-node
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    // create of distance array with max int value
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert(make_pair(0, source));
    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        st.erase(st.begin());

        for (auto neighbor : adj[topNode])
        {
            if ((nodeDistance + neighbor.second < dist[neighbor.first]))
            {
                auto record = st.find(make_pair(dist[neighbor.first], neighbor.first));
                if (record != st.end())
                {
                    st.erase(record);
                }
            }
            dist[neighbor.first] = nodeDistance + neighbor.second;
            st.insert(make_pair(dist[neighbor.first], neighbor.first));
        }
    }
}

// implementing dijkrsta algorithm
vector<int> dijkstra2(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    unordered_map<int, list<pair<int, int>>> adj;
    // create an adjacency list
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    // create a distance array/vector
    vector<int> dist(vertices);

    dist[source] = 0;

    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        auto top = *(st.begin());
        int distanceNode = dist[top.first];
        int topNode = dist[top.second];

        // lets traverse through the adj list
        for (auto neighbor : adj[topNode])
        {
            if (distanceNode + neighbor.first < dist[neighbor.first])
            {
                auto record = st.find(make_pair(dist[neighbor.first], neighbor.first));
                if (record != st.end())
                {
                    st.erase(record);
                }
            }
            dist[neighbor.first] = distanceNode + neighbor.first;
            st.insert(make_pair(dist[neighbor.first], neighbor.first));
        }
    }
}

vector<int> dijkstra_3(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // build an adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> dist(vertices, INT_MAX);

    dist[source] = 0;

    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for (auto neighbor : adj[topNode])
        {
            int adjNode = neighbor.first;
            int edgeWeight = neighbor.second;
            if (nodeDistance + edgeWeight < dist[adjNode])
            {
                auto record = st.find(make_pair(dist[adjNode], adjNode));
                if (record != st.end())
                {
                    st.erase(record);
                }
                // update dist node
            dist[adjNode] = nodeDistance + edgeWeight;
            st.insert(make_pair(dist[adjNode],adjNode));
            }
            
        }
    }
}

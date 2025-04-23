// Learning graph
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <set>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    unordered_map<int, list<int>> adj;

    // adding edges
    void addEdge(int u, int v, bool isDirected)
    {
        adj[u].push_back(v);
        if (isDirected == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph(int vertices)
    {
        for (auto i : adj)
        {
            cout << i.first << "-->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    vector<int> dijktras(vector<vector<int>> &vertices, int n, int source)
    {
        vector<int> distance(n);
        for (int i = 0; i < n; i++)
        {
            distance[i] = INT_MAX;
        }
        set<pair<int, int>> st;
        distance[source] = 0;
        st.insert(0, source);

        while (!st.empty())
        {
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;

            st.erase(st.begin());
            while (!st.empty())
            {
                for (auto neighbor : adjList[topNode])
                {
                    if (nodeDistance + neighbor.second < distance[neighbor.first])
                    {
                        // find if record exist
                        auto record = st.find(make_pair((distance[neighbor.first]), neighbor.first));
                        if (record != st.end())
                        {
                            st.erase(record);
                        }

                        // update distance
                        distance[neighbor.first] = nodeDistance + neighbor.second;
                        st.insert(make_pair((distance[neighbor.first]), neighbor.first));
                    }
                }
            }
        }
        return distance;
    }
    // cycle detection in undirected graph using dfs
    bool dfs(int node, int parent, unordered_map<int, bool> visited, unordered_map<int, list<int>> &adj)
    {
        visited[node] = true;
        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                bool hehe = dfs(neighbor, node, visited, adj);
                if (hehe)
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

    // cycle detection in undirected graph using bfs
    bool bfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        visited[node] = true;
        queue<int> q;
        unordered_map<int, int> parent;
        parent[node] = -1;
        q.push(node);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto neighbor : adj[front])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    parent[neighbor] = front;
                }
                else if (parent[front] != neighbor)
                {
                    return true;
                }
            }
        }
    }
    // traversing connected nodes
    bool IsCyclic(int n, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
    {
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, visited, adj))
                {
                    // if(bfs(i,visited,adj)){
                    return true;
                }
            }
        }
        return false;
    }

    // shortest path in a undirected graph using bfs

    vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
    {
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
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto i : adj[front])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }
        // prepare shortest path
        vector <int> ans;
        int currentNode = t;
        ans.push_back(t);
        while(currentNode!=s){
            currentNode = parent[currentNode];
            ans.push_back(currentNode);
        }

        // reverse ans
        reverse(ans.begin(),ans.end());

        return ans;
    }

};

int main()
{

    return 0;
}
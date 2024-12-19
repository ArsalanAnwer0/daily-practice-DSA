// BFS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class graph
{
public:
    int V;
    vector<vector<int>> adj;

    graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdges(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    void BFS(int start)
    {

        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {

            int v = q.front();
            q.pop();
            cout << v << "  ";

            for (int w : adj[v])
            {
                if (!visited[w])
                {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
    }
};
int main()
{
    graph g(5);
    g.addEdges(0, 1);
    g.addEdges(0, 4);
    g.addEdges(1, 2);
    g.addEdges(1, 3);
    g.addEdges(1, 4);
    g.addEdges(2, 3);
    g.addEdges(3, 4);

    cout << "BFS starting from vertex 0: ";
    g.BFS(0); // Call BFS starting from vertex 0
    cout << endl;

    return 0;
}
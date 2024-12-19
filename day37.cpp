// DFS
#include <iostream>
#include <stack>
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
    void DFS(int start)
    {

        vector<bool> visited(V, false);
        stack<int> s;

        visited[start] = true;
        s.push(start);

        while (!s.empty())
        {

            int v = s.top();
            s.pop();
            cout << v << "  ";

            for (int w : adj[v])
            {
                if (!visited[w])
                {
                    visited[w] = true;
                    s.push(w);
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

    cout << "DFS starting from vertex 0: ";
    g.DFS(0); // Call DFS starting from vertex 0
    cout << endl;

    return 0;
}
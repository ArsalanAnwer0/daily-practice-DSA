// how to represent a graph using adjancency list

#include <iostream>
#include <vector>
using namespace std;
class graph
{
public:
    int V; // an integer that stores number of vertices in our graph
    vector<vector<int>> adj;

    // constructor
    graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    // add edges
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    // displaying our adjancency list
    void display()
    {
        for (int v = 0; v < V; v++)
        {
            cout << "Vector: " << v << ": ";
            for (int w : adj[v])
            {
                cout << " -> " << w << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
int main()
{
    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display(); // Display the graph

    return 0;
}
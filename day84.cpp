#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void BFS(int startVertex)
    {
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (auto neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};
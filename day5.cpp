#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class graph
{
private:
    unordered_map<int, vector<int>> adjacencyList;

public:
    void addEdge(int v, int w)
    {

        adjacencyList[v].push_back(w);
        adjacencyList[w].push_back(v);
    }

    void BFS(int startVertex)
    {

        vector<bool> visited(adjacencyList.size(), false);

        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {

            int currentVertex = q.front();
            q.pop();

            cout << currentVertex << " ";

            for (int neighbor : adjacencyList[currentVertex])

                if (!visited[neighbor])
                {

                    visited[neighbor] = true;
                    q.push(neighbor);
                }
        }
    }
};

int main()
{

    return 0;
}
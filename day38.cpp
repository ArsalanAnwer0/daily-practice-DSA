// learning graph after doing DFS and BFS using iteration and also learning how to represent graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class graph
{
public:
    // creating a adjacency list
    vector<vector<int>> adjacencyList;
    int size;

    // constructor to resize our graph
    graph(int size)
    {
        this->size = size;
        adjacencyList.resize(size);
    }

    void addEdge(int w, int v)
    {
        adjacencyList[v].push_back(w);
        adjacencyList[w].push_back(v);
    }
    void printGraph()
    {

        for (int i = 0; i < size; i++)
        {
            cout << i << " --> ";
            for (int w : adjacencyList[i])
            {
                cout << w << " ";
            }
            cout << endl;
        }
    }
    // BFS

    // how can i code BFS
    void BFS(int start)
    {
        queue<int> q;
        vector<bool> visited(size,false);
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            cout << temp << " ";

            for(int w: adjacencyList[temp]){
                if(!visited[w]){
                    visited[w] = true;
                    q.push(w);
                }
            }
        }



    }
};

// DFS

int main()
{

    // this is a adjacency list to represent graph
    graph g(5);
    g.addEdge(0, 1); // Connect vertex 0 and 1
    g.addEdge(0, 2); // Connect vertex 0 and 2
    g.addEdge(1, 2); // Connect vertex 1 and 2
    g.addEdge(1, 3); // Connect vertex 1 and 3
    g.addEdge(3, 4); // Connect vertex 3 and 4

    g.printGraph();

    return 0;
}
// BFS 

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Algorithm for Breadth-First Search (BFS):
// 1. Start with a given vertex (startVertex)
// 2. Mark startVertex as visited and add it to a queue
// 3. While the queue is not empty:
//    a. Remove the first vertex from the queue (currentVertex)
//    b. Process currentVertex (in this case, print it)
//    c. For each unvisited neighbor of currentVertex:
//       - Mark it as visited
//       - Add it to the queue
// 4. Repeat step 3 until the queue is empty

class Graph {
private:
    // Adjacency list to represent the graph
    unordered_map<int, vector<int>> adjacencyList;

public:
    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
        adjacencyList[w].push_back(v);  // For undirected graph
    }

    // Breadth First Search implementation
    void BFS(int startVertex) {
        // Vector to keep track of visited vertices
        vector<bool> visited(adjacencyList.size(), false);
        
        // Queue for BFS traversal
        queue<int> q;

        // Step 2: Mark the start vertex as visited and enqueue it
        visited[startVertex] = true;
        q.push(startVertex);

        // Step 3: Continue until the queue is empty
        while (!q.empty()) {
            // Step 3a: Dequeue a vertex from queue
            int currentVertex = q.front();
            q.pop();

            // Step 3b: Process currentVertex (print it)
            cout << currentVertex << " ";

            // Step 3c: Get all adjacent vertices of the dequeued vertex currentVertex
            for (int neighbor : adjacencyList[currentVertex]) {
                // If an adjacent has not been visited, then mark it visited and enqueue it
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    // Create a graph object
    Graph g;

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // Perform BFS starting from vertex 2
    cout << "Breadth First Traversal (starting from vertex 2): ";
    g.BFS(2);

    return 0;
}



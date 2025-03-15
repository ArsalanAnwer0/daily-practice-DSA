#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

// Simpler version using adjacency list represented as vector of vectors
class Graph {
private:
    int V; // number of vertices
    vector<vector<int>> adj; // adjacency list

public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add edge between two vertices
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's undirected graph
    }

    // BFS approach to detect cycle
    bool hasCycleBFS(int start) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()) {
            int current = q.front();
            q.pop();

            // Check all neighbors of current vertex
            for(int neighbor : adj[current]) {
                if(!visited[neighbor]) {
                    // If not visited, mark it visited and add to queue
                    visited[neighbor] = true;
                    q.push(neighbor);
                    parent[neighbor] = current;
                }
                // If neighbor is visited and not parent, we found a cycle
                else if(parent[current] != neighbor) {
                    return true;
                }
            }
        }
        return false;
    }

    // DFS approach to detect cycle
    bool hasCycleDFS(int current, int parent, vector<bool>& visited) {
        visited[current] = true;

        // Check all neighbors
        for(int neighbor : adj[current]) {
            if(!visited[neighbor]) {
                if(hasCycleDFS(neighbor, current, visited))
                    return true;
            }
            // If neighbor is visited and not parent, we found a cycle
            else if(neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    // Main function to check for cycles
    string detectCycle() {
        vector<bool> visited(V, false);
        
        // Check all vertices (handles disconnected components)
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                // Use either BFS or DFS (uncommment one)
                if(hasCycleBFS(i))
                    return "YES";
                
                // if(hasCycleDFS(i, -1, visited))
                //     return "YES";
            }
        }
        return "NO";
    }
};

// Example usage
int main() {
    // Create a graph with 4 vertices
    Graph g(4);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0); // This creates a cycle

    // Check for cycle
    cout << "Does the graph have a cycle? " << g.detectCycle() << endl;

    return 0;
}





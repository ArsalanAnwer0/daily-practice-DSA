// practicing all of graph

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

class graph{
    public:
    unordered_map<int,list<int> > adjList;
    vector<vector<int>> adjMatrix;
    int vertices;

    // Constructor to initialize the adjacency matrix
    graph(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v, bool isDirected){
        adjList[u].push_back(v);
        if(isDirected == 0){
            adjList[v].push_back(u);
        }
    }

    // Modified printAdjList for better formatting
    void printAdjList(){
        for(auto i: adjList){
            cout << i.first << " --> ";
            for(auto j: i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // Add edge to adjacency matrix
    void addEdgeMatrix(int u, int v, bool isDirected) {
        adjMatrix[u][v] = 1;
        if(isDirected == 0) {
            adjMatrix[v][u] = 1;
        }
    }

    // Print adjacency matrix
    void printAdjMatrix() {
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    

};

int main(){
    // Example usage
    graph g(5); // Create a graph with 5 vertices

    // Adding edges to both representations
    g.addEdge(0, 1, 0);
    g.addEdge(0, 4, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 0);

    g.addEdgeMatrix(0, 1, 0);
    g.addEdgeMatrix(0, 4, 0);
    g.addEdgeMatrix(1, 2, 0);
    g.addEdgeMatrix(1, 3, 0);
    g.addEdgeMatrix(1, 4, 0);
    g.addEdgeMatrix(2, 3, 0);
    g.addEdgeMatrix(3, 4, 0);

    cout << "Adjacency List:" << endl;
    g.printAdjList();

    cout << "\nAdjacency Matrix:" << endl;
    g.printAdjMatrix();
             
    return 0;
}


// Learning Graph
// Cyclic Acyclic
// undirected and directed graph
// degree
// directed graph in degree and out degree
// weighted graph
// adjacency matrix
// adjacency list
// 2D matrix
//  implementation

#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int> > adj;

    void addEdges(int u, int v,bool direction){
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    } 

    void printAdjacencyList(){
        for(auto i:adj){                    // 1. Iterate through each vertex in the map
            cout << i.first << "-->";       // 2. Print vertex number (key of the map)
            for(auto j: i.second){          // 3. Iterate through connected vertices (list)
                cout << j << ", ";          // 4. Print each connected vertex
            }
            cout << endl;                   // 5. New line after each vertex's list
        }
    }

    void findDegree(int vertex){
        cout << "Degree of vertex " << vertex << " is : "
        << adj[vertex].size() << endl;
    }
};

// breadth first search traversal technique

// print neighbors

// a data structure to check and keep note
// of what is printed
// unordered_map <node,bool>

// queue first in first out

// step 1: add vertex in queue
// ste 2: remove from queue store in frontNode 
// step 3: mark as visited
// step 4: print from frontNode;
// step 5: put neighbors of frontNode in queue
// step 6:  repeat

void prepareAdjList(unordered_map<int, list<int> > &adjList,vector<int,int> &edges){
    // creating adjacency list
    for(int i = 0; i<edges.size(); i++){
        int  u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }
}

void bfs(unordered_map<int, list<int> > &adjList,unordered_map<int,bool> &visited,
        vector<int> &ans,int node){
            queue<int> q;
            q.push(node);
            visited[node] = 1;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                // store frontNode into answer
                ans.push_back(frontNode);
                // traverse all neighbors of frontNode
                for(auto i: adjList[frontNode]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
            }
}
vector<int> BFS(int vertex, vector<int,int> edges){
    unordered_map<int, list<int> > adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    prepareAdjList(adjList,edges);
    // traverse all components of a graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
}


void BFS(int startVertex){
        unordered_map <int,bool> visited;

        queue<int> q;

        q.push(startVertex);
        visited[startVertex] = true;

        while(!q.empty()){
            int current = q.front();
            q.pop();

            cout << current << " ";

            for(auto neighbor : adj[current]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] =  true;
                }
            }
        }
}





int main(){

    return 0;
}


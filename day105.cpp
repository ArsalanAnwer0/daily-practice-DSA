// learning graph
#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

class Graph{
    public:
    unordered_map<int,list<int> > adj;

    void addEdge(int u,int v, bool isDirected){
        adj[u].push_back(v);
        if(!isDirected){
            adj[v].push_back(u);
        }
    }

    // represent adj list
    void adjPrint(){
        for(auto i : adj){
            cout << i.first << "-->";
            for(auto j:i.second){
                cout << j << ", ";
            }
            cout << endl;
            
        }
        cout << endl;
    }

    // learning BFS
    void BFS(int startVertex, queue<int>&q,unordered_map<int,bool>&visited){

        q.push(startVertex);
        visited[startVertex] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cout << front << " ";

            for(auto neighbor : adj[front]){
                if(!visited[neighbor]){
                     visited[neighbor] = true;
                     q.push(neighbor);
                }
            }
        }
    }
    
};

int main(){

    Graph g;
    g.addEdge(2, 3, false);
    g.addEdge(5, 1, false);
    g.addEdge(5, 2, false);
    g.addEdge(5, 3, false);
    g.addEdge(4, 8, false);
    g.addEdge(3, 6, false);

    g.adjPrint();
    queue<int> q;
    unordered_map<int,bool> visited;
    g.BFS(5,q,visited);

    return 0;
}
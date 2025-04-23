// code graph
#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include<limits.h>
#include<utility>

using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    vector<pair<pair<int, int>, int>> adjList;
    // creating an adjList

    vector<pair<pair<int, int>, int>> function(int nodeCount, int EdgeCount,
                                               vector<pair<pair<int, int>, int>> edgeList)
    {
        for (int i = 0; i < nodeCount;
             i++)
        {
            int u = edgeList[i].first.first;
            int v = edgeList[i].first.second;
            int w = edgeList[i].second;

            adjList.push_back({{u, v}, w});
            adjList.push_back({{v, u}, w});
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        return adjList;
    }
    // printing adjList
    void printGraph(){
        for(const auto& i:adj){
            int vertex = i.first;
            const list<pair<int,int>>& neighbors = i.second;
            cout << vertex << "-->" ;
            for(const auto& neighbor : neighbors){
                cout << "(" << neighbor.first << "," << neighbor.second << "),";
            }
            cout << endl;
        }
    }

    bool bfsCyclic(int node,unordered_map<int,bool>&visited){
        visited[node] = true;
        queue<int> q;
        q.push(node);
        unordered_map<int,int> parent;
        parent[node] = -1;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neighbor : adj[front]){
                if(!visited[neighbor.first]){
                    q.push(neighbor.first);
                    parent[neighbor.first] = front; 
                }
                // means visited
                else if(parent[front] != neighbor.first){
                    return true;
                }
            }
        }
        return false;
    }

    // cycle detection in a undirected graph using BFS

    // traversing entire graph
    bool isCyclic(int nodes,unordered_map<int,bool>& visited){
        for(int i=0;i<nodes;i++){
            if(!visited[i]){
                if(bfsCyclic(i,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{

}
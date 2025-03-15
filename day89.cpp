// learning Graph concepts
#include<iostream>
#include<unordered_map>
#include<queue>
#include<stack>
#include<list>

using namespace std;

class graph{
    public:
    unordered_map<int,list<int> > adj;

    void addEdge(int u,int v, bool isDirected){
        adj[u].push_back(v);

        if(isDirected == 0){
            adj[v].push_back(u);
        }
    }
    void printGraph(){
        for(auto i:adj){
            cout << i.first << "-->";
            for(auto j: i.second){
                cout << j << endl;
            }
            cout << endl;
        }
    }
    // Breadth first search
    vector<int> BFS(int startVertex, unordered_map<int,bool>& visited){
        vector<int> ans;
        visited[startVertex] = true;
        queue<int> q;
        q.push(startVertex);

        while(!q.empty()){
            int current = q.front();
            ans.push_back(current);
            q.pop();

            for(auto neighbor: adj[current]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            
        }
        return ans;
    }
    // depth first search
    vector<int> DFS(int startVertex, unordered_map<int,bool>& visited, int v){
        vector<int> ans;
        visited[startVertex] = true;
        stack<int> s;
        s.push(startVertex);

        while(!s.empty()){
            int current = s.top();
            s.pop();
            ans.push_back(current);

            for(auto neighbor: adj[current]){
                if(!visited[neighbor]){
                    s.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            
        }
        return ans;
    }
    bool DFSCycle(int node,int parent,unordered_map<int,bool>& visited){
        visited[node] = true;
        for(auto neighbor: adj[node]){
            if(!visited[neighbor]){
                if(DFSCycle(neighbor,node,visited)){
                    return true;
                }
                else if(parent != neighbor){
                    return true;
                }
            }
        }
        return false;
    }
    // for disconnected components
    bool IsCyclic(int n,unordered_map<int,bool>& visited){
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool Cyclic = DFSCycle(i,-1,visited);
                if(Cyclic){
                    return true;
                }
            }
        }
        return false;
    }

};

int main(){

    return 0;
}

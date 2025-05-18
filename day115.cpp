#include<iostream>
#include<list>
#include<unordered_map>
#include<set>
#include<utility>
#include<vector>

using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u,int v,bool direction){
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }
    void printAdj(){
        for(auto i:adj){
            cout << i.first << "-->";
            for(auto j:i.second){
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

vector<vector<int>> printAdjacency(int n,int m,vector<vector<int>>&edges){
    
    
    vector<vector<int>> ans(n);
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int> > adj;
    for(int i=0; i<n; i++) {
        vector<int> temp;
        temp.push_back(i);
        for(int j=0; j<ans[i].size(); j++) {
            temp.push_back(ans[i][j]);
        }
        adj.push_back(temp);
    }
    return adj;
}
void prepareAdj(unordered_map<int,list<int> >& adj,vector<pair<int,int> > &edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void bfs(unordered_map<int,list<int> >& adj,unordered_map<int,bool>& visited,vector<int> ans,int i){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto neighbor:adj[front]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int,int> > &edges){
    // prepare adjacency list
    unordered_map<int,list<int> > adj;
    vector<int> ans;

    unordered_map<int,bool> visited;

    prepareAdj(adj,edges);

    // check all components
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }
    return ans;
}  

dfs

vector<vector<int>> depthFirstSeacrch(int v,int e,vector<vector<int>> &edges){
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);  
        adj[v].push_back(u);
    }
    vector<vector<int> > ans;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adj,visited,i);
            ans.push_back(component);
        }
    }
    
}

int main(){
    int n;
    cout << "Enter the number of nodes ";
    cin >> n;
    int m;
    cout << "Enter the number of edges ";
    cin >> m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v,0);
    }
    g.printAdj();
    return 0;
}



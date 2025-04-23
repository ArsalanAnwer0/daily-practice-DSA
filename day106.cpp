// Revising Graph
// Directed and Undirected Graph
// Indegree and Outdegree
// weighted graph 
// Cyclic and Acyclic
// Representation of graph
// Adjacency Matrix Adjacency List
#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<queue>
#include<set>

using namespace std;

// class graph{
//     public:
//     unordered_map<int,list<int> > adj;

//     void addEdge(int u, int v, bool direction){
//         // direction = 0 -> undirected graph
//         // direction = 1 -> directed graph
//         // create an edge from u to v
//         adj[u].push_back(v);

//         if(direction == 1){
//             adj[v].push_back(u);
//         }
//     }
//     void printAdjList(){
//         for(auto i:adj){
//             cout << i.first << "-->";
//             for(auto j:i.second){
//                 cout << j << ", ";
//             }
//             cout << endl;
//         }
//     }
//     // Using this approach we have to create and print
//     // adjancency list
//     // n = no of vertices
//     // m = numbers of edges
//     // edges = conncetions like 5-6 6-7
//     vector <vector<int>> printAdjcency(int n,int m,
//     vector< vector<int> > & edges){
//         vector<int> ans[n];
//         for(int i=0;i<m;i++){
//             int u = edges[i][0];
//             int v = edges[i][1];

//             ans[u].push_back(v);

//             ans[v].push_back(u);
//         }
//         vector<vector<int>> adj;
//         for(int i=0;i<n;i++){
//             adj[i].push_back(i);
//             // entering neighbors
//             for(int j=0;j<ans[i].size();j++){
//                 adj[i].push_back(ans[i][j]);
//             }
//         }  
//         return adj; 
//     }
// };

// int main(){
//     int n;
//     cout << "Enter the number of vertices " << endl;
//     cin >> n;
//     int m;
//     cout << "Enter the number of edges " << endl;
//     cin >> m;

//     graph g;

//     for(int i=0;i<m;i++){
//         int u,v;
//         cin >> u >> v;
//         g.addEdge(u,v,0);
//     }

//     // printing graph
//     g.printAdjList();
//     return 0;
// }

// a data structure to track if a node is visited or not
// we can use an unordered map for this

// we will also use queue ds 

// void prepareAdjList(unordered_map<int,set<int> > &adjList, vector<pair<int,int>> &edges){
//     for(int i=0;i<edges.size();i++){
//         int u = edges[i].first;
//         int v = edges[i].second;

//         adjList[u].insert(v);
//         adjList[v].insert(u);
//     }
// }

// void bfs(unordered_map<int,set<int> > &adjList,unordered_map<int,bool> &visited,vector<int> &ans, int node){
//     queue<int> q;
//     q.push(node);
//     visited[node] = true;

//     while(!q.empty()){
//         int frontNode = q.front();
//         q.pop();
//         ans.push_back(frontNode);

//         // traverse all neighbors of front node
//         for(auto i:adjList[frontNode]){
//             if(!visited[i]){
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//     }
// }

// vector<int> BFS(int vertex, vector<pair<int,int>> edges){
//     unordered_map<int,set<int> > adjList;
//     vector<int> ans;
//     unordered_map<int,bool> visited;
    
//     prepareAdjList(adjList,edges);

//     // check all components

//     for(int i=0;i<vertex;i++){
//         if(!visited[i]){
//             bfs(adjList,visited,ans,i);
//         }
//     }
// }
// depth first search
// void dfs(int i,unordered_map<int,list<int> >&  adjList,unordered_map<int,bool> &visited,
//     vector<int>& functionReturn){
//         functionReturn.push_back(i);
//         visited[i] = true;

//         // hr connected node k liye recursive call

//         for(auto i:adjList[i]){
//             if(!visited[i]){
//                 dfs(i,adjList,visited,functionReturn);
//             }
//         }
// }

// vector<vector<int>> depthFirstSearch(int V,int E, vector<vector<int>> &edges){
//     // create adjacency list
//     unordered_map<int,list<int> >  adjList;
//     for(int i=0;i<edges.size();i++){
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
//     vector<vector<int> >ans;
//     unordered_map<int,bool> visited;

//     // for all nodes call dfs, if not visited
//     for(int i=0;i<V;i++){
//         if(!visited[i]){
//             vector<int> functionReturn;
//             dfs(i,adjList,visited,functionReturn);
//             ans.push_back(functionReturn);
//         }
//     }
//     return ans;
// }


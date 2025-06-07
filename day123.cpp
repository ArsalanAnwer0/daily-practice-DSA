#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

vector<int> shortestPath(vector<pair<int,int>>& edges,int n,int m,int s, int t){
    // create adjacency list
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    // create adjacency list
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto neighbor: adj[front]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = front;
            }
        }
    }
    // 8 3 1
    //    CN
    // 1 3 8
    // ans   8 3 1
    // prepare shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);
    while(!currentNode!=s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(),ans.end());
    return ans;

}

int main(){


    return 0;
}
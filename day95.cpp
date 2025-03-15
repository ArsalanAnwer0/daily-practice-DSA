#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<map>
using namespace std;

// topological sort using Kahns algorithms

// directed acyclic graph

// BFS Kahn's Algorithm

// in degree

// step 1: find in degree of all nodes

// step 2: insert all 0 in degree nodes in queue

// step 3: do BFS

vector<int> topologicalSort(vector<vector<int>>&edges,
    int v,int e){
        // create adj list
        unordered_map<int,list<int> >adj;
        for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        }
        // find all indegrees
        
        // initialize indegrees vector with 0
        vector<int> indegrees(v,0);
        // iterate over each node in the adjList
        for(auto i:adj){
            // iterate over each neighbor of the i i.e node
            for(auto j:i.second){
                indegrees[j]++;
            }

        }

        // push ones with 0 in degrees

        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegrees[i] == 0){
                q.push(i);
            }
        }

        // do bfs
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();

            // ans store
            ans.push_back(front);

            // neighbor indegree
            for(auto neighbor : adj[front]){
                indegrees[neighbor]--;
                if(indegrees[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

    return ans;
}

  

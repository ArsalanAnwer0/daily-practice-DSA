#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

// Breadth First Search



class graph{
    public:
    

    // create an adjancency list;
    unordered_map<int, vector<int>> adjancencyList;

    void create(int v, int w){
        adjancencyList[v].push_back(w);
        adjancencyList[w].push_back(v);

    }

    // function for BFS

    void BFS(int start){
        unordered_map <int,bool> visited;

        visited[start] = true;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            cout << node << " ";

            for(int neighbor : adjancencyList[node]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }




    }


    



};






int main(){

    



}

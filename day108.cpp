#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<utility>

using namespace std;

vector<int> dijkrstra(vector<vector<int> >& vec,int source,int vertices, int edges){
    // first, lets create an adjacency list
    unordered_map<int,list<pair<int,int> > >adj;
    for(int i = 0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> dist(vertices,INT_MAX);

    dist[source] = 0;

    set<pair<int,int> > st;
    st.insert(0,source);

    while(!st.empty()){
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbor: adj[topNode]){
            int adjNode = neighbor.first;
            int edgeDistance = neighbor.second;

            if(nodeDistance + edgeDistance < dist[adjNode] ){
                auto record = st.find(make_pair(dist[adjNode],adjNode));
                if(record != st.end()){
                    st.erase(record);
                }
                // update the dist vector
                dist[adjNode] = nodeDistance + edgeDistance;
                // insert the new record to st set
                st.insert(make_pair(dist[adjNode],adjNode));
            }
        }
    }
}
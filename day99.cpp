// Dijkstra's Shortest path
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<list>
#include<set>
using namespace std;


vector<int> dijkstras(vector<vector<int> >&vec, int vertices, int edges, int source){
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i = 0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
        
    }

    vector<int> distance(vertices);
    for(int i =0;i<vertices;i++){
        distance[i] = INT_MAX;
    }
    set<pair<int,int> > st;

    distance[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        auto top = *(st.begin());
        int nodeDistance = top.first;

        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbor : adj[topNode]){
            if(nodeDistance + neighbor.second < distance[neighbor.first]){
                auto record = st.find(make_pair(distance[neighbor.first], neighbor.first));
                // we record found
                if(record != st.end()){
                    st.erase(record);
                }

                // distance update
                distance[neighbor.first] = nodeDistance + neighbor.second;
                st.insert(make_pair(distance[neighbor.first], neighbor.first));


            }
        }

        return distance;

    }


}

int main() {
    // Test case: Create a simple graph with 4 vertices
    vector<vector<int>> graph = {
        {0, 1, 2},  // edge from vertex 0 to 1 with weight 2
        {0, 2, 4},  // edge from vertex 0 to 2 with weight 4
        {1, 2, 1},  // edge from vertex 1 to 2 with weight 1
        {2, 3, 3}   // edge from vertex 2 to 3 with weight 3
    };

    int vertices = 4;
    int edges = 4;
    int source = 0;

    vector<int> shortestDistances = dijkstras(graph, vertices, edges, source);

    cout << "Shortest distances from source vertex " << source << ":\n";
    for(int i = 0; i < vertices; i++) {
        cout << "To vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
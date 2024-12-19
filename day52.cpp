// Quote of the day
// Sweat more in practice, so you bleed less in war

// implementing BFS
#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>

using namespace std;

class graph{
public:

// represent adjacency list

unordered_map <int, vector<int> > adjacencyList;

// methods 

// for creating a graph
void addEdge(int v, int w){
	adjacencyList[v].push_back(w);
	adjacencyList[w].push_back(v);

}

void BFS(int startVertex){
	
	// just a vector which have everything marked as false initially
	vector<bool> visited(adjacencyList.size(),false);
	
	
	// creating a queue
	queue<int> q;
	
	// marking startVertex as visited before enqueueing it
	visited[startVertex] = true;
	q.push(startVertex);

	cout << "DFS: ";
	while(!q.empty()){
	int currentVertex =  q.front();
	q.pop();
	cout << currentVertex << " ";
	

	// using for range based loop to check if neighbor of the currentVertex are visited
	// if not we mark them as visited and enqueue them. 
	
	for(int neighbor : adjacencyList[currentVertex]){	
	if(!visited[neighbor]){	
	visited[neighbor] = true;
	q.push(neighbor);
	}
	}	

	}

}	


};
 
int main(){

	graph g;
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,6);
	g.addEdge(4,6);

	g.BFS(1);	


return 0;
}

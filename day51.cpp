// Quote of the day
// Sweat more during practice so you bleed less during war.
// Implementing Graph

#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>

using namespace std;

class graph{
public:

unordered_map<int, vector<int> > adjacencyList;

// constructor



// creating a function to connect nodes using an edge

void addEdge(int v,int w){
adjacencyList[v].push_back(w);
adjacencyList[w].push_back(v);
}

void DFS(int startVertex){

vector <bool> visited(adjacencyList.size(),false);

stack<int> s;

visited[startVertex] = true;
s.push(startVertex);

while(!s.empty()){

	int currentVertex = s.top();
	s.pop();
	
	// printing current vertex
	
	cout << currentVertex << " ";
	
	// for range based loop
	for(int w : adjacencyList[currentVertex]){
	if(!visited[w]){
	visited[w] = true;
	s.push(w);	
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


	g.DFS(1);
	


return 0;
}


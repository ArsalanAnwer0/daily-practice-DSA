// motivation of the day
// Be so good they can't ignore you
// represent an adjacency List
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class graph{
public:

unordered_map <int,vector<int> > adjacencyList;
int size;

// constructor
graph(){}
void addEdge(int v, int w){	
	adjacencyList[v].push_back(w);
	adjacencyList[w].push_back(v);
	}
void printList(){
	for(int i=1;i<=size;i++){
		if(adjacencyList.find(i) == adjacencyList.end()){
		continue;
		}	
		cout << i << " --> ";
		for(int w: adjacencyList[i]){
		cout << w << " ";
		}
	cout << endl;
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

	g.printList();
}

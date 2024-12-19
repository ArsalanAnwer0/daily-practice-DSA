// Heap
// Graph
// Hash Maps
#include<iostream>
#include<utility>
#include<list>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class heap{
public:
int *arr;
int capacity;
int size;
// constructor
heap(int capacity){
	this->capacity = capacity;
	size = 0;
	arr = new int[capacity + 1];	
}

// inserting in a heap
void insertHeap(int element){
	size++;
	int index = size;	
	arr[index] = element;
	

	// taking the inserted element to its right position
	while(index > 1){
	int parent = index / 2;
	if(arr[index] > arr[parent]){
	swap(arr[index],arr[parent]);
	index = parent;
	}
	else{
	break;
	}
	}
	}
void deleteHeap(){	
arr[1] = arr[size];
size --;

int index = 1;
while(index <= size / 2){
	int leftChild = 2 * index;
	int rightChild = 2 * index + 1;
	int largest = index;
	if(leftChild <= size && arr[largest] < arr[leftChild]){
	largest = leftChild;
	}
	if(rightChild <= size && arr[largest] < arr[rightChild]){
	largest = rightChild;
	}
	if(largest != index){
	swap(arr[largest],arr[index]);
	index = largest;
	}
	else{
	break;
	}
	}
}
void printHeap(){	
	cout << "Heap: ";
	for(int i=1;i<=size;i++){
	cout << arr[i] << " ";
	}
	cout << endl;
}
// build heap
void toBuildHeap(int temp_arr[],int tempSize){
	for(int i = 1; i<= tempSize; i++){
	arr[i] = temp_arr[i];
	}
	cout << "Checking: ";
	for(int i=1;i<=tempSize;i++){
	cout  << arr[i] << " ";
	}
	cout << endl;
	//size = tempSize - 1;
	size = tempSize;
}
void helper(){
	for(int i=size/2;i>=1;i--){
	heapify(i,size);
	}
	}
// heapify
void heapify(int index,int tempSize){
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int largest = index;
        if(leftChild <= tempSize && arr[largest] < arr[leftChild]){
        largest = leftChild;
        }
        if(rightChild <= tempSize && arr[largest] < arr[rightChild]){
        largest = rightChild;
        }
        if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(largest,tempSize);
	}
        }
void heapSort(int arr[],int size){
	toBuildHeap(arr,size);
	for(int i=size; i>=1; i--){
	swap(arr[1],arr[i]);
	size--;	
	helper();
	}
}
};

int main(){

heap h1(10);
int array[6] = {-1,45,32,123,78,5};
h1.heapSort(array,5);
h1.printHeap();


	return 0;
}

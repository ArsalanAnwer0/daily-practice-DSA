// Final Test coding
// List
// Tree BT BST Traversal using recursion and iteration
// Heap Heapify Heap Sort
// Graph Adjacency List Adjancency Matrix MST Shortest path
#include<iostream>
#include<list> // to use list
#include<vector> // to use vector 
#include<unordered_map>
#include<set> // to use set
#include<utility> // to use pair
#include<queue> // to use queue
#include<stack> // to use stack
#include<algorithm> // to use swap

using namespace std;

// Heap Sort

// Array -> Max Heap 0(n)
// Max element to the last element size -- and then heapify
// Repeat this process till size > 1
// 

// Array to covert Max Heap

void heapSort(int arr[], int n){
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        Heapify(arr,0,i);
    }
}


// Step down
void Heapify(int arr[],int index,int n){
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if(leftChild < n && arr[leftChild] > arr[largest] ){
        largest = leftChild;
    }
    if(rightChild < n && arr[rightChild] > arr[largest]){
        largest = rightChild;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        Heapify(arr,largest,n);
    }
}

int main(){



    return 0;
}
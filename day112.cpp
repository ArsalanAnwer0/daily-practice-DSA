#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// Heap is a data structure complete binary Tree 
// that comes with a heap order property
// What is complete Binary Tree CBT
// CBT every level is completly filled except the last level
// nodes always added from the left
// nodes always lean towards the left
// max heap 
// using array representation
class heap{
    public:
    int arr[100];
    int size;

    heap(){
        size  = 0;
    }
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    // deletion in heap
    // we delete root
    void deleteNode(){
        // if size if zero that means no element present in heap
        if(size == 0){
            cout << "Nothing to delete";
            return;
        }
        // insert last element to the root element
        arr[1] = arr[size];
        size -- ;
        // take new root node to its correct position
        int i = 1;
        while(i<size){
            int leftChild = 2*i;
            int rightChild = 2*i+1;

            if(leftChild < size && arr[i] < arr[leftChild]){
                swap(arr[i],arr[leftChild]);
                i = leftChild;
            }
            if(rightChild < size && arr[i] < arr[rightChild]){
                swap(arr[i],arr[rightChild]);
                i = rightChild;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout << arr[i] << " ";
        }
    }
};
// Heapify

void heapify(int arr[], int n, int i){
    int largest= i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if (largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void BuildHeap(int arr[], int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

// heap sort

// complexity n logn 

void heapSort(int arr[], int n){
    int size = n;

    while(size >  1){
        // step 1: swap
        swap(arr[size],arr[1]);
        size--;

        // step 2: heapify the new root node
        heapify(arr,n,1);
    }
}

// Priority Queue - Min Heap - Max heap



int main(){
    heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    h1.print();

    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    cout << "Element at top : " << pq.top() << endl;
    pq.pop();
    cout << "Element at top: " << pq.top() << endl;
    cout << "Size is " << pq.size() << endl;
    if(pq.empty()){
        cout << "pq is empty" << endl;
    }
    else{
        cout << "pq is not empty" << endl;
    }

    // min heap

    priority_queue<int,vector<int>,greater<int> > minHeap;
    




    return 0;
}

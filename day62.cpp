// Heap
#include<iostream>
using namespace std;
void heapify(int arr[],int size,int index);
void buildHeap(int arr[], int size);
class heap{
    public:
    int* arr;
    int size;

    // constructor
    heap(){
        size = 0;
        arr = new int[100];
    }
    void insertInHeap(int value){
        // Step 1: Inserting the element at the last position
        size++;
        int index = size;
        arr[index] = value;
        // Step 2: taking the inserted element to its last position
        while(index > 1){
            int parent = index / 2;

            if(arr[index] > arr[parent]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    // deletion in heap
    void deletionInHeap(){
        // step 1: insert last element in the root element and decrease
        // size
        arr[1] = arr[size];
        size--;

        // take the last inserted element to its right position
        int i = 1;
        while(i < size){
            int largest = i;
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            if( arr[largest] < arr[leftChild]){
                largest = leftChild;
            }
            if( arr[largest] < arr[rightChild]){
                largest =  rightChild;
            }
            if(largest != i){
                swap(arr[largest],arr[i]);
                i = largest;
            }
            else{
                return;
            }
        }
    }
    void heapSort(){
        buildHeap(arr,size);
        int originalSize = size;
        for(int i=size;i>=1;i--){
            swap(arr[1],arr[size]);
            size--;
            heapify(arr,i,1);
        }
        size = originalSize;
    }
    void printHeap2(){
    cout << "Max Heap: ";
        for(int i=1;i<=size;i++){
            cout << arr[i] << " ";
        }
        cout <<  endl;
    }
};
    void heapify(int arr[],int size,int index){
            int largest = index;
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            if(leftChild < size && index < size - 1 && arr[largest] < arr[leftChild]){
                largest = leftChild;
            }
            if( rightChild < size && index < size && arr[largest] < arr[rightChild]){
                largest =  rightChild;
            }
            if(index < size - 1  && largest != index){
                swap(arr[largest],arr[index]);
                heapify(arr,size,largest);
            }
            else{
                return;
            }
    }
    void buildHeap(int arr[], int size){
        for(int ptr = size / 2; ptr >= 1; ptr--){
            heapify(arr,size,ptr);
        }
    }
        // print heap function
    void printHeap(int arr[], int size){
        cout << "Max Heap: ";
        for(int i=1;i<size;i++){
            cout << arr[i] << " ";
        }
        cout <<  endl;
    }

int main(){
    heap h;
    h.insertInHeap(65);
    h.insertInHeap(60);
    h.insertInHeap(55);
    h.insertInHeap(50);
    h.insertInHeap(45);
    h.heapSort();
    h.printHeap2();
    return 0;
}

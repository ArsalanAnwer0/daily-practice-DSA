// max heap
#include<iostream>

using namespace std;

class heap{
    public:
    int* arr;
    int capacity;
    int size;
    heap(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }
    void insertInHeap(int element){

        // inserting at last
        size++;
        int index = size;
        arr[index] = element;

        // taking it to its right position
        while(index>1){
            int parent = index / 2;
            if(arr[index] > arr[parent]){
                swap(arr[index],arr[parent]);
            }
            else{
                break;
            }
        }
    }
    // deleting from heap
    void deleteInHeap(){
        // check if array is not empty
        if(size == 0){
            cout << "Array is empty! " << endl;
            return;
        }
        // deleting root node
        arr[1] = arr[size];
        size--;

        int index = 1;
        while(index<=size){
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            int largest = index;

            if(leftChild <= size && arr[leftChild] > arr[largest]){
                largest = leftChild;
            }
            if(rightChild <= size && arr[rightChild] > arr[largest ]){
                largest = rightChild;
            }
            if(largest == index){
                break;
            }
            swap(arr[largest],arr[index]);
            index = largest;
        }
    }
    // lets write code for heapify now!
    void whatToHeapify(){
        for(int i=size/2;i>=1;i--){
            heapify(i);
        }
    }

    void heapify(int index){

        while(index<=size){
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            int largest = index;
            if(leftChild <= size && arr[leftChild] > arr[largest]){
                largest = leftChild;
            }
            if(rightChild <= size && arr[rightChild] > arr[largest ]){
                largest = rightChild;
            }
            if(largest == index){
                break;
            }
            swap(arr[largest],arr[index]);
            index = largest;
        }
    }
    void heapSort(){

        int originalSize =  size;

        whatToHeapify();

        while(size>1){        
      
        swap(arr[1],arr[size]);
        size--;
        heapify(1);
        }
         size = originalSize ;
    }
};
int main(){

    int arr[6] = {-1,5,7,8,3,2};
    return 0;
}
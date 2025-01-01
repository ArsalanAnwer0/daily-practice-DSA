// heap
#include <iostream>
using namespace std;

class heap
{
public:
    int *arr;
    int size;
    int arraySize;
    // constructor
    heap(int arraySize)
    {
        this->arraySize = arraySize;
        size = 0;
        arr = new int[arraySize];
    }
    // insertion code
    void insertion(int value)
    {

        // check we our array is full
        if (size == arraySize)
        {
            return;
        }
        // we can insert
        // 1. step one
        size++;
        int index = size;
        arr[index] = value;

        // 2. step two
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    // printing array representation of max heap
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // deleting in a max heap
    void deleteNode()
    {

        // inserting last node at 1 position
        arr[1] = arr[size];
        size--;

        // now take the new value at position 1 to its correct position
        int index = 1;
        while (index <= size)
        {
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;

            if (leftChild < size && arr[index] < arr[leftChild])
            {
                swap(arr[index], arr[leftChild]);
                index = leftChild;
            }
            else if (rightChild < size && arr[index] < arr[rightChild])
            {
                swap(arr[index], arr[rightChild]);
                index = rightChild;
            }
            else
            {
                return;
            }
        }
    }

    // Heapify function for a specific index
    void heapify(int index) {
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int largest = index;

        if (leftChild <= size && arr[largest] < arr[leftChild]) {
            largest = leftChild;
        }
        if (rightChild <= size && arr[largest] < arr[rightChild]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapify(largest);
        }
    }

    // Heapify the entire heap (build-heap)
    void buildHeap() {
        for (int i = size / 2; i >= 1; i--) {
            heapify(i);
        }
    }

    // Heapsort implementation
    void heapsort() {
        // making sure that we have heap order property satisfied
        buildHeap();
        int originalSize = size;
        for (int i = size; i > 1; i--) {
            swap(arr[1], arr[i]);
            size--;
            heapify(1); 
        }
        size = originalSize;
    }

    // Print the heap
    void printHeap() {
        cout << "Heap elements: ";
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // Destructor
    ~heap() {
        delete[] arr;
    }
};

int main()
{
    heap h(100);
    h.insertion(65);
    h.insertion(68);
    h.insertion(61);
    h.insertion(63);
    h.buildHeap();
    h.printHeap();
    return 0;
}
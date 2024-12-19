#include <iostream>
#include <vector>
using namespace std;

// Class for implementing a Max Heap
class MaxHeap {
private:
    vector<int> heap;

    // Helper function to get the parent index of a node
    int parent(int i) { return (i - 1) / 2; }

    // Helper function to get the left child index of a node
    int leftChild(int i) { return 2 * i + 1; }

    // Helper function to get the right child index of a node
    int rightChild(int i) { return 2 * i + 2; }

    // Helper function to swap two elements in the heap
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Helper function to maintain the heap property (heapify)
    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        // Check if left child is larger than root
        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        // Check if right child is larger than largest so far
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Function to insert a new element into the heap
    void insert(int key) {
        // Add the new element to the end of the vector
        heap.push_back(key);

        // Get the index of the newly inserted element
        int i = heap.size() - 1;

        // Perform heapify-up operation
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Function to delete the maximum element (root) from the heap
    int deleteMax() {
        if (heap.empty())
            return -1; // Heap is empty

        int maxElement = heap[0];

        // Replace root with the last element
        heap[0] = heap.back();
        heap.pop_back();

        // Heapify the root element
        heapifyDown(0);

        return maxElement;
    }

    // Function to perform heap sort
    void heapSort() {
        int n = heap.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyDown(i);

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(heap[0], heap[i]);

            // Heapify the reduced heap
            heapifyDown(0);
        }
    }

    // Function to print the heap
    void printHeap() {
        for (int i : heap)
            cout << i << " ";
        cout << endl;
    }
};

// Priority Queue implementation using Max Heap
class PriorityQueue {
private:
    MaxHeap heap;

public:
    void push(int value) {
        heap.insert(value);
    }

    int pop() {
        return heap.deleteMax();
    }

    void print() {
        heap.printHeap();
    }
};

int main() {
    MaxHeap maxHeap;

    // Insert elements into the heap
    maxHeap.insert(3);
    maxHeap.insert(2);
    maxHeap.insert(1);
    maxHeap.insert(15);
    maxHeap.insert(5);
    maxHeap.insert(4);
    maxHeap.insert(45);

    cout << "Max Heap: ";
    maxHeap.printHeap();

    cout << "Deleted max element: " << maxHeap.deleteMax() << endl;

    cout << "Max Heap after deletion: ";
    maxHeap.printHeap();

    maxHeap.heapSort();
    cout << "Sorted Heap: ";
    maxHeap.printHeap();

    cout << "\nPriority Queue Demo:\n";
    PriorityQueue pq;
    pq.push(3);
    pq.push(2);
    pq.push(1);
    pq.push(15);
    pq.push(5);

    cout << "Priority Queue: ";
    pq.print();

    cout << "Popped: " << pq.pop() << endl;
    cout << "Priority Queue after pop: ";
    pq.print();

    return 0;
}

// Heap, insert, delete,heapify, heap sort 
#include <iostream>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;

    heap()
    {

        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {

        size++;
        int index = size;
        arr[index] = val;

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
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteMe()
    {

        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;

        // take root node to its correct position

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            //  Re arranging the max heap
            if (leftIndex <= size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex <= size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            // if max heap is sorted
            else
            {
                return;
            }
        }
    }
};
// array, size and index to start with.
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int size)
{
    // Build heap (rearrange array)
    for (int i = size / 2; i > 0; i--) // Ensure to start from size/2
    {
        heapify(arr, size, i);
    }

    // One by one extract elements from heap
    for (int temp = size - 1; temp > 0; temp--) // Change from temp > 1 to temp > 0
    {
        swap(arr[temp], arr[1]); // Change from arr[temp] to arr[temp + 1]
        heapify(arr, temp, 1);
    }
}
int main()
{

    heap h;
    h.insert(15);
    h.insert(20);
    h.insert(25);
    h.insert(30);
    h.print();
    h.deleteMe();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = 6;
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }
    cout << "Printing the array now:" << endl;
    for (int i = 1; i < size; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;

    // heap sort

    heapSort(arr, size);
    cout << "Print sorted array:";
    for (int i = 1; i < size; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
/*
    priority_queue<int> pq;
    pq.push(4);
    pq.push(5);
    pq.push(6);
    pq.top();

*/


    return 0;
}
#include <iostream>
using namespace std;
// heap
class heap
{

public:
    int *arr;
    int size;

    heap()
    {
        size = 0;
        arr = new int[100];
    }
    void insert(int val)
    {

        size++;
        arr[size] = val;
        int index = size;

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
    }
    void deleteMe()
    {

        if (size == 0)
        {
            cout << "Nothing to delete";
            return;
        }

        arr[1] = arr[size];
        size--;

        // take root node to its correct position
        int i = 1;
        while (i <= size)
        {

            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {

                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {

                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};
void heapify(int arr[], int size, int index)
{

    int largest = index;

    int left = 2 * index;
    int right = 2 * index + 1;

    if (index < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (index < size && arr[largest] < arr[right])
    {

        largest = right;
    }

    if (largest != index)
    {

        swap(arr[largest], arr[index]);
        cout << endl
             << "Largest: " << largest << endl;
        heapify(arr, size, largest);
    }
}
void heapSort(int arr[], int size)
{
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }
    for (int i = size; i > 1; i--) // Loop to extract elements from heap
    {
        swap(arr[1], arr[i]); // Move current root to end
        heapify(arr, i - 1, 1); // Call heapify on the reduced heap
    }
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.print();
    int arr[6] = {-1, 50, 55, 57, 52};
    int size = 5;
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }
    cout << endl
         << "printing the array now " << endl;
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;
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

    // inserting in a max heap
    void insert(int value)
    {

        // inserting value at the end of the array
        size++;

        arr[size] = value;
        int index = size;

        // taking it to the right position
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // print function
    void print()
    {

        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // deletion

    // step 1: insert last node in root
    // step 2: delete last node;
    // step 3: take root to its correct position

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

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
            }
            else
            {
                return;
            }
        }
    }
};
// heapify
void heapify(int arr[], int size, int index)
{

    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    else if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}
// heap sort
// step 1: swap krdo first element with last element
// step 2:  delete last element
// step 3: heapify
// repeat

void heapSort(int arr[], int size)
{

    for (int i = (size / 2); i > 0; i--)
    {
        heapify(arr, size, i);
    }
    for(int temp = size -1; temp > 0 ; temp--){

            swap(arr[temp],arr[1]);
            heapify(arr,temp,1);


    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    h.deleteMe();
    h.print();
    int size = 6;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    for (int i = (size / 2); i > 0; i--)
    {
        heapify(arr, size, i);
    }
    cout << "Printing the array now " << endl;
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
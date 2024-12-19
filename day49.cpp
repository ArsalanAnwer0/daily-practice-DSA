// I will be coding Heap,Graph,HashMaps
// #include<utility>
#include <iostream>
// #include<list>
// #include<vector>
// #include<queue>
// #include<stack>

using namespace std;

class heap
{
public:
	int *arr;
	int capacity;
	int size;
	// constructor
	heap(int capacity)
	{
		this->capacity = capacity;
		arr = new int[capacity + 1];
		size = 0;
	}
	// functions
	void insertHeap(int element)
	{
		size++;
		int index = size;
		arr[index] = element;

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
				break;
			}
		}
	}

	// printing heap

	void printHeap()
	{
		cout << "Heap: ";
		for (int i = 1; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void deleteHeap()
	{
		// we will be deleting root so
		arr[1] = arr[size];
		size--;
		int index = 1;
		while (index <= size)
		{
			int leftChild = 2 * index;
			int rightChild = 2 * index + 1;
			int largest = index;
			if (arr[index] < arr[leftChild])
			{
				largest = leftChild;
			}
			if (arr[index] < arr[rightChild])
			{
				largest = rightChild;
			}
			if (largest != index)
			{
				swap(arr[largest], arr[index]);
				index = largest;
			}
			else
			{
				break;
			}
		}
	}
	void heapify(int index)
	{
		int leftChild = 2 * index;
		int rightChild = 2 * index + 1;
		int largest = index;
		if (leftChild <= size && arr[largest] < arr[leftChild])
		{
			largest = leftChild;
		}
		if (rightChild <= size && arr[largest] < arr[rightChild])
		{
			largest = rightChild;
		}
		if (largest != index)
		{
			swap(arr[largest], arr[index]);
			heapify(largest);
		}
	}
	// creating heapify function
	void buildHeap(int inputArr[], int inputSize)
	{
        size = inputSize;
        for (int i = 1; i < size; i++)
        {
            arr[i] = inputArr[i];
        }

        for (int i = size / 2; i >= 1; i--)
        {
            heapify(i);
        }
    }
};

int main()
{
	heap h1(6);
	int blah[6] = {-1, 3, 7, 15, 45, 131};
	h1.buildHeap(blah, 6);

	h1.printHeap();

	return 0;
}

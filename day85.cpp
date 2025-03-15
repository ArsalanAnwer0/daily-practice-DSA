#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>

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
        size = 0;
        arr = new int[capacity + 1];
    }
    // destructor
    ~heap(){
        delete[] arr;
    }
    // insert in max heap
    void insertAtInsert(int element)
    {
        // Check if heap is full
        if (size >= capacity)
        {
            cout << "Heap is full" << endl;
            return;
        }

        // step 1: insert at last position
        size++;
        int index = size;
        arr[index] = element;

        // step 2: take the inserted element to
        // its correct position

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

    void deleteInHeap()
    {
        // Check if heap is empty
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        // we always delete root node
        // step 1: to delete first node;
        arr[1] = arr[size];
        size--;

        // new root element
        // take that to its right position

        int index = 1;
        while (index <= size)
        {
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            // assuming 1 element to be largest
            int largest = index;
            if (leftChild <= size && arr[leftChild] > arr[largest])
            {
                largest = leftChild;
            }
            if (rightChild <= size && arr[rightChild] > arr[largest])
            {
                largest = rightChild;
            }
            if (largest == index)
            {
                break;
            }
            swap(arr[largest], arr[index]);
            index = largest;
        }
    }

    void whatToHeapify(){
        for(int i = size/2; i>=1; i--){
            heapify(i);
        }
    }

    // heapify
    // array of numbers -1 5 4 2 7 8 21 
    void heapify(int index){
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            // assuming 1 element to be largest
            int largest = index;
            if (leftChild <= size && arr[leftChild] > arr[largest])
            {
                largest = leftChild;
            }
            if (rightChild <= size && arr[rightChild] > arr[largest])
            {
                largest = rightChild;
            }
            if(largest!=index){
                swap(arr[largest],arr[index]);
                heapify(largest);
            }
        }

    void heapSort(){
        // store size of heap
        int OriginalSize = size;
        while(size>1){
            swap(arr[1],arr[size]);
            size--;
            heapify(1);
        }
        size = OriginalSize;
    }
};

class graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);

        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    // print graph
    void printGraph()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void bfs(int startVertex)
    {
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (auto neighbors : adjList[current])
            {
                if (!visited[neighbors])
                {
                    q.push(neighbors);
                    visited[neighbors] = true;
                }
            }
        }
    }
    void dfs(int startVertex)
    {
        stack<int> s;
        unordered_map<int, bool> visited;

        s.push(startVertex);
        visited[startVertex] = true;

        while (!s.empty())
        {
            int current = s.top();
            s.pop();
            cout << current << " ";

            for (auto neighbors : adjList[current])
            {
                if (!visited[neighbors])
                {
                    s.push(neighbors);
                    visited[neighbors] = true;
                }
            }
        }
    }
};





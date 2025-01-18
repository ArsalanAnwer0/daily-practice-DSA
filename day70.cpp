#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>

using namespace std;

// Yaay I will implementing Linked List, Stack, Queue, Heap, Tree, BST, Graph,
// Hash Maps 

// Circular Doubly Linked List;
class node{
    public:
    int data;
    node* prev,*next;

    // constructor
    node(int value): data(value),prev(nullptr),next(nullptr){
    }
    // destructor
    ~node(){
        int val = this->data;
        if(this->next!=nullptr){
            delete this->next;
            this->next = nullptr;
        }
        cout << endl << "Memory free of " << val << endl;
        }
    };
// inserting at head
    void insertAtHead(node* &head,node* &tail, int d){
        // nothing/empty
        if(head == nullptr){
            node* newNode = new node(d);
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
            return;
        }
        // if not empty
        if(head!=nullptr){
            node* newNode = new node(d);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            tail->next = head;
        }
    }
    // inserting at tail
    void insertAtTail(node* &head,node* &tail,int d){
        // nothing/empty
        if(head == nullptr){
            node* newNode = new node(d);
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
            return;
        }
        // linked list is not empty
        if(head!=nullptr){
            node* newNode = new node(d);
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    // inserting at a position
    void insertAtPosition(node* &head,node* &tail, int pos, int d){
        // if list is empty
        // nothing/empty
        if(head == nullptr){
            node* newNode = new node(d);
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
            return;
        }
        // inserting at pos 1
        if(pos ==  1){
            insertAtHead(head,tail,d);
            return;
        }
        // middle node
        int count = 1;
        node* temp = head;
        while(count < pos - 1){
            temp = temp -> next;
            count++;
        }
        // we are the postion to insert
        node* newNode = new node(d);
        if(temp->next == head){
            tail = newNode;
        }
        newNode->next = temp->next;
        temp->next =  newNode;
        newNode->prev = temp;
    }

    // deleteNode (head,tail,middle)
    void deleteNode(node* &head,node* & tail, int pos){
        // check if list is empty
        if(head == nullptr){
            cout << "Nothing to delete!" << endl;
            return;
        }
        // check if we are inserting at first position
        else if(pos == 1){
          node* temp = head;
          head = temp->next;
          temp->next = nullptr;
          head->prev = nullptr;
          tail->next = head;
          delete temp;
          return;
        }
            int count = 0;
            node* curr = head;
            node* previous = nullptr;
        // there is smth we can delete
      
            while(count < pos - 1){
                count++;
                previous = curr;
                curr = curr->next;
            }
            // now we are where we have to delete
            // check we are deleting last node
            if(curr->next == head){
                tail = previous;
            }
            previous->next = curr->next;
            curr->next->prev = previous;
            curr->next = nullptr;
            curr->prev = nullptr;
            delete curr;
        }     
    // print function to print linked list
    void printLL(node* head,node* tail){
        node* temp = head;
        do{
            cout << temp -> data << " ";
            temp = temp->next;
        }while(temp!=head);
        cout << endl;
        cout << "Head: " << head->data << endl;
        cout << "Tail: " << tail->data << endl;
    }

class heap {
public:
    int arr[100]; // Increase array size for inserts
    int size;

    // Constructor
    heap() {
        size = 0;
        cout << "Enter the number of elements in the heap: ";
        int n;
        cin >> n;
        cout << "Enter array elements: ";
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        size = n;
        cout << endl;
    }

    // Insert in heap
    void insertHeap(int value) {
        size++;
        int index = size;
        arr[index] = value;

        // Adjust position
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    // Delete root from heap
    void deleteHeap() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int index = 1;
        while (index <= size) {
            int largest = index;
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;

            if (leftChild <= size && arr[largest] < arr[leftChild]) {
                largest = leftChild;
            }
            if (rightChild <= size && arr[largest] < arr[rightChild]) {
                largest = rightChild;
            }
            if (index != largest) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else {
                return;
            }
        }
    }

    // Heapify to maintain heap property
    void heapify(int i) {
        int largest = i;
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        if (leftChild <= size && arr[largest] < arr[leftChild]) {
            largest = leftChild;
        }
        if (rightChild <= size && arr[largest] < arr[rightChild]) {
            largest = rightChild;
        }
        if (i != largest) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Build heap
    void helper() {
        for (int i = size / 2; i >= 1; i--) {
            heapify(i);
        }
    }

    // Heap sort
    void heapSort() {
        helper(); // Build max heap
        int originalSize = size;

        for () {
            swap(arr[1], arr[i]); // Move root to the end
            size--;
            heapify(1); // Restore heap property
        }

        size = originalSize; // Reset size
    }

    // Print heap
    void printHeap() {
        cout << "Heap array: ";
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;

    cout << "Original heap array: ";
    h.printHeap();

    h.heapSort();

    cout << "Sorted array: ";
    h.printHeap();

    return 0;
}
// Linked List
// Stack
// Queue
// Tree
// BST
// Heap
// DFS BFS
#include <iostream>
using namespace std;

class stack
{
public:
    int *arr;
    int size;
    int top;

    stack(int size) : size(size)
    {
        arr = new int[100];
        top=0;
    }

    void push(int element)
    {

        if (top == size)
        {
            cout << "Stack overflow: " << endl;
        }
        else
        {
            arr[top] = element;
            top++;
        }
    }
    void pop()
    {
        if (empty())
        {
            cout << "Stack is empty " << endl;
        }
        else
        {
            top--;
        }
    }
    bool empty()
    {
        if (top == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void peek()
    {
        if (!empty())
        {
            cout << "Peek: " << arr[top-1] << endl;
        }
        else
        {
            cout << "Stack is empty " << endl;
        }
    }
};

class node
{
public:
    int data;
    node *next;

    node(int value) : data(value), next(nullptr) {}

    // my own destructor

    ~node()
    {

        int val = this->data;
        if (this->next != nullptr)
        {

            delete this->next;
            this->next = nullptr;
        }
        cout << "Memory free of " << val << endl;
    }
};

void insertAtHead(node *&head, node *&tail, int val)
{
    if (head == nullptr)
    {
        node *newNode = new node(val);
        head = newNode;
        tail = newNode;
        return;
    }
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
}
void printLL(node *head, node *tail)
{

    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
}
void insertAtTail(node *&head, node *&tail, int val)
{

    if (tail == nullptr)
    {
        node *newNode = new node(val);
        tail = newNode;
        head = newNode;
        return;
    }
    node *newNode = new node(val);
    tail->next = newNode;
    tail = newNode;
}
void insertAtAnyPosition(node *&head, node *&tail, int pos, int val)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, val);
        return;
    }

    int count = 1;
    node *temp = head;
    while (count < pos - 1)
    {

        count++;
        temp = temp->next;
    }
    node *newNode = new node(val);
    if (temp->next == nullptr)
    {
        tail = newNode;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(node *&head, node *&tail, int pos)
{

    if (pos == 1)
    {
        node *temp = head;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    int count = 0;
    node *curr = head;
    node *prev = nullptr;
    while (count < pos - 1)
    {

        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr->next == nullptr)
    {
        tail = prev;
    }

    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
}
int main()
{
    // node *head = nullptr;
    // node *tail = nullptr;
    // insertAtHead(head, tail, 5);
    // insertAtTail(head, tail, 10);
    // insertAtAnyPosition(head, tail, 2, 9);
    // deleteNode(head, tail, 3);
    // printLL(head, tail);

    stack s(5);
    s.push(5);
    s.peek();
    s.pop();
    cout << boolalpha << s.empty();
    

    return 0;
}

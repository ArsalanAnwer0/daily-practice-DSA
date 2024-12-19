#include <iostream>
#include <queue>
using namespace std;

void print(int age)
{
    cout << "My age is " << age << endl;
}

class Queue{
    public:
    int* arr;
    int size;
    int front,rear;

    Queue(int size){
        this->size = size;
        arr =  new int[size];
        front = rear = 0;
    }
    void push(int element){
        if(rear == size){
            cout << "Queue is full " << endl;
        }
        else{

            arr[rear] = element;
            rear++;

        }
    }
    void pop(){
        if(rear > 0){
            arr[front] = 0;
            front ++;

        }
        else{
            cout << "Queue is empty " << endl;
        }
    }

};
    void front2(Queue& q){
        if (q.rear > 0)
        {
            cout << q.arr[q.front];
                
        }
        else{
            cout << "queue is empty " << endl;

        }
        
    }

class stack
{
public:
    int *arr;
    int size;
    int top;

    stack(int size)
    {

        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {

            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow " << endl;
        }
    }
    void pop()
    {
        if (top != -1)
        {
            top--;
        }
        else
        {
            cout << "stack is empty" << endl;
        }
    }
    void peek()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << arr[top] << endl;
        }
    }
    void empty()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << "Stack is not empty" << endl;
        }
    }
};




class tree
{
public:
    int data;
    tree *left, *right;

    tree(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

// two methods
// iterative way we will be using queue data structure
tree *iterative()
{
    queue<tree *> q;
    int rootValue, leftChild, rightChild;
    cin >> rootValue;
    if (rootValue == -1)
    {
        return nullptr;
    }
    tree *root = new tree(rootValue);
    q.push(root);
    while (!q.empty())
    {
        tree *temp = q.front();
        q.pop();
        cout << "Enter value for left child of " << temp->data << ": ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            temp->left = new tree(leftChild);
            q.push(temp->left);
        }
        cout << "Enter value for right child of " << temp->data << ": ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            temp->right = new tree(rightChild);
            q.push(temp->right);
        }
    }
    return root;
}
void inOrder(tree *root)
{

    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// recursion
tree *recursive()
{
    int x;
    cin >> x;
    if (x == -1)
    {

        return nullptr;
    }
    tree *newNode = new tree(x);
    cout << "Enter left child of " << newNode->data << ": ";
    newNode->left = recursive();
    cout << "Enter right child of  " << newNode->data << ":  ";
    newNode->right = recursive();

    return newNode;
}

// singly linked list
class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = nullptr;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete this->next;
            this->next = nullptr;
        }
        cout << "Memory free of " << value << endl;
    }
};
void insertAtHead(node *&head, node *&tail, int d)
{
    if (head == nullptr)
    {
        node *newNode = new node(d);
        head = newNode;
        tail = newNode;
    }
    else
    {
        node *newNode = new node(d);
        newNode->next = head;
        head = newNode;
    }
}
void insertAtTail(node *&head, node *&tail, int d)
{
    if (tail == nullptr)
    {
        node *newNode = new node(d);
        tail = newNode;
        head = newNode;
    }
    else
    {
        node *newNode = new node(d);
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAtAnyPosition(node *&head, node *&tail, int position, int value)
{
    // if we want to insert at head
    if (position == 1)
    {
        insertAtHead(head, tail, value);
        return;
    }
    else
    {
        int count = 1;
        node *temp = head;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }
        node *newNode = new node(value);
        if (temp->next == nullptr)
        {
            tail = newNode;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void deleteNode(node *&head, node *&tail, int position)
{

    if (head == nullptr)
    {
        cout << "list is empty " << endl;
    }
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    int count = 0;
    node *prev = nullptr;
    node *curr = head;
    while (count < position - 1)
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
void traverse(node *&head, node *&tail)
{

    if (head == nullptr)
    {
        cout << "List is empty " << endl;
    }
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

int main()
{

    node *head = nullptr;
    node *tail = nullptr;

    //     insertAtHead(head, tail, 5);
    //     insertAtHead(head, tail, 10);
    //     insertAtTail(head, tail, 9);
    //    //traverse(head, tail);
    //     insertAtAnyPosition(head,tail,1,1);
    //     traverse(head,tail);
    // cout << "Enter the root node: ";
    // tree *root;
    // root = recursive();
    // inOrder(root);
    // return 0;
    Queue q1(5);
    q1.push(9);
    front2(q1);
    print(1);
}
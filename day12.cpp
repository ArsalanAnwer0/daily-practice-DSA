#include <iostream>

using namespace std;

class queue
{

public:
    int size, front, rear, *arr;

    queue(int size) : size(size), front(0), rear(0)
    {
        arr = new int[size];
    }
    void push(int element)
    {

        if (rear < size)
        {
            arr[rear] = element;
            rear++;
        }
        else if (rear == size)
        {
            cout << "Queue is full " << endl;
        }
    }
    void pop()
    {
        if (front < rear)
        {
            front++;
        }
        else
        {
            cout << "queue is empty  " << endl;
        }
    }
    void isEmpty()
    {
        if(rear == 0){
            cout << "Queue is empty " << endl;
        }
        else{
            cout << "Queue is not empty " << endl;
        }
    }
    void peek()
    {
        if(rear>0){
            cout << arr[front] << endl;
        }
        else{
            cout << "Queue is empty " << endl;
        }
    }
};

int main()
{
    queue line(10);
    line.push(5);
    line.peek();
    line.isEmpty();


    return 0;
}
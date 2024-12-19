#include <iostream>
using namespace std;

class queue
{
public:
    int data, first, rear;
    int *arr;
    int size;
    queue(int size1) : size(size1), first(0), rear(0) {
        arr = new int[100];
    }

    void push(int element)
    {
        if (rear == size)
        {

            cout << "Queue is full";
        }
        else
        {
            arr[rear] = element;
            rear++;
        }
    }
    void pop()
    {
        if (rear > 0)
        {

            arr[first] = -1;
            first++;
        }
        else
        {
            cout << "Queue is empty " << endl;
        }
    }
    bool isEmpty()
    {

        if (rear == 0)
        {
            cout << "Queue is empty" << endl;
            return true;
        }
        else
        {
            cout << "Queue is not empty " << endl;
            return false;
        }
    }
    void front()
    {

        if (rear > 0)
        {

            cout << "Front: " << arr[first] << endl;
        }
        else
        {

            cout << "Queue is empty" << endl;
        }
    }
    void last()
    {
        if (rear!=size)
        {

            cout << "Last: " << arr[rear - 1] << endl;
        }
        else
        {
            cout << "Queue is empty " << endl;
        }
    }
};

int main()
{
    queue q(5);
    q.push(5);
    q.push(10);
    q.front();
    q.last();
    q.isEmpty();

    return 0;
}
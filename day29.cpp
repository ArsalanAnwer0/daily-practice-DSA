// learning stack and queue
#include <iostream>

using namespace std;

class stack
{

public:
    int *arr;
    int top;
    int size;

    stack(int size1) : size(size1), top(-1)
    {
        arr = new int[100];
    }

    void push(int element)
    {

        if (top < size - 1)
        {

            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack overflow" << endl;
        }
    }
    void pop()
    {
        if(top > -1){

            top--;
        }
        else{

            cout << "Stack is empty " << endl;
        }
    }
    bool isEmpty()
    {
        if(top == -1){

            return true;

        }
        else{
            return false;
        }
    }
    void peek()
    {
        if(!isEmpty()){

            cout << "Top element: "  << arr[top] << endl;

        }
        else{
            cout << "Stack is empty " << endl;
        }
    }
};

int main()
{
    stack s(5);
    s.pop();
    s.peek();
    cout << s.isEmpty();

    return 0;
}
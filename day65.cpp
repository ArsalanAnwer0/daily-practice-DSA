// Learning stacks and queues
// stack
#include<iostream>
#include<stack>

using namespace std;

class TwoStack{
    public:
    
    int* arr;
    int top1,top2;
    int size;

    TwoStack(int size){
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int element){
        // atleast one empty space
        if((top2 - top1) > 1){
            top1++;
            arr[top1] =  element;
        }
        else{
            cout << "Stack One overflow" << endl;
        }
    }
    void push2(int element){
        if(top2 - top1 > 1){
            top2--;
            arr[top2];
        }
        else{
            cout << "Stack Two overflow";
        }
    }
    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            cout << "Stack one is empty!" << endl;
        }
        return -1;
    }
    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            cout << "Stack two is empty!" << endl;
        }
        return -1;
    }
};

class Stack{

    public:

    // properties
    int* arr;
    int top;
    int size;


    // behavior
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack overflow" << endl;
        }
    }
    void pop(){

        if(top >= 0){
            top--;
        }
        else{
            cout << "Stack is empty!" << endl;
        }

    }
    int peek(){
        if(top >= 0 && top < size){
            return arr[top];
        }
        else{
            cout << "Stack is empty!" << endl;
        }
        return -1;
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

};



int main(){ 

    Stack st(5);
    st.push(22);
    st.push(24);
    st.push(26);

    cout << st.peek();
    st.pop();
    cout << endl << st.peek();
        st.pop();
    cout << endl << st.peek();
          st.pop();
    if(st.isEmpty()){
        cout << "Stack is empty!" << endl;
    }
    else{
        cout << "Stack is empty!" << endl;
    }
    // stack<int> s;
    // s.push(2);
    // s.push(3);
    // s.pop();

    // cout << s.top();

    // if(s.empty()){
    //     cout << "Stack is empty " << endl;
    // }
    // else{
    //     cout << "Stack is not empty " << endl;
    // }
    // cout << "Size of stack is " << s.size();
    


    return 0;
}
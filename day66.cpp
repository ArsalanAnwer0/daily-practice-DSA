// Stack questions

#include<iostream>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

// Question#1 Reverse a string using stack


// int main(){

//     string str = "nalasra";
//     stack<char> st;
//     for(int i=0;i<str.length();i++){
//         char ch =  str[i];
//         st.push(ch);
//     }

//     string ans =  "";

//     while(!st.empty()){
//         char ch = st.top();
//         ans.push_back(ch);
//         st.pop();
//     }

//     cout << "Hi, My name is " << ans << endl;



//     return 0;
// }





// Question#2 Delete middle element using stack

// void solve(stack<int>&inputStack,int count,int size){
//     // base case
//     if(count == size/2){
//         inputStack.pop();
//         return;
//     }
//     int num = inputStack.top();
//     inputStack.pop();
//     solve(inputStack,count++,size);
//     inputStack.push(num);
// }

// int main(){

//    int count = 0;
//    solve(inputStack,count,size);




//     return 0;
// }


// Question#3 Valid Parenthesis


// bool isValidParenthesis(string expression){

// stack<char> s;
//     for(int i=0;i<expression.lenth();i++){
//         char ch = expression[i];
        
//         // if opening bracket, stack push

//         if(ch == 'C' || ch == '{' || ch == '['){
//             s.push(ch);
//         }

//         // if close bracket, check stack top and pop
//         else{
//             if(!s.empty()){
//                 char top = s.top();
//                 if( (ch == ']' && top == '[' ) ||
//                     (ch == '}' && top == '{') ||
//                     (ch == ')' && top == '(')
//                 ){
//                     s.pop();
//                 }
//                 else{
//                     return false;
//                 }
//             }
//             else{
//                 return false;
//             }
//         }
//     }
//     if(s.empty()){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// Question#4 Insert at last position of stack

// void solve(stack<int>& myStack, int x){
//     // base case
//     if(myStack.empty()){
//         myStack.push(x);
//         return;
//     }
//     int num = myStack.top();
//     myStack.pop();

//     solve(myStack,x);
//     myStack.push(num);
// }

// stack<int> pushAtBottom(stack<int>& myStack, int x){
//     solve(myStack,x);
//     return myStack;
// }

// Question#5 Reverse stack using recursion

// void insertAtBottom(stack<int> &stack, int element){
//     // base case
//     if(stack.empty()){
//         stack.push(element);
//         return;
//     }

//     int num = stack.top();
//     insertAtBottom(stack,element);
//     stack.push(num);

// }

// void reverseStack(stack<int>&stack){

//     // base case
//     if(stack.empty()){
//         return;
//     }
//     int num = stack.top();
//     stack.pop();

//     reverseStack(stack);
//     insertAtBottom(stack,num);

// }

// Question Sort a Stack

// void sortedInsert(stack<int>&stack,int num){
//     // base case
//     if((stack.empty()) || (!stack.empty() && stack.top() < num) ){
//         stack.push(num);
//         return;
//     }
//     int n = stack.top();
//     stack.pop();

//     sortedInsert(stack,num);

//     stack.push(n);
// }


// void sortStack(stack<int> &stack){
//     // base case
//     if(stack.empty()){
//         return;
//     }
//     int num =  stack.top();
//     stack.pop();

//     sortStack(stack);

//     sortedInsert(stack,num);
// }


// Learning Queues


// implementing queue

// class Queue{
//     public:
//     int* arr;
//     int size,front,rear;

//     Queue(int size){
//         this->size = size;
//         front = 0;
//         rear = 0;
//         arr = new int[size];
//     }

//     void push(int element){
//         if(rear == size){
//             cout << "Queue is full! " << endl;
//         }
//         else{
//             arr[rear] = element;
//             rear++;
//         }
//     }
//     int pop(){
//         if(front == rear){
//             cout << "Queue is empty!" << endl;
//             return -1;
//         }
//         else{
//             int ans = arr[front];
//             arr[front] = -1;
//             front++;

//             if(front == rear){
//                 front = 0;
//                 rear = 0;
//             }   
            
//         }
//         return ans;
//     }
//     void frontValue(){
//         if(front == rear){
//             cout << "Queue is empty! " << endl;
//         }
//         else{
//             cout << arr[front];
//         }
//     }
//     bool isEmpty(){
//         if(front == rear){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };

// class CircularQueue{
//     public:
//     int size,front,rear;
//     int* arr;

//     CircularQueue(int size){
//         this->size = size;
//         arr = new int[size];
//         front = rear = -1
//     }
//     bool push(int element){
//         if( front == 0 && rear == size - 1 || rear = (front-1)%(size-1)){
//             cout << "Queue is full";
//             return false;
//         }
//         else if(front == -1){
//             front = rear = 0;
           
//         }
//         else if(rear == size - 1 && front!=0){
//             rear = 0;
//         }
//         else{
//             rear++;
//         }
//          arr[rear] = element;
//          return true;
//     }
//     int pop(){
//         if(front == -1){
//             cout << "Queuen is empty" << endl;
//             return -1;
//         }
//         // single element
//         if(front == rear){
//             front = rear = -1;
//         }
//         else if(front = size - 1){
//             front = 0; // to maintain cyclic nature
//         }
//         else{
//             front ++;
//         }  
//     }   
// };

class Deque{
    public:
    int* arr;
    int front,rear,size;

    Deque(int size){
        this->size = size;
        front = -1;
        rear = -1;
    }
    bool pushFront(int x){
        // check full or not
        if(front == 0 && rear == size - 1 || rear = (front-1)%(size-1)){
            return false;
        }
        else if(front == -1)
    {
        front = rear = 0;

    }
    else if(front == 0){
        front = size - 1;
    }
    else{
        front --;
    }
    arr[front] = x;
    return true;
    }
    bool pushRear(int x){
        // same as before
    }
    int popFront(){
        // same as before
    }
    int popRear(){
        
    }






};




int main(){

    deque<int> d;

    d.push_front(3);
    d.push_back(23);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();

    cout << d.front() << endl;
    cout << d.back() << endl << endl;


    if(d.empty()){
        cout << "Is empty!" << endl;
        }

    









    

    


}


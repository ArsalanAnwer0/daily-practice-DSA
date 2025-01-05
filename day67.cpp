// Solving Queue questions

#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>

using namespace std;

// Queue Reversal

queue<int> rev(queue<int>& q){

    stack<int> s;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}


// Find negative integer in window size

vector<long long> printFirstNegativeInteger
(long long int A[],long long int N, long long int k)
{
    deque<long long int> dq;
    vector<long long> ans;
    // process first window of k size
    for(int i=0;i<K;i++){
        if(A[i] < 0){
            dq.push_back(i);
        }
    } 
    // store ans of first k size window
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    // process for remaining windows
    for(int i = K; i<N;i++){
        // removal
        if(!dq.empty() && i - dq.front() >= K){
            dq.pop_front();
        }
        // addition
        if(A[i] < 0){
            dq.push_back(i);
        }
         if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
         }
        else{
        ans.push_back(0);
        }
    }
    return ans;
}

// Reverse first k element of queue


queue<int> modifyQueue(queue<int> q, int k){
    // algo
    // step 1: pop first k from queue and push into stack
    stack<int> s;
    for(int i=0;i<k;i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    // fetch from stack and push into queue
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    // step 3: fetch first n - k element and put them at last
    int t = q.size() - k;
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q; 
}

// first non repeating character in a string

string FirstNonRepeating(string A){
    unordered_map<char,int> count;
    queue<int> q;

    string ans = "";

    for(int i=0;A.lenth();i++){
        char ch = A[i];

        // increase count
        count[ch] ++;

        q.push(ch);

        while(!q.empty()){

            // check we repeating
            if(count[q.front()] > 1){
                q.pop();
            }
            // if not repeating
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#';)
        }
    }
    return ans;
}   


// Circular tour

class petrolPump{

    public:
    int petrol;
    int distance;

    int tour(petrolPump p[], int n){

    int deficit = 0;
    int balance = 0;
    int start = 0;

    for(int i = 0;i<n,i++){
        balance += p[i].petrol - p[i].distance;
        if(balance < 0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }
    if(deficit + balance >= 0){
        return start;
    }
    else{
        return -1;
    }
}
};


int main(){




    return 0;
}
// Print all elements in queue

void printQueue(){
    queue<int> q;
    int n = q.size();
    while(n--){
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
}

// Queue reversal

class solution{
    public:
    queue<int> rev(queue<int> q){
        stack<int> st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        return q;
    }
}

// Reverse First K element of queue

queue<int> modifyQueue(queue<int> q,int k){
    stack<int>  st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    int n = q.size();
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(n--){
        q.push(q.front());
        q.pop();
    }
    return q;
}

// Time needed to buy tickets

int ticket(int arr[], int size, int k){
    queue<int> q;
    for(int i=0;i<size;i++){
        q.push(i);        
    }
    int time = 0;
    while(arr[k]!=0){
        arr[q.front()]--;   
        time++;
        if(arr[q.front()] != 0){
            q.push(q.front());
        }
        q.pop();
    }
    return time;
}

// Implement Queue using Stack
// Implement Stack using Queue


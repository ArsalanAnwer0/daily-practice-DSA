// solving stack questions

    
class solution{
    public:
    // reverse a string
    void reverseString(vector<char>& s){
        stack<char>st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }
        int i=0;
        while(!s.empty()){
            s[i] = st.top();
            st.pop();
            i++;
        }
    }
    // insert at bottom
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> temp;
        
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return st;
    }
    // make the array beautiful
    vector<int> makeBeautiful(vector<int> arr){
        stack<int> s;
        for(int i=0;i<arr.size();i++){
            // stack can be empty
            if(s.empty()){
                s.push(arr[i]);
            }
            // None negative number
            else if(arr[i] >= 0){
                // None negative in stack
                if(s.top >= 0){
                    s.push(arr[i]);
                }
                else{
                    s.pop();
                }
            }
            // Negative number
            else{
                // Negative in stack
                if(s.top <= 0){
                    s.push(arr[i]);
                }
                else{
                    s.pop();
                }
            }
        }
        // putting elements from stack into vector
        vector<int> ans(s.size());
        int i = s.size() - 1;
        while(!s.empty){
            ans[i] = s.top();
            i--;
            s.pop();
        }
        return ans;
    }

    // string manipulation
    int removeConsecutiveSame(vector <string> v){
        stack<string> s;
        for(int i=0;i<v.size();i++){
            if(s.empty()){
                s.push(v[i]);
            }
            else if(s.top == v[i]){
                s.pop();
            }
            else{
                s.push(v[i]);
            }
        }
        return s.size();
    }

    // parenthesis is valid or not
    bool check(string str){
        stack<char> s;
        for(int =0;i<str.size();i++){
            if(str[i] == '('){
                s.push(str[i]);
            }
            else{
                if(s.empty()){
                    return true;
                }
                else{
                    s.pop();
                }
            }
        }
        return s.empty();
    }
    // Minimum add to make parenthesis valid
    int minAddToMakeValid(string s){
        stack<char> st;
        int count = 0;
        for(int i=0;i<s.size();i++){
            // opening 
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    count++;
                }
                else{
                    st.pop();
                }
            }
        }
        return count+st.size();
    }
    // Valid parenthesis
    bool isValid(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            // we got opening bracket
            if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
                st.push(s[i]);
            }
            // we got closing bracket
            else{
                if(st.empty()){
                    return 0;
                }
                else if(s[i] == ']'){
                    if(st.top()!='['){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
                else if(s[i] == '}'){
                     if(t.top()!='}'){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
                else if(s[i] == ')'){
                     if(t.top()!=')'){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
            }
        }
    }

    // background string compare
    // # backspace

    // Point Bracket Number
    vector<int> bracketNumbers(string s){
        stack<int> st;
        int count = 0;
        for(int i=0;i<s.size();i++){
            // opening bracket
            if(s[i] == '('){
                count++;
                st.push(count);
                ans.push_back(count);
            }
            // closing bracket
            else if(s[i] == ')'){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
    // get minimum at pop

    stack<int> _push(int arr[], int n){
        stack<int> st;
        for(int i=0;i<n;i++){
            if(i==0){
                s.push(arr[i];)
            }
            else{
                st.push(min(arr[i]),st.top());
            }
        }
        return st;
    }
    void _getMinAtPop(stack <int>s){

        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }

    }







};

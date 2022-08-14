class MyQueue {
    stack<int> s;
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);    
    }
    
    int pop() {
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        int x=st.top();
        st.pop();
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        return x;
    }
    
    int peek() {
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        int x=st.top();
        
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        return x;
    }
    
    bool empty() {
        return s.empty()?true:false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MinStack {
public:
    stack<int>st;
    vector<int>arr;
    int topptr;
    int n;
    MinStack() {
        this->topptr = -1;
        this->n = 30000;
        this->arr.resize(n, -1);
    }
    
    void push(int val) {
        if(st.empty() || st.top() >= val)  st.push(val);
        
        arr[++topptr] = val;
    }
    
    void pop() {
        if( !st.empty() && st.top() == arr[topptr] )
            st.pop();
        topptr--;

    }
    
    int top() {
       if(topptr == -1 || topptr == n)
        return 0; 
        return arr[topptr];
    }
    
    int getMin() {
        if(st.empty())  return 0;
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
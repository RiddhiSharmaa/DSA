class MinStack {
public:
    stack<int>mini, st;
    MinStack() {
        
    }
    
    void push(int value) {
        if (!mini.empty() && value <= mini.top()) mini.push(value);
        if (mini.empty()) mini.push(value);
        st.push(value);
    }
    
    void pop() {
        if (st.top() == mini.top()) mini.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
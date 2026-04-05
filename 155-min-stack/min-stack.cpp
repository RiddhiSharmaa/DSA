class MinStack {
public:
    vector<pair<int, int>>st;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        mini = min(mini, val);
        st.push_back({val, mini});
    }
    
    void pop() {
        st.pop_back();
        int n = st.size();
        if (n > 0) mini = st[n-1].second;
        if (n == 0) mini = INT_MAX;
    }
    
    int top() {
        int n = st.size();
        if (n == 0) return -1;
        return st[n-1].first;
    }
    
    int getMin() {
        int n = st.size();
        if (n <= 0) return -1;
        return st[n-1].second;
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
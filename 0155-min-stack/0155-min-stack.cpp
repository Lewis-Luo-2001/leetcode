class MinStack {
private:
    stack<int> st, minSt;
    int curMin;

public:    
    MinStack() {
        curMin = INT_MAX;
        st = stack<int>();
        minSt = stack<int>();
    }
    
    void push(int val) {
        curMin = min(curMin, val);
        st.push(val);
        minSt.push(curMin);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
        curMin = (minSt.empty()) ? INT_MAX : minSt.top();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
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
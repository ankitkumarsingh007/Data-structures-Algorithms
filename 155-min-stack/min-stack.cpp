class MinStack {
public:
    long minValue;
    stack<long> st;
    MinStack() { minValue = 0; }

    void push(long value) {
        if (st.empty()) {
            st.push(value);
            minValue = value;
        } else if (minValue <= value) {
            st.push(value);
        } else {
            long pushValue = 2 * value - minValue;
            minValue = value;
            st.push(pushValue);
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        } else if (st.top() >= minValue) {
            st.pop();
        } else {
            minValue = 2 * minValue - st.top();
            st.pop();
        }
    }

    int top() {
        if (st.top() >= minValue) {
            return st.top();
        } else {
            return minValue;
        }
    }

    int getMin() { return minValue; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
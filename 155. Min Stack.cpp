class MinStack {
public:
//S.C -> O(N)
stack<long long >st;
long long mini;
    MinStack() {
        while(!st.empty()) st.pop();
        mini = INT_MAX;
    }
    //Modified value < minimum value 
    void push(int value) {
         long long val = value ;
            if (st.empty()) {
                    mini = val;
                    st.push(val);
            } 
            else {
                    if (val < mini) {
                        st.push(2 *val*1LL - mini);
                        mini = val;
                    }
                    else {
                        st.push(val);
                    }
            }
    }
    
    void pop() {
        if (st.empty()) return;
        long long el = st.top();
        st.pop();
        //Modified value being popped down -> see for previous minimum
        if (el < mini) {
        mini = 2 * mini - el;
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        long long el = st.top();
        if (el < mini) return mini; //Modified value greater than minimal therefore return minimum value
        return el;
    }
    
    int getMin() {
        return mini ;
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

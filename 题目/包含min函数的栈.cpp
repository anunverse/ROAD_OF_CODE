class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> a;
    vector<int> b;
    MinStack() {
        
    }
    
    void push(int x) {
        a.push_back(x);
        if (b.empty() || b.back() >= x) b.push_back(x);
        else b.push_back(b.back());
    }
    
    void pop() {
        b.pop_back();
        a.pop_back();
    }
    
    int top() {
        return a.back();
    }
    
    int getMin() {
        return b.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

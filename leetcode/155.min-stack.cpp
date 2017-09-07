/**
 * https://leetcode.com/problems/min-stack/
 * By Nroskill
 * runtime 29 ms
 * language cpp
 */

class MinStack {
private:
    stack<int> data;
    stack<int> helper;
    
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data.push(x);
        if(helper.empty() || getMin() >= x)
            helper.push(x);
    }
    
    void pop() {
        if(top() == getMin())
            helper.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return helper.top();
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
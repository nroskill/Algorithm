/**
 * https://leetcode.com/problems/implement-queue-using-stacks/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

class MyQueue {
private:
    stack<int> db;
    stack<int> helper;

public:
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!db.empty()) {
            helper.push(db.top());
            db.pop();
        }
        db.push(x);
        while(!helper.empty()) {
            db.push(helper.top());
            helper.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto t = db.top();
        db.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        return db.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return db.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
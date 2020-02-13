class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack1.push(x);
        if (stack2.empty() || x < stack2.top())
        {
            stack2.push(x);
        }
        else
        {
            int y = stack2.top();
            stack2.push(y);
        }
    }
    
    void pop() {
        if (stack1.size()>0 && stack2.size()>0)
        {
            stack1.pop();
            stack2.pop();
        }
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

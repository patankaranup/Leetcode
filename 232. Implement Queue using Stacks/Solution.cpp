class MyQueue {
public:
    stack<int> inp;
    stack<int> op;
    int peekElement;
    MyQueue() {
        peekElement = -1;
    }
    
    void push(int x) {  
        if(inp.empty()){
            peekElement = x;
        }
        inp.push(x);
    }
    
    int pop() {
        if(op.empty()){
            while(!inp.empty()){
                int val = inp.top();
                inp.pop();
                op.push(val);
            }
        }
        int ans = op.top();
        op.pop();
        return ans;
    }
    
    int peek() {
        if(op.empty()){
            return peekElement;
        }
        return op.top();
    }
    
    bool empty() {
        return inp.empty() && op.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
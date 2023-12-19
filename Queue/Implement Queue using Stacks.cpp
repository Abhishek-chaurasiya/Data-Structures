class MyQueue {
public:
    stack<int> enq, deq;
    MyQueue() {
        
    }
    
    void push(int x) {
        enq.push(x);
    }
    
    int pop() {
        int res = -1;
        if(deq.empty()){
            while(!enq.empty()){
                deq.push(enq.top());
                enq.pop();
            }
        }
        if(deq.empty())return res;
        res = deq.top(); 
        deq.pop();
        
        return res;
    }
    
    int peek() {
        int res = -1;
        if(deq.empty()){
            while(!enq.empty()){
                deq.push(enq.top());
                enq.pop();
            }
        }
        if(deq.empty())return res;
        res = deq.top(); 
        return res;
    }
    
    bool empty() {
        return (enq.empty() && deq.empty());
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

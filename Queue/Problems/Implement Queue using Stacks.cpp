class MyQueue {
    stack<int>st1, st2;

    void shift(){
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        shift();
        int ans = st2.top();
        st2.pop();
        return ans;
    }
    
    int peek() {
        shift();
        return st2.top();
    }
    
    bool empty() {
        return (((int)st1.size() + (int)st2.size()) == 0);
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
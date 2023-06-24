class MyStack {
    queue<int>q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = (int)q.size();
        int ans = q.back();
        for(int i = 0; i < size - 1;i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        return ans;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
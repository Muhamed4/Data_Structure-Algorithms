class MinStack {
    vector<int>MStack, _data;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(MStack.empty())MStack.push_back(val);
        else MStack.push_back(min(MStack.back(), val));
        _data.push_back(val);
    }
    
    void pop() {
        MStack.pop_back();
        _data.pop_back();
    }
    
    int top() {
        return _data.back();
    }
    
    int getMin() {
        return MStack.back();
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
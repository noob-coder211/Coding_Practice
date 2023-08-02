class MyStack {
public:

    queue<int> q1;
    queue<int> q2;

    MyStack() {
        queue<int> empty;
        q1 = empty;
        q2 = empty;
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1)
        {
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }
        int ans = q1.front();
        //q2.push(ans);
        q1.pop();

        q1 = q2;
        queue<int> empty;
        q2 = empty;
        return ans;
        
    }
    
    int top() {
          while(q1.size() > 1)
        {
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }
        int ans = q1.front();
        q2.push(ans);
        q1.pop();

        q1 = q2;
        queue<int> empty;
        q2 = empty;
        return ans;
        
    }
    
    bool empty() {
        if(q1.size() == 0)
            return true;
        return false;
        
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
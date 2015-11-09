class Stack {
public:
    queue<int> q;
    int stack_top;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        stack_top = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        int q_size = q.size();
        if(q_size==0) return;
        for(int i=0; i<q_size-1; i++){
            int num = q.front();
            q.pop();
            q.push(num);
            if(i==q_size-2) stack_top = num;
        }
        q.pop();
    }

    // Get the top element.
    int top() {
        if(q.empty()) return -1;
        return stack_top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

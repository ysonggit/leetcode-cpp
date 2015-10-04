class MinStack {
public:
    stack<int> all_vals, min_vals;
    void push(int x) {
        all_vals.push(x);
        if(min_vals.empty()) min_vals.push(x);
        else{
            if(x <= min_vals.top()) min_vals.push(x);
        }
    }

    void pop() {
        if(all_vals.empty()) return;
        if(all_vals.top()==min_vals.top()){
            min_vals.pop();
        }
        all_vals.pop();
    }

    int top() {
        return all_vals.top();
    }

    int getMin() {
        return min_vals.top();
    }
};

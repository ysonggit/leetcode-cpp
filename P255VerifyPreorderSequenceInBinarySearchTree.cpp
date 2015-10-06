class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return true;
        stack<int> pred;
        int nearest_root = INT_MIN;
        for(int cur : preorder){
            if(cur<nearest_root) return false;
            while(!pred.empty() && cur > pred.top()){
                nearest_root = pred.top();
                pred.pop();
            }
            pred.push(cur);
        }
        return true;
    }
};

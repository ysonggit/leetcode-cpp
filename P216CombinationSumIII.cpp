class Solution {
public:
    void dfs(vector<vector<int>> & res, vector<int> sol, int k, int n, 
            int cur, int cur_sum){
        if(sol.size() > k || cur_sum > n) return;
        if(sol.size()==k && cur_sum ==n){
            res.push_back(sol);
            return;
        }
        for(int i=cur; i<=9; i++){
            sol.push_back(i);
            dfs(res, sol, k, n, i+1, cur_sum+i);
            sol.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(n==0) return res;
        vector<int> sol;
        dfs(res, sol, k, n, 1, 0);
        return res;
    }
};

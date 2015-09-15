class Solution {
public:
    void dfs(vector<vector<int> > & res, vector<int>& candidates, vector<int> sol, int target, int cur_idx){
        if(target<0 || cur_idx >= candidates.size()) return;
        if(target == 0){
            res.push_back(sol);
            return;
        }
        for(int i= cur_idx; i<candidates.size(); i++){
            int cur = candidates[i];
            sol.push_back(cur);
            dfs(res, candidates, sol, target-cur, i);
            sol.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res; 
        if(candidates.size()==0) return res;
        vector<int> sol;
        sort(candidates.begin(), candidates.end());
        dfs(res, candidates, sol, target, 0);
        return res;
    }
};

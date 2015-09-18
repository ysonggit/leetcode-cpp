class Solution {
public:
    void dfs(vector<vector<int> >& res, vector<int>& candidates, vector<int> sol, int target, int cur_idx){
        if(target==0){
            res.push_back(sol);
            return;
        }
        if(target < 0) return;
        for(int i=cur_idx; i<candidates.size(); i++){
            if(i> cur_idx && candidates[i]==candidates[i-1]) continue; // mistake : candidates[i]==candidates[cur_idx]
            int cur = candidates[i];
            sol.push_back(cur);
            dfs(res, candidates, sol, target-cur, i+1);
            sol.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> sol;
        sort(candidates.begin(), candidates.end());
        dfs(res, candidates, sol, target, 0);
        return res;
    }
};

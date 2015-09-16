class Solution {
public:
    void dfs(vector<vector<int>> & res, vector<int> & nums, 
            vector<int> sol, int cur_idx)
    {
        if(cur_idx==nums.size()){
            res.push_back(sol);
            return;
        }                
        // ignore this one
        dfs(res, nums, sol, cur_idx+1);
        int cur = nums[cur_idx];
        // put this one into subset
        sol.push_back(cur);
        dfs(res, nums, sol, cur_idx+1);
        sol.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        vector<int> sol;
        sort(nums.begin(), nums.end());
        dfs(res, nums, sol, 0);
        return res;
    }
};

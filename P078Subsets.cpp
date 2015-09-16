class Solution {
public:
    void dfs(vector<vector<int>> & res, vector<int> & nums, 
            vector<int> sol, int cur_idx)
    {
        for(int i=cur_idx; i<nums.size(); i++){
            int cur = nums[i];
            sol.push_back(cur);
            res.push_back(sol);
            dfs(res, nums, sol, i+1);
            sol.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        vector<int> sol;
        sort(nums.begin(), nums.end());
        res.push_back(sol);
        dfs(res, nums, sol, 0);
        return res;
    }
};

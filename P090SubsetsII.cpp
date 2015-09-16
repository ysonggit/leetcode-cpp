Enter file contents hereclass Solution {
public:
    void dfs(vector<vector<int>> & res, vector<int>& nums,
            vector<int> sol, int cur_idx)
    {
        for(int i=cur_idx; i<nums.size(); i++){
            if(i>cur_idx && nums[i]==nums[i-1]){
               continue; // remove duplicates
            }
            int cur = nums[i];
            sol.push_back(cur);
            res.push_back(sol);
            dfs(res, nums, sol, i+1);
            sol.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n==0) return res;
        sort(nums.begin(), nums.end());
        vector<int> sol;
        // empty set
        res.push_back(sol);
        dfs(res, nums, sol, 0);
        return res;
    }
};

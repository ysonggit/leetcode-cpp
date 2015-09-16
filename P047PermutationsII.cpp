class Solution {
public:
    void dfs(vector<vector<int> >& res, vector<int>& nums,
            vector<int> sol, vector<int> visited)
    {
        if(sol.size()==nums.size()){
            res.push_back(sol);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1] && visited[i-1]) continue;
            if(visited[i]==0){
                visited[i]=1;
                sol.push_back(nums[i]);
                dfs(res, nums, sol, visited);
                sol.pop_back();
                visited[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        int n = nums.size();
        if(n==0) return res;
        sort(nums.begin(), nums.end());
        vector<int> sol;
        vector<int> visited(n, 0);
        dfs(res, nums, sol, visited);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> cache;
    int maxSum(vector<int>&nums, int low, int high){
        if(low>high) return 0;
        if(cache[low+1][high]>=0) return cache[low+1][high];
        int global = 0;
        for(int k=low+1; k<high; k++){
            int left = (low==-1) ? 1 : nums[low];
            int right = (high==nums.size()) ? 1 : nums[high];
            int local = maxSum(nums, low, k) + maxSum(nums, k, high) + left*nums[k]*right;
            global = max(global, local);
        }
        cache[low+1][high] = global;
        return global;
    }
    int maxCoins(vector<int>& nums) {
       int n = nums.size();
       if(n==0) return 0;
       cache = vector<vector<int>>(n+1, vector<int>(n+1, -1));
       return maxSum(nums, -1, n);
    }
};

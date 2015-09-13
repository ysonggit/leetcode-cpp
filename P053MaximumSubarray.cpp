class Solution {
public:
    // local max and global max
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int global_max = nums[0], local_max = nums[0];
        for(int i=1; i<n; i++){
            int cur = nums[i];
            local_max = max(local_max + cur, cur);
            global_max = max(global_max, local_max);
        }
        return global_max;
    }
};

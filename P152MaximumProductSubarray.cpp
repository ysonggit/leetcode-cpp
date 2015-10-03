class Solution {
public:
    //    [-1,-2,-9,-6]
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        long long global_max = nums[0], local_max= nums[0], local_min=nums[0];
        for(int i=1; i<n; i++){
            long long cur = (long long) nums[i];
            long long pre_local_max = local_max; // important!
            local_max = max({cur, cur * pre_local_max, cur * local_min});
            local_min = min({cur, cur * pre_local_max, cur * local_min});
            global_max = max(global_max, local_max);
        }
        return (int)global_max;
    }
};

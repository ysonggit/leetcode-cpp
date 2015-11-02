class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int min_len = n+1;
        int sum = 0, start = 0, end = 0;
        while(end<n){
            if(nums[end]>=s) return 1;
            sum += nums[end];
            while(sum>=s && start < end) {
                min_len = min(min_len, end-start+1);
                sum -= nums[start++];
            }
            end++;
        }
        return min_len > n ? 0 : min_len;
    }
};

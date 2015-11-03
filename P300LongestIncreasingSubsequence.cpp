class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> D(n, 0);
        int max_len = 0;
        for(int i=0; i<n; i++){
            D[i] = 1;
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]) D[i] = max(D[i], D[j]+1);
            }
            max_len = max(max_len, D[i]);
        }
        return max_len;
    }
};

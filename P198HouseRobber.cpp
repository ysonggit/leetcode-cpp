class Solution {
public:
    // assume no overflow
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> D(n+1, 0);
        D[1] = nums[0];
        for(int i=2; i<=n; i++){
            D[i] = max(D[i-2]+nums[i-1], D[i-1]);
        }
        return D[n];
    }
};

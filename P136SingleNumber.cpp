class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int x = nums[0];
        for(int i=1; i<n; i++){
            x ^= nums[i];
        }
        return x;
    }
};

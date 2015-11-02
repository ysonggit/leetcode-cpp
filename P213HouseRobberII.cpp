class Solution {
public:
    int robI(vector<int> & nums, int start, int end){
        int m = end - start +1;
        if(m<=0) return 0;
        vector<int> D(m+1, 0);
        D[1] = nums[start];
        for(int i=2; i<=m; i++){
            D[i] = max(D[i-1], D[i-2]+nums[i-1+start]); // mistake: don't forget +start as offset
        }
        return D[m];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        return max(robI(nums, 0, n-2), robI(nums, 1, n-1));
    }
};

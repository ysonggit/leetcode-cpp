class Solution {
public:
    // from sonkugo
    // 1,4,2,3  -> 1,4,3,2
    // pivot index = 3
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i]) pivot = i;
        }
        if(pivot>0){ // need swap
           int j = n-1;
           while(j>(pivot-1) && nums[pivot-1] >= nums[j]) j--;
           swap(nums[pivot-1], nums[j]);
        }
        sort(nums.begin()+pivot, nums.end());
    }
    
};

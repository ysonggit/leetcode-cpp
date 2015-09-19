class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int non_zero_idx = 0;
        for(int & i : nums){
            if(i!=0){
                nums[non_zero_idx++] = i;
            }
        }
        int m = non_zero_idx; // m is the size of non_zero sequence
        fill_n(nums.begin()+m, n-m, 0);
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return;
        bool less_than = true;
        for(int i=1; i<n; i++){
            int cur = nums[i], pre = nums[i-1];
            if(less_than){
                if(pre > cur) swap(nums[i], nums[i-1]);
            }else{
                if(pre < cur) swap(nums[i], nums[i-1]);
            }
            less_than = less_than ? false : true;
        }
    }
};

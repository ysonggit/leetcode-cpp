class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return n;
        int j=1, count=1;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]){
                nums[j++]=nums[i];
                count = 1;
            }else{
                count++;
                if(count<=2){
                    nums[j++] = nums[i];
                }
            }
        }
        return j;
    }
};

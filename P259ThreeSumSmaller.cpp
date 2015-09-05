class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0; i<n-2; i++){
            // no need to remove duplicates
            int j = i+1, k=n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum< target){
                    res+= k-j; // tricky step! (not res++)
                    j++;
                }else{
                    k--;
                }
            }
        }
        return res;
    }
};

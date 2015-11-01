class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if(n==0) return res;
        int start = 0, end = 0;
        while(end<n){
            while(end<n-1 && nums[end+1]-nums[end]==1){
                end++;
            }
            if(start==end) res.push_back(to_string(nums[start]));
            else res.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            end++;
            start= end;
        }
        return res;
    }
};

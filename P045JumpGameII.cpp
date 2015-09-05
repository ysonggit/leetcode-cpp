class Solution {
public:
// fucking corner cases [0] [1] []
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        int furthest_pos_by_preidx = nums[0];
        int furthest_pos_with_minstep = 0;
        int min_steps = 0;
        for(int i=1; i<n; i++){
            if(furthest_pos_by_preidx < i) return 0;
            if(furthest_pos_with_minstep < i) { 
                min_steps++;
                // mistake: ust check before update furthest_pos_by_preidx
                furthest_pos_with_minstep = furthest_pos_by_preidx;
            }
            int pos_from_cur = i+ nums[i];
            furthest_pos_by_preidx = max(furthest_pos_by_preidx, pos_from_cur); 
            if(furthest_pos_with_minstep >=n-1) return min_steps;
        }
        return min_steps;
    }
};

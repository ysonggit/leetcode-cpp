class Solution1 {
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

class Solution2 {
public:
    // test case [2    3    1 1 4]
    //      0|0   1|2  2|4  
    //           [2   0    1  0 1]
    //      0|0   1|2 3|3  4|3
    int jump(vector<int>& nums) {
        int n = nums.size();
        int lower = 0, upper = 0;
        int steps = 0;
        while(upper< n-1){
            int pre_lower = lower;
            int pre_upper = upper;
            for(int pos=pre_lower; pos<=pre_upper; pos++){
                // within current bounded range, find the next upperbound
                upper = max(nums[pos]+pos, upper);
            }
            // next lowerbound <==> move 1 step forward
            lower = pre_upper+1;
            if(lower > upper) return 0; // never reach last
            steps++;
        }
        return steps;
    }
};

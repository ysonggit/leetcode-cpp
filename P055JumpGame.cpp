class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=0) return true;
        int furthest_pos_sofar = 0;// mistake : donot initialize to nums[0], since given [0] should return true
        for(int i=0; i<n; i++){
            if(i>furthest_pos_sofar) return false;
            int furthest_pos_fromhere = i+nums[i];
            furthest_pos_sofar = max(furthest_pos_sofar, furthest_pos_fromhere);
            if(furthest_pos_sofar >=n-1){
                return true;
            }
        }
        return false;
    }
};

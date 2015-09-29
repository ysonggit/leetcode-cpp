class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int bits[32] ={0};
        for(int cur : nums){
            for(int j=0; j<32; j++){
                // get j-th bit of cur
                bits[31-j] += (cur>>j) & 1;
            }
        }
        int x = 0;
        for(int i=0; i<32; i++){
            x = x<<1;
            x += (bits[i] %3);
        }
        return x;
    }
};

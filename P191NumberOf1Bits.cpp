class Solution {
public:
    // navie solution while(n!=0) {n &= (n-1); count++;}
    int hammingWeight(uint32_t n) {
        if(n<2) return n;
        return n%2 + hammingWeight(n/2);
    }
};

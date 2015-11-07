class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n&(n-1))==0 ? true : false; // n&(n-1) => eliminate the rightmost '1'
        // mistake: (n&(n-1)==0) ? is wrong , == has higher pred than & 
    }
};

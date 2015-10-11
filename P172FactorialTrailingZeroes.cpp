class Solution {
public:
    // equal to count the number of 5's in n's factors
    int trailingZeroes(int n) {
        int count = 0;
        for(long long i=5; i<=n; i*=5){ //mistake: must use longlong for overflow 
            count+= n/i;
        }
        return count;
    }
};

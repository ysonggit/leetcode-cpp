class Solution {
public:
    /**
     * shift divisor to left by one-bit each time
     * use dividend to keep on substracting the shifted divisor
     * until dividend - shifted divisor < divisor
     * return the sum of total shifting values
     * 
     */ 
    int divide(int dividend, int divisor) {
        if(divisor==0) return INT_MAX;
        if(divisor==1) return dividend;
        if(divisor==-1){
            if(dividend== INT_MIN) return INT_MAX;
            return -dividend;
        }
        long long dividend_ll = abs((long long)dividend); // mistake: must convert dividend to long long then find abs
        long long divisor_ll = abs((long long) divisor);  // consider dividend = INT_MIN
        int res = 0;
        while(dividend_ll >= divisor_ll){
            long long shifted_divisor = divisor_ll;
            int shifted_val =1;
            while((shifted_divisor<<1) <= dividend_ll){
                shifted_divisor <<=1;
                shifted_val <<=1;
            }
            res += shifted_val;
            dividend_ll -= shifted_divisor;
        }
        int sign = ((divisor^dividend)>=0) ? 1 : -1;
        return sign * res;
    }
};

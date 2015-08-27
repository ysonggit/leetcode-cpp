class Solution {
public:
// 1001
    bool isPalindrome(int x) {
        if(x<0) return false;
        int d = 1;
        while(x/d >=10){// mistake >10
            d *=10;
        }   
        while(x>0){
            // get rightmost digit
            int right_digit = x%10;
            // get leftmost digit
            int left_digit = x/d;
            if(right_digit != left_digit) return false;
            x -= (left_digit * d + right_digit);
            x /= 10;
            d /= 100;
        }
        return true;
    }
};

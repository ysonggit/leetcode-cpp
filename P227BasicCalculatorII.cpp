class Solution {
public:
    // from StefanPochmann (https://leetcode.com/discuss/41641/17-lines-c-easy-20-ms)
    // key1: istringstream and head/tail safeguards: '+'
    // key2: track both mul and sum
    int calculate(string s) {
        int res = 0, num = 0, mul = 0, sign = 1;
        char op = '+';
        istringstream expr("+"+s+"+"); // trick to start loop if s is a number only
        while(expr>>op){
            if(op=='+'||op=='-'){
                // first update res with previous num
                res += num;
                expr >> num;  
                sign = (op=='+') ? 1 : -1;
                num *= sign;
            }else{
                expr >> mul;  // extract multiplier
                if(op == '*') num *= mul;
                else num /= mul;
            }
        }
        return res;
    }
};

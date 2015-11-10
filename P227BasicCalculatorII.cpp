class Solution1 {
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

class Solution2 {
public: // assume no overflow
    int calculate(string s) {
        stack<int> operands;
        int res = 0, num = 0;
        int sign = '+'; // sign before a number
        for(char c : (s+"+")){
            if(c==' ') continue;
            if(isdigit(c)) num = num*10 + (int)(c-'0');
            else{
                if(sign=='+') operands.push(num);
                if(sign=='-') operands.push(-num);
                if(sign=='*') {
                    int mul = operands.top() * num;
                    operands.pop();
                    operands.push(mul);
                }
                if(sign=='/'){
                    int div = operands.top() / num;
                    operands.pop();
                    operands.push(div);
                }
                sign = c;
                num = 0;
            }
        }
        while(!operands.empty()) {
            res += operands.top();
            operands.pop(); 
        }
        return res;
    }
};

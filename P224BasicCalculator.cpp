class Solution {
public:
    // from d40a
    int calculate(string s) {
        int num = 0, res = 0, sign = 1;
        stack<int> ops;
        stack<int> sums;
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            if(c==' ') continue;
            else if(isdigit(c)){//assume no overflow
                num = num*10 + (int)(c-'0');
            }else{
                res += sign * num; 
                num = 0;
                if(c=='+') sign = 1;
                if(c=='-') sign = -1;
                if(c=='('){
                    ops.push(sign);
                    sums.push(res);
                    // important trick
                    res = 0;
                    sign =1;
                }
                if(c==')' && !ops.empty()){
                    res = sums.top() + ops.top() * res;
                    sums.pop();
                    ops.pop();
                }
            }
        }
        return res + sign * num; // do not forget the last num 
    }
};

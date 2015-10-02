class Solution {
public:
    // assume no overflow
    int eval(int a, int b, string op){
        if(op=="+") return a+b;
        if(op=="-") return a-b;
        if(op=="*") return a*b;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token : tokens){
            if(token=="+"||token=="-"||token=="*"||token=="/"){
                if(s.size()>1){
                    int b = s.top();
                    s.pop();
                    int a = s.top();
                    s.pop();
                    s.push(eval(a, b, token));
                }
            }else{
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};

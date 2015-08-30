class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0) return false;
        stack<char> left_parens;
        for(char c : s){
            if(c=='('||c=='['||c=='{'){
                left_parens.push(c);
            }else{
                if(left_parens.empty()) return false;
                if(c==')' && left_parens.top() !='(') return false;
                if(c==']' && left_parens.top() !='[') return false;
                if(c=='}' && left_parens.top() !='{') return false;
                left_parens.pop();
            }
        }
        return (left_parens.empty()) ? true : false;
    }
};

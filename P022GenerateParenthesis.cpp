class Solution {
public:
    // refer to unique binary search trees II  
    // Key: a possible parenthesis = i outer()s + ( +  n-i-1 inner()s   + )
    vector<string> generateParenthesis(int n) {
        vector<string> parens;
        if(n==0) {
            parens.push_back("");
            return parens;
        }
        if(n==1) {
            parens.push_back("()");
            return parens;
        }
        for(int i=0; i<n; i++){
            for(string outer : generateParenthesis(i)){
                for(string inner : generateParenthesis(n-i-1)){ // here, think carefully
                    parens.push_back(outer+"("+inner+")");
                }
            }
        }
        return parens;
    }
};

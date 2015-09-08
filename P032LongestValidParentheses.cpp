class Solution {
public:
    /**
     * Define D[i], the length of the longest valid parentheses from begining to the i-th char in s
     * initial: D[0] = 0
     * 1) if s[i]==')' and s[i-1] =='(', then D[i] = D[i-2] + 2
     * 2) if s[i]==')', and s[i-1]==')', 
     *    and s[i-1 - D[i-1]] =='(', 
     *    then D[i] = D[i-1] + 2 + D[i-1 - D[i-1] – 1]
     * 
     *    0.. i-2, i-1, i, ....
     */ 
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n==0) return 0;
        vector<int> D(n, 0);
        for(int i=1; i<n; i++){
            if(s[i]==')'){
                if(i>0 && s[i-1]==')'){
                    int left_pos_matching_cur = i-1-D[i-1];
                    if(left_pos_matching_cur>=0){
                        if(s[left_pos_matching_cur]=='('){
                            D[i] = D[i-1] + 2 + D[left_pos_matching_cur-1];
                        }
                    }
                }
                if(i>0 && s[i-1]=='(') {
                    D[i] = D[i-2] + 2;
                }
            }
        }
        return *max_element(D.begin(), D.end());
    }
};

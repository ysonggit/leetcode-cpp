class Solution {
public:
    // can optimize solution with memorization 
    // or DP (Sprague-Grundy Theorem) https://leetcode.com/discuss/64344/theory-matters-from-backtracking-128ms-to-dp-0ms
    bool canWin(string s) {
        int n = s.length();
        if(n<2) return false;
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1] && s[i]=='+'){
                string next = s.substr(0, i) + "--" + s.substr(i+2);
                if(!canWin(next)){
                    return true;
                }
            }
        }
        return false;
    }
};

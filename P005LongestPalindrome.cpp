class Solution {
public:
    /*
        DP O(n^2)
        P[i][j] : substring s[i]...s[j] is a palindrome
        P[i][j] is true if P[i+1][j-1] is true && s[i]==s[j]
    */
    string longestPalindrome(string s) {
        const int n = s.length();
        if(n<2) return s;
        bool P[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                P[i][j] = (i==j) ? true : false;
            }
        }
        int max_len = 1;
        int start_idx = 0;
        for(int j=0; j<n; j++){
            for(int i=j; i>=0; i--){
                P[i][j]= s[i]==s[j] && ((j-i<=1) || (P[i+1][j-1]) ); // mistake 1: important! to check j-i<=1
                                         // mistake 2: wrong condition : (s[i]==s[j] && P[i+1][j-1])||(j-i<=1) 
                if(P[i][j]) {
                    // save start index
                    if(max_len < j-i+1){
                        max_len = j-i+1;
                        start_idx = i;
                    }
                }
            }
        }
        
        return s.substr(start_idx, max_len);
    }
};

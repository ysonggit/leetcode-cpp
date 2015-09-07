class Solution {
public:
    /**
     * D[i][j]: the number of distinct subsequences composed by first i chars in s 
     * that matches the first j chars in t
     * initial: D[i][0] = 1
     * D[i][j] = D[i-1][j] if s[i-1]!= t[j-1] 
     *         = D[i-1][j-1] + D[i-1][j] if s[i-1]=t[j-1] 
     *  0123456
     * "rabbbit" 
     * "rabbit"
     * 
     */
    int numDistinct(string s, string t) {
        int n= s.length(), m=t.length();
        vector<vector<int> > D(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++){
            D[i][0] = 1; // important! 
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]!=t[j-1]){
                    D[i][j] = D[i-1][j];
                }else{
                    D[i][j] = D[i-1][j-1] + D[i-1][j];
                }
            }
        }
        return D[n][m];
    }
};

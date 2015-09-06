class Solution {
public:
    /**
     * D[i][j]: the minimum distance of transforming the first i characters in word1 to 
     * the first j characters in word2
     * initial: D[i][0] = i, D[0][j]= j
     *                insert       replace    delete
     * D[i][j] = D[i-1][j-1] if word1[i]==word2[j]
     *         = min(D[i-1][j], D[i-1][j-1], D[i][j-1]) + 1 if word1[i]!=word2[j]
     */ 
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int> > D(n+1, vector<int>(m+1, 0));
        for(int i=1; i<n+1; i++) D[i][0] = i;
        for(int j=1; j<m+1; j++) D[0][j] = j;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (word1[i-1]==word2[j-1]) {
                    D[i][j] = D[i-1][j-1];
                }else{
                    D[i][j] =min({D[i-1][j], D[i-1][j-1], D[i][j-1]}) + 1;
                }
            }
        }
        return D[n][m];
    }
};

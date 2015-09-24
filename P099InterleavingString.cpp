class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int m = s1.length(), n = s2.length();
        if(m==0) return s2==s3;
        if(n==0) return s1==s3;
        if(m+n!= s3.length()) return false;
        bool D[m+1][n+1];
        D[0][0] = true;
        for(int i=1; i<=m; i++){
            D[i][0] = (D[i-1][0] && s3[i-1]==s1[i-1]) ? true : false;
        }
        for(int j=1; j<=n; j++){
            D[0][j] = (D[0][j-1] && s3[j-1]==s2[j-1]) ? true : false;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                int k = i+j-1;
                D[i][j] = (D[i-1][j] && s3[k]==s1[i-1]) || (D[i][j-1] && s3[k]==s2[j-1]);
            }
        }
        return D[m][n];
    }
};

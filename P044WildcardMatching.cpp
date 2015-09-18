class Solution {
public:
    /**
     * '*' - any sequence including empty
     * D[i][j] : the first i characters in s match first j characters in p
     * initial
     * D[0][j] is true if p[j-1] =='*' && D[0][j-1]
     * if cur is not *
     * D[i][j] = D[i-1][j-1] && (s[j-1]==p[j-1] || p[j-1]==?)
     * if *
     * D[i][j] = true if D[i-1][j-1] is true, also D[i+1][j] ... D[n][j] = true
     *         = true if D[i][j-1] is true    s="aba|a" p="*a|*"
     */ 
    bool isMatch(string s, string p) {
        const int n=s.length(), m= p.length();
        bool** D = new bool*[n+1];
        for(int i=0; i<=n; i++){
            D[i] = new bool[m+1];
            for(int j=0; j<=m; j++){
                D[i][j]= false; // must initialize false!
            }
        }
        D[0][0] = true;
        // initialize
        for(int j=1; j<=m; j++){
            if(p[j-1]=='*' && D[0][j-1]){
                D[0][j] = true;
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1]!='*'){
                    if(D[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='?')) D[i][j]=true;
                }else{
                    if(D[i-1][j-1]){
                        for(int k=i; k<=n; k++) D[k][j] = true;
                    }else{
                        if(D[i][j-1]) D[i][j] = true;
                    }
                }
            }
        }
        return D[n][m];
    }
};

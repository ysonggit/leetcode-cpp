class Solution {
public:
    
    int minCut(string s) {
        int n = s.length();
        if(n<2) return 0;
        vector<vector<int> > P(n, vector<int>(n, 0));
        for(int i=0; i<n; i++) P[i][i] = 1;
        for(int len=2; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int j=i+len-1;
                if(len==2 && s[i]==s[j]) P[i][j] = 1;
                else{
                    P[i][j] = (P[i+1][j-1] && s[i]==s[j]) ? 1: 0;
                }
            }
        }
        vector<int> D(n, n-1);
        for(int i=0; i<n; i++){
            if(P[0][i]>0) D[i]=0;
            else{
                for(int k=0; k<i; k++){
                    if(P[k+1][i]>0) D[i] = min(D[i], D[k]+1);
                }
            }
        }
        return D[n-1];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0) return 0;
        if(s[0]=='0') return 0; // mistake corner case : "0" return 0
        vector<int> D(n+1, 1);
        for(int i=2; i<=n; i++){
            // should check validity of character 
            D[i] = (s[i-1]!='0') * D[i-1] + (s[i-2]=='1' || (s[i-2]=='2'&& s[i-1]<='6')) * D[i-2];
        }
        return D[n];
    }
};

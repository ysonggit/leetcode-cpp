class Solution {
public:
    // DP 
    // Define D[i] boolean value representing the first i chars can be segmented
    // D[i] is true if D[k] is true and substring s[k, i-1] is in dict, k is [0, i-1]
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        if(n==0) return true;
        vector<int> D(n+1, 0);
        D[0] = 1;
        for(int i=1; i<=n; i++){
            for(int k=i-1; k>=0; k--){
                if(D[k]==1 && wordDict.find(s.substr(k, i-k)) != wordDict.end()){
                    D[i] = true;
                }
            }
        }
        return D[n];
    }
};

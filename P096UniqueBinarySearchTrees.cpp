class Solution {
public:
    int numTrees(int n) {
        vector<int> D(n+1, 1);
        for(int i=2; i<=n; i++){
            D[i] =0;
            for(int j=1; j<=i; j++){
                // should check overflow
               D[i] += D[j-1] * D[i-j];
            } 
        }
        return D[n];
    }
};

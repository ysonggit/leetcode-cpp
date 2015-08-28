class Solution {
public:
    // trival O(n^2) space/time DP solution
    int uniquePaths(int m, int n) {
        if(m==0||n==0) return 0;
        vector<vector<int> > D(m, vector<int>(n, 1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                D[i][j] = D[i-1][j] + D[i][j-1];
            }
        }
        return D[m-1][n-1];
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m ==0) return 0;
        int n = matrix[0].size();
        vector<vector<int> > D(m+1, vector<int>(n+1, 0));
        int max_len = 0;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(matrix[i-1][j-1]=='0') D[i][j] = 0;
                else D[i][j] = 1+min({D[i-1][j], D[i][j-1], D[i-1][j-1]});
                max_len = max(max_len, D[i][j]);
            }
        }
        return max_len*max_len;
    }
};

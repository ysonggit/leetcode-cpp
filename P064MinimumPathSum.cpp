class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        vector<vector<int> > D(grid);
        for(int i=1; i<m; i++) D[i][0] += D[i-1][0];
        for(int j=1; j<n; j++) D[0][j] += D[0][j-1];
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                D[i][j] += min(D[i-1][j], D[i][j-1]);
            }
        }
        return D[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int> > D(m, vector<int>(n, 1)); 
        D[0][0] = (obstacleGrid[0][0]== 1) ?  0 : 1; // mistake : start pos may be obstacle!
        for(int i=1; i<n; i++){
            if(obstacleGrid[0][i]==1 || D[0][0] == 0){
                while(i<n) {
                    D[0][i] = 0;
                    i++;
                }
            }
        }
        for(int j=1; j<m; j++){
            if(obstacleGrid[j][0]==1 || D[0][0]==0){
                while(j<m) {
                    D[j][0] = 0;
                    j++;
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                D[i][j] = (obstacleGrid[i][j]==1) ? 0 : D[i-1][j] + D[i][j-1];
            }
        }
        return D[m-1][n-1];
    }
};

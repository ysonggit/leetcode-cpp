class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m==0) return 0;
        int n = dungeon[0].size();
        vector<vector<int> > D(m+1, vector<int>(n+1, INT_MAX));
        D[m][n-1] = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(dungeon[i][j]<=0 ||min(D[i+1][j], D[i][j+1])> dungeon[i][j]){
                    D[i][j] = min(D[i+1][j], D[i][j+1]) - dungeon[i][j];
                }else{
                    D[i][j] = 1;
                }
            }
        }
        return D[0][0];
    }
};

class Solution {
public:
    /**
     * DP define D[i][j]: minimum cost of painting first i houses, the i-th house uses j-th color
     * D[i][j] = cost[i][j] + min(D[i-1][j1], D[i-1][j2])
     *    note if j=0, j1=1, j2=2
     *            j=1, j1=0, j2=2
     *            j=2, j1=0, j2=1
     */
    int minCost(vector<vector<int>>& costs) {
       int n = costs.size();
       if(n==0) return 0;
       vector<vector<int> > D (n+1, vector<int>(3, 0));
       for(int i=1; i<=n; i++){
           D[i][0] = costs[i-1][0] + min(D[i-1][1], D[i-1][2]);
           D[i][1] = costs[i-1][1] + min(D[i-1][0], D[i-1][2]);
           D[i][2] = costs[i-1][2] + min(D[i-1][0], D[i-1][1]);
       }
       return min({D[n][0], D[n][1], D[n][2]});
    }
};

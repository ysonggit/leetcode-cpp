class Solution {
public:
    // D[i][j]: the minimum cost of painting hourse[i] with color[j]
    // D[i][j] = costs[i][j] + min(D[i-1][p], .. ) p = {0,...,k}\{j}
    // initialize: D[0][0] = 0
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n==0) return 0;
        int k = costs[0].size();
        vector<vector<int> > D(n+1, vector<int>(k, 0));
        for(int i=1; i<=n; i++){
            for(int j=0; j<k; j++){
                int min_cost_color_j = INT_MAX;
                for(int p=0; p<k; p++){
                    if(p==j) continue;
                    min_cost_color_j = min(min_cost_color_j, D[i-1][p]);
                }
                if(k<=1) D[i][j] = costs[i-1][j]; // mistake: corner case : k=1
                else D[i][j] = costs[i-1][j] + min_cost_color_j;
            }
        }
        int min_cost = INT_MAX;
        for(int i=0; i<k; i++){
            min_cost = min(min_cost, D[n][i]);
        }
        return min_cost;
    }
};

class Solution {
public:
    // from jinwu
    // https://leetcode.com/discuss/62026/clean-java-dp-solution-with-comment
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        if(k>=n){
            int max_profit = 0;
            for(int i=1; i<n; i++){
                int diff = prices[i] - prices[i-1];
                if(diff>0) max_profit += diff;
            }
            return max_profit;
        }
        vector<vector<int>> D(n, vector<int>(k+1, 0));
        for(int j=1; j<=k; j++){
            int local_max = D[0][j-1] - prices[0];
            for(int i=1; i<n; i++){
                D[i][j] = max(D[i-1][j], prices[i]+local_max);
                local_max = max(local_max, D[i][j-1] - prices[i]);
            }
        }
        return D[n-1][k];
    }
};

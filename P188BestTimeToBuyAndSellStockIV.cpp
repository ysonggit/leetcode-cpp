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
            int max_diff = D[0][j-1] - prices[0]; // mistake: initial value can not be 0
            for(int i=1; i<n; i++){
                // for h in [0,i-1] find max_of_(D[h][j]-prices[h])
                for(int h=0; h<i; h++){
                    max_diff = max(D[h][j-1]-prices[h], max_diff);
                }
                D[i][j] = max(D[i-1][j], prices[i]+max_diff);
            }
        }
        return D[n-1][k];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        int lowest = prices[0], max_profit = 0;
        for(int i=1; i<n; i++){
            max_profit = max(max_profit, prices[i]-lowest);
            lowest = min(lowest, prices[i]);
        }
        return max_profit;
    }
};

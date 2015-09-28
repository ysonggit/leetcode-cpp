class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        int max_profit = 0;
        for(int i=1; i<n; i++){
            int diff =prices[i]-prices[i-1];
            max_profit += (diff>0) ? diff : 0;
        }
        return max_profit;
    }
};

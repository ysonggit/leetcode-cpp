class Solution {
public:
    // 1 2 0 4 1 3 9
    // 0 1 1 4 4 4 8
    // 9 9 9 8 8 6 0
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<int> before(n, 0), after(n, 0);
        int lowest = prices[0], highest = prices[n-1];
        for(int i=1; i<n; i++){
            before[i] = max(before[i-1], prices[i]-lowest);
            lowest = min(lowest, prices[i]);
        }
        for(int i=n-2; i>=0; i--){
            after[i] = max(after[i+1], highest-prices[i]);
            highest = max(highest, prices[i]);
        }
        int max_profit = 0;
        for(int i=0; i<n-1; i++){
            max_profit = max(max_profit, before[i]+after[i]);
        }
        return max_profit;
    }
};

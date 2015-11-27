class Solution {
public:
// from whnzinc
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n+1, 0), noop(n+1, 0), sell(n+1, 0), cool(n+1, 0);
        noop[0] = buy[0] = INT_MIN;
        for(int i=1; i<=n; i++){
            int price = prices[i-1];
            buy[i] = cool[i-1] - price;
            cool[i] = max(cool[i-1], sell[i-1]);
            noop[i] = max(noop[i-1], buy[i-1]);
            sell[i] = noop[i] + price;
        }
        return max(sell[n], cool[n]);
    }
};

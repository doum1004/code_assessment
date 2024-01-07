/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

Solution1. Accumulate profits
time: o(n)
space: o(1)

trade n time
- buy: min(buy, price - previous profit)
- profit: max(profit, price - buy)

ex)       3 3 5 0 0 3 1 4
trade1
- buy   : 3 3 3 0 0 0 0 0
- profit: 0 0 2 2 2 3 3 4
Trade 2
- buy   : 3 3 3 -2 -2 -2 -2 -2
- profit: 0 0 2 2 2 5 5 6

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        vector<pair<int,int>> dp(k);
        for (int i=0; i<k; ++i)
            dp[i] = {INT_MAX, 0};
        
        for (int i=0; i<prices.size(); ++i) {
            int pre = 0;
            for (int j=0; j<dp.size(); ++j) {
                dp[j].first = min(dp[j].first, prices[i] - pre);
                dp[j].second = max(dp[j].second, prices[i] - dp[j].first);
                pre = dp[j].second;
            }
        }
        return dp.back().second;
    }
};
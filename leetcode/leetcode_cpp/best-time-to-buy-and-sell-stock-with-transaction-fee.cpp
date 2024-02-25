/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
https://www.youtube.com/watch?v=QOvDwbIC4Pk

1. dp memorization
time: o(n)
space: o(n)

2. dp tabulation (bottom up) 2d array
time: o(n)
space: o(n)

3. dp tabulation (bottom up) 1d
time: o(n)
space: o(1)
*/
class Solution {
public:
    int recursion(vector<int>& prices, int fee, unordered_map<int, unordered_map<bool, int>>& dp, int i, bool holding) {
        if (i == prices.size()) return 0;
        if (dp.count(i) && dp[i][holding]) return dp[i][holding];
        if (holding) {
            dp[i][holding] = max(recursion(prices, fee, dp, i+1, holding), prices[i] - fee + recursion(prices, fee, dp, i+1, !holding));
        }
        else {
            dp[i][holding] = max(recursion(prices, fee, dp, i+1, holding), -prices[i] + recursion(prices, fee, dp, i+1, !holding));
        }
        return dp[i][holding];
    }

    int maxProfit_1(vector<int>& prices, int fee) {
        unordered_map<int, unordered_map<bool, int>> dp;
        return recursion(prices, fee, dp, 0, false);
    }

    int maxProfit_2(vector<int>& prices, int fee) {
        if (!prices.size()) return 0;
        vector<int> holds(prices.size()+1, 0);
        vector<int> not_holds(prices.size()+1, 0);
        for (int i=prices.size()-1; i>=0; --i) {
            holds[i] = max(holds[i+1], prices[i] - fee + not_holds[i+1]);
            not_holds[i] = max(not_holds[i+1], -prices[i] + holds[i+1]);
        }
        return not_holds[0];
    }
    
    int maxProfit_3_1(vector<int>& prices, int fee) {
        if (!prices.size()) return 0;
        int hold = 0;
        int not_holds = 0;
        for (int i=prices.size()-1; i>=0; --i) {
            int temp_hold = hold;
            hold = max(hold, prices[i] - fee + not_holds);
            not_holds = max(not_holds, -prices[i] + temp_hold);
        }
        return not_holds;
    }

    int maxProfit_3_2(vector<int>& prices, int fee) {
        if (!prices.size()) return 0;
        int profit = 0, effectiveBuy = prices[0];
        for (int i=1; i<prices.size(); ++i) {
            profit = max(profit, prices[i] - effectiveBuy - fee);
            effectiveBuy = min(effectiveBuy, prices[i] - profit);
        }
        return profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        return maxProfit_3_1(prices, fee);
    }
};
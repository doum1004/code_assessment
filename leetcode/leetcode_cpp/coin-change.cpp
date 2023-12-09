/*
https://leetcode.com/problems/coin-change

Solution1. recursion memorization
time: o(nm) 2^n -> n
space: o(nm) height

Solution2. iteration tabulation (1D dp)
time: o(nm)
space: o(nm)
*/
class Solution {
public:
    int findCoins(vector<int>& coins, int amount, int idx, vector<vector<int>>& m) {
        if (amount <= 0 || idx == coins.size()) return amount == 0 ? 0 : INT_MAX-1;
        if (m[idx][amount] != -1) return m[idx][amount];

        int v1 = findCoins(coins, amount, idx+1, m); // move to next coin
        int v2 = 1 + findCoins(coins, amount - coins[idx], idx, m); // take this coin
        m[idx][amount] = min(v1, v2);
        return m[idx][amount];
    }
    int coinChange_1(vector<int>& coins, int amount) {
        vector<vector<int>> m(coins.size(), vector<int>(amount+1, -1)); // [coinIdx][amount]
        int res = findCoins(coins, amount, 0, m);
        return res < INT_MAX - 1 ? res : -1;                
    }
    int coinChange_2(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for (int i=1; i<= amount; i++) {
            for (int j=0; j<coins.size(); ++j) {
                if (i >= coins[j]) dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        return dp[amount] < INT_MAX - 1 ? dp[amount] : -1;
    }
    int coinChange(vector<int>& coins, int amount) {
        return coinChange_2(coins, amount);
    }
};
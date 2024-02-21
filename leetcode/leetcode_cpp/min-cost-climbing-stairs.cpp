/*
https://leetcode.com/problems/min-cost-climbing-stairs

1. memorization
time: o(n)
space: o(n)

2. tabulation (bottom up)
time: o(n)
space: o(1) in place modifiation
*/
class Solution {
public:
    int dfs(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size()) return 0;
        if (dp[i] != -1) return dp[i];
        dp[i] = cost[i] + min(dfs(cost, i+1, dp), dfs(cost, i+2, dp));
        return dp[i];

    }

    int minCostClimbingStairs_1(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        dfs(cost, 0, dp);
        dfs(cost, 1, dp);
        return min(dp[0], dp[1]);
    }

    int minCostClimbingStairs_2(vector<int>& cost) {
        for (int i=2; i<cost.size(); ++i) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[cost.size()-1], cost[cost.size()-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return minCostClimbingStairs_1(cost);
    }
};
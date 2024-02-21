'''
https://leetcode.com/problems/min-cost-climbing-stairs

1. memorization
time: o(n)
space: o(n)

2. tabulation (bottom up)
time: o(n)
space: o(1) in place modifiation
'''
class Solution:
    def minCostClimbingStairs_1(self, cost: List[int]) -> int:
        dp = [-1] * len(cost)
        def dfs(i):
            if i >= len(cost): return 0
            if dp[i] != -1: return dp[i]
            dp[i] = cost[i] + min(dfs(i+1), dfs(i+2))
            return dp[i]
        return min(dfs(0), dfs(1))

    def minCostClimbingStairs_2(self, cost: List[int]) -> int:
        for i in range(2, len(cost)):
            cost[i] += min(cost[i-1], cost[i-2])
        return min(cost[len(cost)-1], cost[len(cost)-2])
        
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        return self.minCostClimbingStairs_2(cost)
        
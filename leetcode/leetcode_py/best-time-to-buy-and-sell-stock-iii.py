'''
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description

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
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        k = 2
        dp = []
        for i in range(k):
            dp.append([float(inf), 0])

        for i in range(len(prices)):
            profit = 0
            for j in range(k):
                dp[j][0] = min(dp[j][0], prices[i] - profit)
                dp[j][1] = max(dp[j][1], prices[i] - dp[j][0])
                profit = dp[j][1]
        return dp[-1][1]
        
        
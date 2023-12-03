'''
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

Solution1. Two Pointers
time: o(n)
space: o(1)
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n < 2: return 0

        res = 0
        l, r = 0, 1
        while r < n:
            res += max(0, prices[r] - prices[l])
            l += 1
            r += 1
        return res
        
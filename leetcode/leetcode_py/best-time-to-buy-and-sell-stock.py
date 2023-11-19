'''
https://leetcode.com/problems/best-time-to-buy-and-sell-stock

Solution1. Find min value before index and find max value from it

   3 2 1 5 7
l: 3. max value: 0
l: 2. max value: 0
l: 1. max value: 0
l: 1. max value: 4
l: 1. max value: 6
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minValue = float(inf)
        res = 0
        for p in prices:
            res = max(res, p - minValue)
            minValue = min(minValue, p)            
        return res
        
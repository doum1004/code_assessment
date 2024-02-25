'''
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
'''
class Solution:
    def maxProfit_1(self, prices: List[int], fee: int) -> int:
        dp = {}
        def recursion(i, holding):
            if i == len(prices): return 0
            if (i, holding) in dp: dp[(i, holding)]
            new = 0
            if holding:
                new = prices[i] - fee + recursion(i+1, not holding)
            else:
                new = -prices[i] + recursion(i+1, not holding)
            dp[(i, holding)] = max(recursion(i+1, holding),  new)
            return dp[(i, holding)]
        return recursion(0, False)

    def maxProfit_2(self, prices: List[int], fee: int) -> int:
        holds = [0] * (len(prices) + 1)
        not_holds = [0] * (len(prices) + 1)
        for i in range(len(prices)-1, -1, -1):
            holds[i] = max(holds[i+1], prices[i] - fee + not_holds[i+1])
            not_holds[i] = max(not_holds[i+1], -prices[i] + holds[i+1])
        return not_holds[0]

    def maxProfit_3(self, prices: List[int], fee: int) -> int:
        hold = 0
        not_hold = 0
        for i in range(len(prices)-1, -1, -1):
            temp = hold
            hold = max(hold, prices[i] - fee + not_hold)
            not_hold = max(not_hold, -prices[i] + temp)
        return not_hold

    def maxProfit(self, prices: List[int], fee: int) -> int:
        return self.maxProfit_3(prices, fee)
        
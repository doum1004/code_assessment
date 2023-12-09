'''
https://leetcode.com/problems/coin-change

Solution1. recursion memorization
time: o(nm) 2^n -> n
space: o(nm) height

Solution2. iteration tabulation (1D dp)
time: o(nm)
space: o(nm)
'''
class Solution:
    def coinChange_1(self, coins: List[int], amount: int) -> int:
        dp = [[-1 for i in range(amount+1)] for j in range(len(coins))]
        def findCoins(amount, idx):
            if amount <= 0 or idx == len(coins): return 0 if amount == 0 else float('inf') - 1
            if dp[idx][amount] != -1: return dp[idx][amount]

            v1 = findCoins(amount, idx+1)
            v2 = 1 + findCoins(amount-coins[idx], idx)
            dp[idx][amount] = min(v1, v2)
            return dp[idx][amount]
        res = findCoins(amount, 0)
        return res if res < float('inf') - 1 else -1

    def coinChange_2(self, coins: List[int], amount: int) -> int:
        dp = [float(inf) - 1] * (amount+1)
        dp[0] = 0
        for i in range(amount+1):
            for j, v in enumerate(coins):
                if i >= v: dp[i] = min(dp[i], 1 + dp[i - v])
        return dp[-1] if dp[-1] < float(inf) - 1 else -1
        
    def coinChange(self, coins: List[int], amount: int) -> int:
        return self.coinChange_2(coins, amount)
        
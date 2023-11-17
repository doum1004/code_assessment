
from typing import List

"""
https://leetcode.com/problems/coin-change-2/
"""
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        #cur = [0] * (amount+1)
        cur = [0 for i in range(amount+1)]
        cur[0] = 1
        #coins.sort()
        for coin in coins:
            for i in range(coin, amount+1):
                cur[i] += cur[i-coin]
                
        return cur[-1]
        
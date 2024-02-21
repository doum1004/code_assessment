'''
https://leetcode.com/problems/domino-and-tromino-tiling

1. dp
time: o(n)
space: o(n)
'''
class Solution:
    def numTilings(self, n: int) -> int:
        if n <= 2: return n
        if n == 3: return 5
        dp = [0] * (n+1)
        dp[1] = 1
        dp[2] = 2
        dp[3] = 5
        for i in range(4, n+1):
            dp[i] = (2*dp[i-1] + dp[i-3]) % 1000000007
        return dp[n]
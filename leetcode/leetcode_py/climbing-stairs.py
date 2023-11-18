'''
https://leetcode.com/problems/climbing-stairs
'''

class Solution:
    def climbStairs_recursive(self, n: int) -> int:
        if n == 0 or n == 1: return 1
        return self.climbStairs_recursive(n - 1) + self.climbStairs_recursive(n - 2)

    def climbStairs_recursive_mem(self, n: int) -> int:
        mem = {}
        def recursive(n):
            if n == 0 or n == 1: return 1
            if not n in mem:
                mem[n] = recursive(n - 1) + recursive(n - 2)
            return mem[n]
        return recursive(n)

    def climbStairs_iterate_mem(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        dp = [1, 1]
        for i in range(2,n+1):
            dp[i] = dp[i-2] + dp[i-1]
        return dep[n]       

    def climbStairs_iterate_nomem(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        cur = 1
        prev = 1
        for i in range(2, n+1):
            temp = cur
            cur = prev + cur
            prev = temp
        return cur
        
    def climbStairs(self, n: int) -> int:
        return self.climbStairs_iterate_nomem(n)
        
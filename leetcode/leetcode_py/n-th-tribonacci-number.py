'''
https://leetcode.com/problems/n-th-tribonacci-number

1. Iteration
time: o(n)
space: o(1)
'''
class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 2: return n
        a,b,c = 0,1,1
        while n-2 > 0:
            c, b, a = a + b + c, c, b
            n -= 1
        return c
        
'''
https://leetcode.com/problems/sqrtx

Solution1. Iteration
time: o(n)
space: o(1)

Solution2. Binary search
time: o(logn)
space: o(1)

1 2 3 4 5 6 7 8 (ans 2)
l: 1, r: 8

'''

class Solution:
    def mySqrt_1(self, x: int) -> int:
        if x <= 1: return x

        i = 0
        while i < x:
            if i * i > x:
                return i-1
            i += 1
        return 1
        
    def mySqrt_2(self, x: int) -> int:
        l = 1
        r = x
        while l <= r:
            m = l + (r - l) // 2
            if m == x // m:
                return m
            if x // m < m:
                r = m - 1
            else:
                l = m + 1

        return r

    def mySqrt(self, x: int) -> int:
        return self.mySqrt_2(x)
'''
https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

1. bit manipulation
time: o(n)
space: o(1)
'''
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        res = 0
        while a or b or c:
            abit = a & 1
            bbit = b & 1
            cbit = c & 1
            if cbit == 0:
                res += abit + bbit
            elif abit + bbit == 0:
                res += 1
            a >>= 1
            b >>= 1
            c >>= 1
        return res
        
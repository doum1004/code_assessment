'''
https://leetcode.com/problems/bitwise-and-of-numbers-range

Solution1. Iternate and cal bit
time: o(n)
space: o(1)

[5, 6, 7]
right: 7 (111)
111 -> 111 & 110 -> 110 & 101 -> 100
'''
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        res = right
        while res > left:
            res &= res - 1        
        return res
        
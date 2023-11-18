'''
https://leetcode.com/problems/number-of-1-bits

solution1. bit manipulation
time: o(logn)
space: o(1)

solution2. bit manipulation (popcount). erase lesat 1 each time
time: o(logn)
space: o(1)

ex) 001101
count(1) 001101 & 001100 = 001100
count(2) 001100 & 001011 = 001000
count(3) 001000 & 000111 = 000000

'''

class Solution:
    def hammingWeight_1(self, n: int) -> int:
        c = 0
        while n > 0:
            if n & 1 != 0: # or n % 2 == 1
                c += 1
            n >>= 1
        return c

    def hammingWeight_2(self, n: int) -> int:
        c = 0
        while n != 0:
            n &= (n-1)
            c += 1
        return c

    def hammingWeight(self, n: int) -> int:
        return self.hammingWeight_2(n)
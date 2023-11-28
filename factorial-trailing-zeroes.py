'''
https://leetcode.com/problems/factorial-trailing-zeroes

Solution1. math
time: o(logn)

The ZERO comes from 10.
The 10 comes from 2 x 5
And we need to account for all the products of 5 and 2. likes 4×5 = 20 ...
So, if we take all the numbers with 5 as a factor, we'll have way more than enough even numbers to pair with them to get factors of 10

'''
class Solution:
    def trailingZeroes(self, n: int) -> int:
        result = 0
        i = 5
        while n / i > 0:
            result += n//i
            i *= 5
            
        return result
        
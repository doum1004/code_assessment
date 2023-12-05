"""
https://leetcode.com/problems/integer-to-roman
"""

class Solution:
    def intToRoman(self, num: int) -> str:
        nums = [ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 ]
        symboles = [ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" ]
        
        res = ''
        for i in range(len(nums)):
            res += num // nums[i] * symboles[i]
            num %= nums[i]
            
        return res
        
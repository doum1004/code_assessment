from typing import List

'''
https://leetcode.com/problems/plus-one
'''

class Solution:
    def plusOne_1(self, digits: List[int]) -> List[int]:
        for i in range(len(digits)-1, -1,-1):
            digits[i] += 1
            if digits[i] == 10:
                digits[i] = 0
            else:
                return digits
        return [1] + digits
    
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        i = n - 1
        while i >= 0:
            digits[i] += 1
            if digits[i] != 10:                
                break
            digits[i] = 0
            if i == 0:
                digits.insert(0, 1)
            i -= 1
        return digits
        
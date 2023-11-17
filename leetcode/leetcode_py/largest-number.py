from typing import List

"""
https://leetcode.com/problems/largest-number/
"""

class LargerNumKey(str):
    def __lt__(x,y):
        return x+y > y+x

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = map(str, nums)
        result = ''.join(sorted(nums, key=LargerNumKey))
        return '0' if result[0] == '0' else result
        
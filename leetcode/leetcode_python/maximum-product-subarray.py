from typing import List

"""
https://leetcode.com/problems/maximum-product-subarray/
"""

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        preA = preB = res = nums[0]
        for i in range(1, len(nums)):
            n = nums[i]
            a, b = n * preA, n * preB
            preA, preB = min(n,a,b), max(n,a,b)
            res = max(res, preA, preB)
        return res
        
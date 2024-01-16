'''
https://leetcode.com/problems/maximum-average-subarray-i

Solution1. Sliding Window
time: o(n)
space: o(1)
'''
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        s = 0.0
        l, r = 0, 0
        while r < k:
            s += nums[r]
            r += 1
        res = s
        while r < len(nums):
            s += nums[r] - nums[l]
            res = max(res, s)
            l += 1
            r += 1
        return res / k
            

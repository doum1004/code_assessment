'''
https://leetcode.com/problems/max-consecutive-ones-iii

1. Sliding window
time: o(n)
space: o(1)
'''
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        l, res = 0, 0
        for r in range(n):
            if nums[r] == 0: k -= 1
            while k < 0 and l < r:
                if nums[l] == 0: k += 1
                l += 1
            if k >= 0:
                res = max(res, r - l + 1)
        return res
        
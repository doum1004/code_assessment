'''
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

Solution1. iterate
time: o(n)
space: o(1)

Solution2. Bin search
time: o(logn)
space: o(1)
loop
1) if nums[l] < nums[r] return nums[l]
2) if nums[l] > nums[r]
2.1) if nums[m] < nums[r] r= m
2.2) if nums[m] > nums[r] l = m+1
'''
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return nums[0]
        l, r = 0, n-1
        while l<=r:
            m = l + (r-l) // 2
            if nums[l] < nums[r]: return nums[l]
            if nums[m] < nums[r]: r = m
            else: l = m + 1
        return nums[r]
        
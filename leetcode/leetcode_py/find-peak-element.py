'''
https://leetcode.com/problems/find-peak-element

Solution1. linear
time: o(n)
space: o(1)

Solution2. binary search
time: o(logn)
space: o(1)
'''
class Solution:
    def findPeakElement_linear(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return 0
        
        maxValue = nums[0]
        maxIdx = 0
        for i in range(1, n):
            if maxValue < nums[i]:
                maxValue = nums[i]
                maxIdx = i
        return maxIdx

    def findPeakElement_bs(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return 0
        l = 0
        r = n - 1
        while l < r:
            m = l + (r - l) // 2
            if nums[m] > nums[m+1]:
                r = m
            else:
                l = m+1
            
        return l
        
    def findPeakElement(self, nums: List[int]) -> int:
        return self.findPeakElement_bs(nums)
            
        
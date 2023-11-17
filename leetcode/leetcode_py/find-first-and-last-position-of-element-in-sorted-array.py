from typing import List

"""
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
"""

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0: return [-1,-1]
        def lower_bound(t):
            i,j=0,len(nums)-1
            while i<j:
                m = (j-i)//2+i
                if nums[m] < t: i=m+1
                else: j=m
            return i if nums[i] == t else -1
            
        def upper_bound(t):
            i,j=0,len(nums)-1
            while i<j:
                m = (j-i+1)//2+i
                if nums[m] <= t: i=m
                else: j=m-1
            return j if nums[j] == t else -1
        
        l = lower_bound(target)
        r = upper_bound(target)
        return [l,r] if l != -1 and r != -1 else [-1,-1]
            
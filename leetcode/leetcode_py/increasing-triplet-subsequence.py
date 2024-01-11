'''
https://leetcode.com/problems/increasing-triplet-subsequence

Solution1. Max List
time: o(n)
space: o(n)

Solution2. One pass
time: o(n)
space: o(1)
'''
class Solution:
    def increasingTriplet_1(self, nums: List[int]) -> bool:
        n = len(nums)
        maxRight = [0] * n
        maxRight[-1] = nums[-1]
        for i in range(n-2, -1, -1):
            maxRight[i] = max(nums[i], maxRight[i+1])
        
        minLeft = nums[0]
        for i in range(1, n-1):
            if minLeft < nums[i] and nums[i] < maxRight[i+1]:
                return True
            minLeft = min(minLeft, nums[i])
        return False
    def increasingTriplet_2(self, nums: List[int]) -> bool:
        low, middle = float(inf), float(inf)
        for i in range(len(nums)):
            if middle < nums[i]: return True
            if nums[i] < low: low = nums[i]
            elif low < nums[i] and nums[i] < middle: middle = nums[i]
        return False

    def increasingTriplet(self, nums: List[int]) -> bool:
        return self.increasingTriplet_2(nums)
        
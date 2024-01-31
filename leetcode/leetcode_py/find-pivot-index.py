'''
https://leetcode.com/problems/find-pivot-index

1. Sum list and compare
time: o(n)
space: o(n)

2. Accumulate and distract in iteration
time: o(n)
space: o(1)
'''
class Solution:
    def pivotIndex_1(self, nums: List[int]) -> int:
        v1 = [0] * len(nums)
        s = 0
        for i in range(len(nums)-1,-1,-1):
            v1[i] = s
            s += nums[i]

        s = 0
        for i in range(len(nums)):
            if s == v1[i]:
                return i
            s += nums[i]
        return -1

    def pivotIndex_2(self, nums: List[int]) -> int:
        s = 0
        for num in nums: s += num

        s1 = 0
        for i in range(len(nums)):
            s -= nums[i]
            if s == s1:
                return i
            s1 += nums[i]
        return -1

    def pivotIndex(self, nums: List[int]) -> int:
        return self.pivotIndex_2(nums)
        
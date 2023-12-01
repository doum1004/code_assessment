'''
https://leetcode.com/problems/search-in-rotated-sorted-array

Solution1. Iteration
time: o(n)
space: o(1)

Solution2. binary search
time: o(logn)
space: o(1)
'''
class Solution:
    def search_1(self, nums: List[int], target: int) -> int:
        for i in range(len(nums)):
            if nums[i] == target:
                return i
        return -1
    def search_2(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while l <= r:
            m = (l+r) // 2
            mNum = nums[m]
            if mNum == target:
                return m
            if mNum > nums[r]:
                if target < mNum and target >= nums[l]:
                    r = m-1
                else:
                    l = m+1
            elif mNum < nums[l]:
                if target > mNum and target <= nums[r]:
                    l = m + 1
                else:
                    r = m - 1
            else:
                if target < mNum:
                    r = m - 1
                else:
                    l = m + 1
        return -1
    def search(self, nums: List[int], target: int) -> int:
        return self.search_2(nums, target)
        
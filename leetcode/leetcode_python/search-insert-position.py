'''
https://leetcode.com/problems/search-insert-position
'''
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r, m = 0, len(nums) - 1, 0
        while l<=r:
            m = int((l+r)/2)
            print(l, r, m)
            if nums[m] == target:
                return m
            if nums[m] > target:
                r = m - 1
            else:
                l = m + 1

        return m if nums[m] > target else m + 1
        
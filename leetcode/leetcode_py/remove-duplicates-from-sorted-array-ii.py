'''
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

Solution1. Erase if duplicates
time: o(n^2). iterate * erase
space: o(1)

Solution2. Hashmap
time: o(n)
space: o(n)

Solution3. Without extra memory
time: o(n)
space: o(1)
'''
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 3: return len(nums)
        cur = 0
        for i in range(2, len(nums)):
            if nums[i] != nums[cur]:
                nums[cur + 2] = nums[i]
                cur += 1
        return cur + 2
        
'''
https://leetcode.com/problems/longest-consecutive-sequence

Solutions1. sort + sliding window
time: o(nlogn)
space: o(1)

Solutions2. store it into hash map and iterate to find it has next or not
time: o(n)
space: o(1)

'''

class Solution:
    def longestConsecutive_1(self, nums: List[int]) -> int:
        if len(nums) < 2: return len(nums)

        nums = sorted(nums)
        r = 1
        res = 1
        cnt = 1

        while r < len(nums):            
            if nums[r-1] + 1 == nums[r]:
                cnt += 1
                res = max(res, cnt)
            elif nums[r-1] != nums[r]:
                cnt = 1
            r += 1
        return res

    def longestConsecutive_2(self, nums: List[int]) -> int:
        if len(nums) < 2: return len(nums)
        h = set(nums)
        res = 1
        for n in h:
            if n - 1 in h:
                continue
            cnt = 1
            while n + cnt in h:
                cnt += 1
            res = max(res, cnt)
        return res

    def longestConsecutive(self, nums: List[int]) -> int:
        return self.longestConsecutive_2(nums)
'''
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

Solution1. sliding window
time: o(n)
space: o(1)

Solution2. iterate cur and prev sections
time: o(n)
space: o(1)
'''
class Solution:
    def longestSubarray_1(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, 0
        m = -1
        res = 0
        curSum = 0
        while r < n:
            if nums[r]:
                curSum += 1
            else:
                if m == -1:
                    m = r
                else:
                    res = max(res, curSum)
                    curSum = 0
                    r = m
                    m = -1
            r += 1
        res = max(res, curSum)
        return res - 1 if res == n else res

    def longestSubarray_2(self, nums: List[int]) -> int:
        n = len(nums)
        cur, prev = 0, 0
        res = 0
        for i in range(n):
            if nums[i]:
                cur += 1
            else:
                res = max(res, cur + prev)
                prev = cur
                cur = 0
        res = max(res, cur + prev)
        return res - 1 if res == n else res
        
    def longestSubarray(self, nums: List[int]) -> int:
        return self.longestSubarray_2(nums)
        
        
from typing import List

"""
https://leetcode.com/problems/summary-ranges/
"""

class Solution:
    def summaryRanges_1(self, nums: List[int]) -> List[str]:
        if not len(nums): return []

        res = []
        start = nums[0]
        count = 0
        for i in range(1, len(nums) + 1):
            if i < len(nums) and start + count + 1 == nums[i]:
                count += 1
            else:
                s = str(start)
                if count != 0:
                    s += "->" + str(start+count)
                res.append(s)
                if i < len(nums):
                    start = nums[i]
                    count = 0
        return res
                
    def summaryRanges_2(self, nums: List[int]) -> List[str]:
        n = len(nums)
        if not n:
            return []
        res = []
        l = 0
        r = 1
        while r <= n:
            while r < n and nums[r - 1] + 1 == nums[r]:
                r += 1
            
            if (l == r - 1):
                res.append(str(nums[l]))
            else:
                res.append(str(nums[l]) + "->" + str(nums[r-1]))

            l = r
            r += 1
        return res

    def summaryRanges(self, nums: List[int]) -> List[str]:
        return self.summaryRanges_2(nums)
        
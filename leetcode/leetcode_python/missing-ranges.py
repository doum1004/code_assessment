from typing import List

"""
https://leetcode.com/problems/missing-ranges/
"""

class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        res = []
        for i in range(len(nums) + 1):
            l = lower if i == 0 else nums[i-1]+1
            r = upper if i == len(nums) else nums[i]-1
            
            if l<=r:
                s = str(l)
                if l < r:
                    s += "->" + str(r)
                res.append(s)
        
        return res
        
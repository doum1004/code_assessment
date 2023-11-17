from typing import List

"""
https://leetcode.com/problems/sort-colors/
"""

from typing import List

class Solution:
    def sortColors_count(self, nums: List[int]) -> None:
        n = len(nums)
        counter = [0] * 3
        for n in nums:
            counter[n] += 1
        
        idx = 0
        for i in range(len(counter)):
            for j in range(1, counter[i] + 1):
                nums[idx] = i
                idx += 1
                
    def sortColors_onepass(self, nums: List[int]) -> None:
        n = len(nums)
        l,r,cur = 0,n-1,0
        while cur<=r:
            if nums[cur] == 0:
                nums[l], nums[cur] = nums[cur], nums[l]
                l += 1
                cur += 1
            elif nums[cur] == 2:
                nums[cur], nums[r] = nums[r], nums[cur]
                r -= 1
            else:
                cur += 1
        
    def sortColors(self, nums: List[int]) -> None:
        #self.sortColors_count(nums)
        self.sortColors_onepass(nums)
        
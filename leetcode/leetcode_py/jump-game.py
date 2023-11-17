from typing import List

"""
https://leetcode.com/problems/jump-game/
"""

class Solution:
    def canJump_dp(self, nums: List[int]) -> bool:
        n = len(nums)
        t = [0 for i in range(n)]
        t[n-1] = 1
        for i in range(n-1, -1, -1):
            p = i + nums[i]
            if p >= n-1:
                t[i] = True
            else:
                for j in range(i+1,min(p+1, n)):
                    if t[j]:
                        t[i] = True
                        break
        
        return t[0] == 1
        
    def canJump_greedy(self, nums: List[int]) -> bool:
        n,m = len(nums),0
        if n < 1: return False
        
        for i, v in enumerate(nums):
            if m<i: return False
            if m >= n-1: return True
            m = max(m, i+v)
            
        return False
    
    def canJump(self, nums: List[int]) -> bool:
        #return self.canJump_dp(nums)
        return self.canJump_greedy(nums)
        
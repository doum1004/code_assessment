"""
https://leetcode.com/problems/container-with-most-water/
"""

class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        if (n < 1):
            return 0
        
        maxArea = 0
        l,r = 0,n-1
        while (l<r):
            area = min(height[l], height[r]) * (r-l)
            maxArea = max(area, maxArea)
            if (height[l] < height[r]):
                l += 1
            else:
                r -= 1
                
        return maxArea
        
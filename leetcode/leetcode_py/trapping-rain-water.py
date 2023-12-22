'''
https://leetcode.com/problems/trapping-rain-water

Solution1. Keep max l, r and get space
time: o(n)
space: o(n)

Solution2. Sliding window. Two pointers
time: o(n)
space: o(1)
'''
class Solution:
    def trap_1(self, height: List[int]) -> int:
        n = len(height)
        if n < 3: return 0
        lmax = [0] * n
        lmax[0] = height[0]
        rmax = [0] * n
        rmax[n-1] = height[n-1]
        
        for i in range(1, n):
            lmax[i] = max(lmax[i-1], height[i])
            
        for i in range(n-2, -1, -1):
            rmax[i] = max(rmax[i+1], height[i])

        res = 0
        for i in range(n):
            ref = min(lmax[i], rmax[i])
            if ref > height[i]: res += ref - height[i]
        return res
    def trap_2(self, height: List[int]) -> int:
        n = len(height)
        if n < 3: return 0

        l, r = 0, n-1
        maxL, maxR, res = 0, 0, 0
        
        while l<r:
            curL = height[l]
            curR = height[r]
            maxL = max(curL, maxL)
            maxR = max(curR, maxR)
            cur = 0
            if curL < curR:
                cur = curL
                l += 1
            else:
                cur = curR
                r -= 1
            ref = min(maxL, maxR)
            if ref > cur: res += ref - cur

        return res
        
    def trap(self, height: List[int]) -> int:
        return self.trap_2(height)
        
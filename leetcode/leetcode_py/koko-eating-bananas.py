'''
https://leetcode.com/problems/koko-eating-bananas

1. brute force
time: o(m^n)
space: o(1)

2. binary search
time: o(logn)
space: o(1)
'''
class Solution:
    def minEatingSpeed_1(self, piles: List[int], h: int) -> int:
        l = 1
        while True:
            hour = 0
            for pile in piles:
                hour += pile // l
                if pile % l != 0: hour += 1
                if hour > h: break
            if hour <= h: return l
            l += 1            
        return l

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, float(-inf)
        for n in piles: r = max(r, n)
        while l<=r:
            m = l + (r-l) // 2
            hour = 0
            for pile in piles:
                hour += pile // m
                if pile % m != 0: hour += 1
                if hour > h: break
            if hour <= h: r = m - 1
            else: l = m + 1
        return l

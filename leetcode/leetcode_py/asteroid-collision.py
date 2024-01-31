'''
https://leetcode.com/problems/asteroid-collision

1. list to store and compare
time: o(n)
space: o(n)
'''
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        res = []
        for v in asteroids:
            add = True
            while add and v < 0 and res and res[-1] > 0:
                add = res[-1] < abs(v)
                if res[-1] <= abs(v):
                    res.pop()
            if add:
                res.append(v)
        return res
        
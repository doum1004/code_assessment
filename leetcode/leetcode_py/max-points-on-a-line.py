'''
https://leetcode.com/problems/max-points-on-a-line

Solution1. Iteration and store by slope
time: o(n^2)
space: o(n)
slope(inclination, y2-y1/x2-x1) x2-x1 -> INT_MAX
https://leetcode.com/problems/max-points-on-a-line/solutions/3016360/easiest-c-solution-with-detailed-explanation/?envType=study-plan-v2&envId=top-interview-150
'''
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        res = 0
        n = len(points)
        for i in range(n):
            m = {}
            x1 = points[i][0]
            y1 = points[i][1]
            for j in range(i+1, n):
                x2 = points[j][0]
                y2 = points[j][1]
                dx = x2 - x1
                dy = y2 - y1
                
                slope = 0.0
                if dx == 0: slope = float(inf)
                else: slope = dy / dx
                
                if not slope in m:
                    m[slope] = 0
                m[slope] += 1
                res = max(res, m[slope])
                
        return res + 1
        
'''
https://leetcode.com/problems/daily-temperatures

Soltuion1. Brute force (no accepted)
time o(n^2)
space o(1)

Solution2. linear with stack (same for other top to bottom)
time: o(n)
space: o(n) stack
'''
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        s = []
        for i in range(len(temperatures)):
            while s and s[-1][0] < temperatures[i]:
                temperatures[s[-1][1]] = i - s[-1][1]
                s.pop()
            s.append((temperatures[i], i))
            temperatures[i] = 0
        return temperatures
        
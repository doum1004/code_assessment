'''
https://leetcode.com/problems/find-the-highest-altitude

1. Iterate and accumulate
time: o(n)
space: o(1)
'''
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        res = 0
        cur = 0
        for val in gain:
            cur += val
            res = max(cur, res)
        return res

        
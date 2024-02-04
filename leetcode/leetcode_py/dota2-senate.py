'''
https://leetcode.com/problems/dota2-senate

1. Queue
time: o(n)
space: o(n)
'''
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        r = []
        d = []
        n = len(senate)
        for i, c in enumerate(senate):
            if c == 'R': r.append(i)
            else: d.append(i)
        while r and d:
            if r[0] < d[0]: r.append(r[0] + n)
            else: d.append(d[0] + n)
            n += 1
            r.pop(0)
            d.pop(0)
        return "Radiant" if r else "Dire"

        
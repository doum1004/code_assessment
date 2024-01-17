'''
https://leetcode.com/problems/removing-stars-from-a-string

1. iterate and push, pop on string
time: o(n)
space: o(n)

2. two pointers (actual place, iterate place) and resize(l)
time: o(n)
space: o(1)
'''
class Solution:
    def removeStars_1(self, s: str) -> str:
        res = []
        for c in s:
            if c == '*':
                res.pop()
            else:
                res.append(c)
        return ''.join(res)
        
    def removeStars_2(self, s: str) -> str:
        s = list(s)
        l, r = 0, 0
        while r < len(s):
            if s[r] == '*':
                l -= 1
            else:
                s[l] = s[r]
                l += 1
            r += 1
        return ''.join(s[:l])
        
    def removeStars(self, s: str) -> str:
        return self.removeStars_1(s)
        
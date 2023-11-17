'''
https://leetcode.com/problems/summary-ranges
'''

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        m1 = {}
        m2 = {}
        for i in range(len(s)):
            c1 = s[i]
            c2 = t[i]
            if c1 in m1 and m1[c1] != c2:
                return False
            if c2 in m2 and m2[c2] != c1:
                return False
            m1[c1] = c2
            m2[c2] = c1
        print(m1)
        print(m2)
        return True
        
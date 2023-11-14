
"""
https://leetcode.com/problems/is-subsequence/

"""

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s == t: return True
        m = len(s)
        n = len(t)
        i = 0
        j = 0
        while i < m and j < n:
            if s[i] == t[j]:
                i += 1
            j += 1
        return i == m
        
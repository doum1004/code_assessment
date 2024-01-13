'''
https://leetcode.com/problems/is-subsequence

sol0. Recursive
time: o(n^2)
space: o(n)

Solution1. Two Pointer
time: o(n)
space: o(1)

Solution2. Follow up problem. Using Map 
time: o(n) m + n
space: o(m)
'''
class Solution:
    def isSubsequence_1(self, s: str, t: str) -> bool:
        l, r = 0, 0
        while l < len(s) and r < len(t):
            if s[l] == t[r]:
                l += 1
            r += 1
        return l == len(s)
        
    def isSubsequence_2(self, s: str, t: str) -> bool:
        m = defaultdict(list)
        for i in range(len(t)):
            m[t[i]].append(i)
        l = -1
        for c in s:
            if c not in m: return False
            idxList = m[c]
            x = bisect.bisect_right(idxList, l)
            if x == len(idxList):
                return False
            l = idxList[x]
        return True

    def isSubsequence(self, s: str, t: str) -> bool:
        return self.isSubsequence_2(s, t)
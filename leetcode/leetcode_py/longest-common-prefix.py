'''
https://leetcode.com/problems/longest-common-prefix

Solution1. Iterate. find window
time: o(n)
space: o(1)

'''
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0: return ""
        res = strs[0]
        r = len(res)
        for i in range(1, len(strs)):
            s = strs[i]
            r = min(r, len(s))
            j = 0
            while (j < len(s) and j < r):
                if res[j] != s[j]:
                    if j == 0: return ""
                    r = j
                    break
                j += 1
        return res[:r]
        
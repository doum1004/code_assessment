'''
https://leetcode.com/problems/minimum-window-substring

Solution. Hash map and sliding window
time: o(n)
space: o(n)
'''
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        m = defaultdict(int)
        for c in t: m[c] += 1
        l, cnt = 0, 0
        res_len, res_start = float(inf), 0
        for r in range(len(s)):
            if m[s[r]] > 0: cnt += 1
            m[s[r]] -= 1
            if cnt == len(t):
                while l < r and m[s[l]] < 0:
                    m[s[l]] += 1
                    l += 1
                if res_len > r - l + 1:
                    res_len = r - l + 1
                    res_start = l
                m[s[l]] += 1
                l += 1
                cnt -= 1
        return "" if res_len == float(inf) else s[res_start:res_start+res_len]
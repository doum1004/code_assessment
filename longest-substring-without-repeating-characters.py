class Solution:
    def lengthOfLongestSubstring_1(self, s: str) -> int:
        m = set()
        l, r = 0, 0
        res = 0
        while (r < len(s)):
            if s[r] in m:
                m.discard([s[l]])
                l += 1
            else:
                res = max(res, r - l + 1)
                m.add(s[r])
                r += 1
        return res
    
    def lengthOfLongestSubstring_2(self, s: str) -> int:
        m = {}
        l, r = 0, 0
        res = 0
        while r < len(s):
            if s[r] in m and m[s[r]] >= l:
                l = m[s[r]] + 1
            m[s[r]] = r
            res = max(res, r - l + 1)
            r += 1
        return res
    
    def lengthOfLongestSubstring_3(self, s: str) -> int:
        m = [-1] * 128
        l, r = 0, 0
        res = 0
        while r<len(s):
            c = int(s[r])
            if m[c] >= l:
                l = m[c] + 1
            m[c] = r
            res = max(res, r - l + 1)
            r += 1
        return res

    def lengthOfLongestSubstring(self, s: str) -> int:
        return self.lengthOfLongestSubstring_3(s)
        
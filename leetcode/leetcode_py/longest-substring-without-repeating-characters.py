'''
https://leetcode.com/problems/longest-substring-without-repeating-characters

Solutlins1. sliding window with hash map (set)
time: o(n)
space: o(n)

Solutlins2. sliding window with hash map(char, int). find next left window from map. Sol1 improvement
time: o(n) 
space: o(n)

Solutions3. sliding window with array (128 char)
time: o(n)
space: o(n) improved from sol2 (map -> array)


solution1. two pointers.
time: o(n)
space: o(min(m,26)) m (num of none duplicated chars)

1. iterate with two pointers (i=0, j=0) till j < n
2. if not s[j] in m:
    m[s[j]] = j
    l = max(l, j-i+1)
    j++
3. else:
    i = m[s[j]] + 1
    m[s[j]] = j
    if i == j:
        j++

'''
class Solution:    
    def lengthOfLongestSubstring_twopointers_slower(self, s: str) -> int:
        n = len(s)
        if n < 2:
            return n
        
        m = {}
        l = 0
        r = 0
        res = 0
        while r < n:
            if s[r] in m:
                l = max(l, m[s[r]] + 1)
            res = max(res, r-l+1)
            m[s[r]] = r
            r += 1
                    
        return res
    
    def lengthOfLongestSubstring_twopointers_faster(self, s: str) -> int:
        n = len(s)
        if n < 2:
            return n
        
        m = {}
        res = 0
        l = 0
        
        for r,c in enumerate(s):
            if not c in m or m[c] < l:
                res = max(res, r-l+1)
            else:
                l = m[c] + 1
            m[c] = r
        return res
    
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
        
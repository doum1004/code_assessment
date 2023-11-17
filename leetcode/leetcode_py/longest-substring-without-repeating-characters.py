"""
https://leetcode.com/problems/longest-substring-without-repeating-characters/

1) abcabcbb
3

2) bbbbb
1

3) pwwkew
3

solution. brute force
o(n^2)

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

"""

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
                
    def lengthOfLongestSubstring(self, s: str) -> int:
        #return self.lengthOfLongestSubstring_twopointers_slower(s)
        return self.lengthOfLongestSubstring_twopointers_faster(s)
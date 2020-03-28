from typing import List

"""
https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
"""

class Solution:
    def lengthOfLongestSubstringTwoDistinct_slidingwindow(self, s: str) -> int:
        h = collections.defaultdict(int)
        l,r,res,n = 0,0,0,len(s)
        while r<n:
            h[s[r]] += 1
            while len(h) > 2:
                h[s[l]] -= 1
                if h[s[l]] == 0:
                    del h[s[l]]
                l += 1
                
            res = max(res, r-l+1)
            r += 1
        
        return res
    
    def lengthOfLongestSubstringTwoDistinct_nospace(self, s: str) -> int:
        l,c,res = 0,0,0
        for r,v in enumerate(s):
            if s[r] != s[c]:
                if c != 0 and s[c-1] != s[r]:
                    l = c
                c = r
            res = max(res, r-l+1)
        return res
    
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        #return self.lengthOfLongestSubstringTwoDistinct_slidingwindow(s)
        return self.lengthOfLongestSubstringTwoDistinct_nospace(s)
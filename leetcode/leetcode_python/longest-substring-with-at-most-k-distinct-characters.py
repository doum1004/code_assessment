from typing import List
import collections

"""
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
"""

class Solution:
    def lengthOfLongestSubstringKDistinct_slidingwindow(self, s: str, k: int) -> int:
        n, l, res = len(s), 0, 0
        counter = collections.defaultdict(int)
        for r in range(n):
            counter[s[r]] += 1
            
            while len(counter) > k:
                counter[s[l]] -= 1
                if counter[s[l]] == 0:
                    del counter[s[l]]
                l += 1
                
            res = max(res, r-l+1)
        return res
            
        
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        return self.lengthOfLongestSubstringKDistinct_slidingwindow(s,k)
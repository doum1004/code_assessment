import collections

"""
https://leetcode.com/problems/valid-anagram/
"""

class Solution:
    def isAnagram_sort(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
        
    def isAnagram_set(self, s: str, t: str) -> bool:
        h = collections.defaultdict(int)
        for c in s: h[c] += 1
        for c in t: h[c] -= 1
        for k in h:
            if h[k] != 0: return False
        return True
        
    def isAnagram_builtin(self, s: str, t: str) -> bool:
        return collections.Counter(s) == collections.Counter(t)
    
    def isAnagram(self, s: str, t: str) -> bool:
        #return self.isAnagram_sort(s,t)
        #return self.isAnagram_set(s,t)
        return self.isAnagram_builtin(s,t)
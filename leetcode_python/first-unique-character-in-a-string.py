# https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution:
    def firstUniqChar(self, s: str) -> int:
        # count = {}
        # for c in s:
        #     if c in count:
        #         count[c] += 1
        #     else:
        #         count[c] = 1
        count = collections.Counter(s)
                
        # for i in range(len(s)):
        #     if count[s[i]] == 1:
        #         return i
        for i, c in enumerate(s):
          if count[c] == 1:
            return i
        
        return -1
        
        
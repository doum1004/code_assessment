'''
https://leetcode.com/problems/ransom-note
'''

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        m = {}
        for c in magazine:
            if c in m:
                m[c] += 1
            else:
                m[c] = 1

        for c in ransomNote:
            if not c in m or m[c] == 0:
                return False
            m[c] -= 1

        return True

        
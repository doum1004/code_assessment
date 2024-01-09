'''
https://leetcode.com/problems/merge-strings-alternately

Soltuion1. Two Pointer
time: o(n)
space: o(1)

Solution2. Single Pointer
time: o(n)
space: o(1)
'''
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res = ''
        for i in range(max(len(word1), len(word2))):
            if i < len(word1):
                res += word1[i]
            if i < len(word2):
                res += word2[i]
        return res
                
        
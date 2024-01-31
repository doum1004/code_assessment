'''
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

1. Sliding Window
time: o(n)
space: o(1)
'''
class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        n = len(s)
        res, cnt = 0, 0
        for i in range(n):
            if i >= k and s[i-k] in vowels:
                cnt -= 1
            if s[i] in vowels:
                cnt += 1
            res = max(res, cnt)
        return res

        
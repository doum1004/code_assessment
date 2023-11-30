'''
https://leetcode.com/problems/longest-palindromic-substring/

Solution1. Iterate and expand from cetner
time: o(n^2)
space: o(1)

Solution2. DP (https://leetcode.com/problems/longest-palindromic-substring/solutions/147548/direct-c-dp/?envType=study-plan-v2&envId=top-interview-150)
time: o(n^2)
space: o(n^2)
'''
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 2: return s
        maxRange = 1
        start = 0
        for i in range(n):
            l = i
            while i < n-1 and s[l] == s[i+1]: i += 1
            r = i
            while l >= 0 and r < n and s[l] == s[r]:
                length = r - l + 1
                if maxRange < length:
                    print(l, r, length)
                    maxRange = length
                    start = l
                l -= 1
                r += 1
            if r == n - 1: break
        return s[start:start+maxRange]
                
            

        

            
        
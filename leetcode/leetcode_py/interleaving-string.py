'''
https://leetcode.com/problems/interleaving-string

solution1. dp memorization
time: o(m+n) before 2^(m+2)
space: o(m+n)

solution2. dp tabulation (TODO)

'''
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)
        n3 = len(s3)
        if n1 + n2 != n3: return False

        dp = [[-1] * (n2+1) for _ in range(n1 + 1)]
        def recursion(i, j):
            if i == n1 and j == n2: return 1
            if dp[i][j] != -1:
                return dp[i][j]
            
            ans = 0
            if not ans and i < n1 and s1[i] == s3[i+j]:
                ans = recursion(i+1, j)
            if not ans and j < n2 and s2[j] == s3[i+j]:
                ans = recursion(i, j+1)
            dp[i][j] = ans
            return ans
        result = recursion(0,0)
        return result
        
'''
https://leetcode.com/problems/longest-common-subsequence

1. Recursion greedy with memorization
time: o(mn)
space: o(mn)

2. Iteration with tabulation (bottom-up)
time : o(mn)
space: o(mn)
'''
class Solution:
    def longestCommonSubsequence_1(self, text1: str, text2: str) -> int:
        dp = [[-1 for _ in range(len(text2))] for _ in range(len(text1))]
        def recursion(i, j):
            if i == len(text1) or j == len(text2):
                return 0
            if dp[i][j] != -1:
                return dp[i][j]
            res = 0
            if text1[i] == text2[j]:
                res = 1 + recursion(i+1, j+1)
            else:
                res = max(recursion(i+1, j), recursion(i, j+1))
            dp[i][j] = res
            return res
        recursion(0, 0)
        return dp[0][0]

    def longestCommonSubsequence_2(self, text1: str, text2: str) -> int:
        dp = [[0 for _ in range(len(text2)+1)] for _ in range(len(text1)+1)]
        for i in range(len(text1)-1, -1, -1):
            for j in range(len(text2)-1, -1, -1):
                dp[i][j] = 1 + dp[i+1][j+1] if text1[i] == text2[j] else max(dp[i+1][j], dp[i][j+1])
        return dp[0][0]

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        return self.longestCommonSubsequence_2(text1, text2)
        
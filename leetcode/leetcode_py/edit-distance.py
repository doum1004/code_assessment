'''
https://leetcode.com/problems/edit-distance

Solution1. dp for edit distance (2 dimensions)
time: o(mn)
space: o(mn)

Solution2. dp with 1 dimension
time: o(mn)
space: o(n)

'''
class Solution:
    def minDistance_1(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)
        dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
        for i in range(n+1):
            dp[i][0] = i
        for i in range(m+1):
            dp[0][i] = i

        for i in range(1, n+1):
            for j in range(1, m+1):
                if word2[i-1] == word1[j-1]: dp[i][j] = dp[i-1][j-1]
                else: dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1

        return dp[-1][-1]
        
    def minDistance_2(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)
        dp = [0] * (n+1)
        for i in range(1, n+1):
            dp[i] = i
            
        pre = 0
        for i in range(1, m+1):
            pre = dp[0]
            dp[0] = i
            for j in range(1, n+1):
                temp = dp[j]
                if word1[i-1] == word2[j-1]: dp[j] = pre
                else: dp[j] = min(min(pre, dp[j]), dp[j-1]) + 1
                pre = temp
        return dp[-1]

    def minDistance(self, word1: str, word2: str) -> int:
        return self.minDistance_2(word1, word2)
        
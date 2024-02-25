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
        dp = [[0 for _ in range(len(word1)+1)] for _ in range(len(word2)+1)]
        for i in range(len(word2) + 1):
            dp[i][0] = i
            
        for j in range(len(word1) + 1):
            dp[0][j] = j

        for i in range(1, len(word2) + 1):
            for j in range(1, len(word1) + 1):
                if word2[i-1] == word1[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
        return dp[-1][-1]
        
    def minDistance_2(self, word1: str, word2: str) -> int:
        dp = [0] * (len(word1) + 1)
        for i in range(len(word1) + 1):
            dp[i] = i
            
        for i in range(1, len(word2) + 1):
            pre = dp[0]
            dp[0] = i
            for j in range(1, len(word1) + 1):
                temp = dp[j]
                if word2[i-1] == word1[j-1]:
                    dp[j] = pre
                else:
                    dp[j] = min(dp[j-1], dp[j], pre) + 1
                pre = temp
        return dp[-1]        

    def minDistance(self, word1: str, word2: str) -> int:
        return self.minDistance_2(word1, word2)
        
'''
https://leetcode.com/problems/maximal-square

Solution1. recursion + memorization
time: o(nm)
space: o(nm)

Solution2. iteration + tabulation (2d)
time: o(nm)
space: o(nm)

Solution3. iteration + tabulation (1d)
time: o(nm)
space: o(2n)
'''
class Solution:
    def maximalSquare_1(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        dp = [[-1 for _ in range(n)] for _ in range(m)]

        def recursion(i, j):
            if i == m or j == n: return 0
            if matrix[i][j] == '0': return 0
            if dp[i][j] != -1: return dp[i][j]
            n1 = recursion(i+1, j)
            n2 = recursion(i+1, j+1)
            n3 = recursion(i, j+1)
            dp[i][j] = min(n1, n2, n3) + 1
            return dp[i][j]

        res = 0
        for i in range(m):
            for j in range(n):
                res = max(res, recursion(i, j))
        return res * res

    def maximalSquare_2(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        
        res = 0
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if i == m-1 or j == n-1 or matrix[i][j] == '0': dp[i][j] = int(matrix[i][j])
                else: dp[i][j] = min(min(dp[i+1][j], dp[i][j+1]), dp[i+1][j+1]) + 1
                res = max(res, dp[i][j])

        return res * res

    def maximalSquare_3(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])

        cur = [0] * n
        pre = [0] * n
        
        res = 0
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if i == m-1 or j == n-1 or matrix[i][j] == '0': cur[j] = int(matrix[i][j])
                else: cur[j] = min(min(pre[j], pre[j+1]), cur[j+1]) + 1
                res = max(res, cur[j])
            pre = [0] * n
            cur, pre = pre, cur

        return res * res

    def maximalSquare(self, matrix: List[List[str]]) -> int:
        return self.maximalSquare_3(matrix)
        
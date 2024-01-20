'''
https://leetcode.com/problems/unique-paths

1. DFS with memorization
time: o(n)
space: o(n) n(dp) + n(recursion)

2. BFS with tabulation
time: o(n)
space: o(n) dp

3. BFS with tabulation (one or two vector)
time: o(n)
space: o(2n or n)
'''
class Solution:
    def uniquePaths_1(self, m: int, n: int) -> int:
        dp = [[-1 for _ in range(n)] for _ in range(m)]
        dp[m-1][n-1] = 1
        print(dp)
        
        def dfs(r, c):
            if r == m or c == n:
                return 0
            if dp[r][c] != -1:
                return dp[r][c]
            dp[r][c] = dfs(r+1, c) + dfs(r, c+1)
            return dp[r][c]
        dfs(0, 0)
        return dp[0][0]
        
    def uniquePaths_2(self, m: int, n: int) -> int:
        dp = [[1 for _ in range(n)] for _ in range(m)]
        for r in range(m-2, -1, -1):
            for c in range(n-2, -1, -1):
                dp[r][c] = dp[r+1][c] + dp[r][c+1]
        return dp[0][0]

    def uniquePaths_3(self, m: int, n: int) -> int:
        pre, cur = [1] * n, [1] * n
        for r in range(m-2, -1, -1):
            for c in range(n-2, -1, -1):
                cur[c] = cur[c+1] + pre[c]
            pre, cur = cur, pre
        return pre[0]

    def uniquePaths(self, m: int, n: int) -> int:
        return self.uniquePaths_3(m, n)
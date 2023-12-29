'''
https://leetcode.com/problems/n-queens-ii

Solution: Backtracking (DFS)
https://leetcode.com/problems/n-queens-ii/solutions/2111695/c-n-queens-variation/?envType=study-plan-v2&envId=top-interview-150
time: o(n!)
spalce: o(n^2)

Solution2. TODO
time: o(n!)
space: o(n)
'''
class Solution:
    def totalNQueens(self, n: int) -> int:
        b = [[0 for _ in range(n)] for _ in range(n)]
        def isSafe(r, c):
            for i in range(r+1):
                if b[i][c]: return False
                if r - i >= 0 and c - i >= 0 and b[r-i][c-i]: return False
                if r - i >= 0 and c + i < n and b[r-i][c+i]: return False
            return True
                
        def solve(r):
            if r >= n: return 1
            cnt = 0
            for c in range(n):
                if isSafe(r, c):
                    b[r][c] = 1
                    cnt += solve(r+1)
                    b[r][c] = 0
            return cnt

        return solve(0)
        

        
'''
https://leetcode.com/problems/minimum-path-sum

1. DP Recursion Memorization
time: o(mn)
space: o(mn)

2. DP topdown with in space
time: o(mn)
space: o(1)
'''
class Solution:
    def minPathSum_1(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        hm = {}
        def recursive(r, c):
            if r >= m or c >= n:
                return -1
            if (0,0) in hm: return hm[(0,0)]
            print(r,c)
            v = grid[r][c]
            v1 = recursive(r+1, c)
            v2 = recursive(r, c+1)
            if v1 != -1 and v2 != -1:
                v += min(v1,v2)
            elif v1 != -1 and v2 == -1:
                v += v1
            elif v1 == -1 and v2 != -1:
                v += v2
            hm[(r,c)] = v
            return v
        recursive(0,0)
        return hm[(0,0)]
        
        
    def minPathSum_2(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if i != m-1 and j != n-1: grid[i][j] += min(grid[i+1][j], grid[i][j+1])
                if i == m-1 and j != n-1: grid[i][j] += grid[i][j+1]
                if i != m-1 and j == n-1: grid[i][j] += grid[i+1][j]
        return grid[0][0]

    def minPathSum(self, grid: List[List[int]]) -> int:
        return self.minPathSum_2(grid)

                
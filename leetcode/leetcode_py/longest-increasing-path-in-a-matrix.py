from typing import List

"""
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
"""

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if len(matrix) < 1 or len(matrix[0]) < 1: return 0
        n,m = len(matrix),len(matrix[0])
        
        cache = [[0 for i in range(m)] for i in range(n)]
        def dfs(row,col):
            if (cache[row][col] > 0): return cache[row][col]
            
            for n_r,n_c in [(row+1,col), (row,col+1), (row-1,col), (row,col-1)]:
                if n_r < 0 or n_c < 0 or n_r >= n or n_c >= m or matrix[row][col] >= matrix[n_r][n_c]: continue
                    
                cache[row][col] = max(cache[row][col], dfs(n_r,n_c))
                    
            cache[row][col] += 1
            return cache[row][col]
        
        return max(dfs(r,c) for c in range(m) for r in range(n))
            
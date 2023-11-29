'''
https://leetcode.com/problems/unique-paths-ii

solution1. recursion with memorization
time: o(n)
space: o(n)

solution1. iteration with dp
time: o(n)
space: o(n)
'''
class Solution:
    def uniquePathsWithObstacles_1(self, obstacleGrid: List[List[int]]) -> int:
        n1 = len(obstacleGrid)
        n2 = len(obstacleGrid[0])
        def recursive(r, c):
            if r < 0 or c < 0 or r >= n1 or c >= n2:
                return 0
            if obstacleGrid[r][c] > -1:
                return obstacleGrid[r][c]
            if r == n1 - 1 and c == n2 - 1: return 1
            
            node1 = recursive(r + 1, c)
            node2 = recursive(r, c + 1)
            obstacleGrid[r][c] = node1 + node2
            return node1 + node2
        for i in range(n1):
            for j in range(n2):
                obstacleGrid[i][j] = -1 if obstacleGrid[i][j] == 0 else 0
        return recursive(0, 0)
        
    def uniquePathsWithObstacles_2(self, obstacleGrid: List[List[int]]) -> int:
        n1 = len(obstacleGrid)
        n2 = len(obstacleGrid[0])
        for i in range(n1):
            for j in range(n2):
                if obstacleGrid[i][j] == 1:
                    obstacleGrid[i][j] = 0
                elif i == 0 or j == 0:
                    if i == 0 and j == 0:
                        obstacleGrid[i][j] = 1
                    elif i == 0:
                        obstacleGrid[i][j] = obstacleGrid[i][j-1]
                    elif j == 0:
                        obstacleGrid[i][j] = obstacleGrid[i-1][j]
                else: obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
        return obstacleGrid[n1 - 1][n2 - 1]
        
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        return self.uniquePathsWithObstacles_2(obstacleGrid)
        
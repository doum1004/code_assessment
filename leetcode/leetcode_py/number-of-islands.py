'''
https://leetcode.com/problems/number-of-islands

Solution1. DSF inorder. Mark visited in place
time: o(n)
space: o(1)

Solution2. BSF. Mark visited in place
time: o(n)
space: o(1)
'''
class Solution:
    def numIslands_1(self, grid: List[List[str]]) -> int:
        n1 = len(grid)
        if n1 == 0: return 0
        n2 = len(grid[0])
        if n2 == 0: return 0

        def dfs(row, col):
            if row < 0 or col < 0 or row >= n1 or col >= n2 or grid[row][col] == '0':
                return
            grid[row][col] = '0'
            dfs(row-1,col)
            dfs(row+1,col)
            dfs(row,col-1)
            dfs(row,col+1)
            
        cnt = 0
        for i in range(n1):
            for j in range(n2):
                if grid[i][j] == '0':
                    continue
                cnt += 1
                dfs(i, j)
        return cnt

    def numIslands_2(self, grid: List[List[str]]) -> int:
        n1 = len(grid)
        if n1 == 0: return 0
        n2 = len(grid[0])
        if n2 == 0: return 0

        cnt = 0
        for i in range(n1):
            for j in range(n2):
                if grid[i][j] == '0':
                    continue
                cnt += 1
                q = [[i,j]]
                while q:
                    values = q.pop(0)
                    row = values[0]
                    col = values[1]
                    if row < 0 or col < 0 or row >= n1 or col >= n2 or grid[row][col] == '0':
                        continue
                    grid[row][col] = '0'
                    q.append([row-1,col])
                    q.append([row+1,col])
                    q.append([row,col-1])
                    q.append([row,col+1])
                
        return cnt

    def numIslands(self, grid: List[List[str]]) -> int:
        return self.numIslands_2(grid)
        
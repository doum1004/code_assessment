'''
https://leetcode.com/problems/rotting-oranges

1. BFS
time: o(n)
space: o(n)
- Add all rotten orange in queue
- Visit adj nodes and mark it. After loop of queue size, add day += 1
- Check again Fresh orange exist
'''
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = []
        hasFresh = False
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    q.append((i,j))
                elif grid[i][j] == 1:
                    hasFresh = True
        if not hasFresh: return 0
        if not q: return -1

        res = 0
        while q:
            qSize = len(q)
            for k in range(qSize):
                i, j = q[0][0], q[0][1]
                q.pop(0)
                if i + 1 < len(grid) and grid[i+1][j] == 1:
                    grid[i+1][j] = 2
                    q.append((i+1, j))
                if j + 1 < len(grid[0]) and grid[i][j+1] == 1:
                    grid[i][j+1] = 2
                    q.append((i, j+1))
                if i > 0 and grid[i-1][j] == 1:
                    grid[i-1][j] = 2
                    q.append((i-1, j))
                if j > 0 and grid[i][j-1] == 1:
                    grid[i][j-1] = 2
                    q.append((i, j-1))
            if q:
                res += 1

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1: return -1

        return res
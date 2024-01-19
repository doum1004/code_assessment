'''
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

1. BFS
time: o(n)
space: o(n)
'''
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        n1 = len(maze)
        n2 = len(maze[0])
        q = [(0, entrance[0], entrance[1])]
        while q:
            step, r, c = q[0]
            q.pop(0)
            if maze[r][c] != '.':
                continue
            if step != 0 and (r == 0 or c == 0 or r == n1 - 1 or c == n2 - 1):
                return step
            maze[r][c] = '+'
            if r + 1 < n1:
                q.append((step+1, r + 1, c))
            if r - 1 >= 0:
                q.append((step+1, r - 1, c))
            if c + 1 < n2:
                q.append((step+1, r, c + 1))
            if c - 1 >= 0:
                q.append((step+1, r, c - 1))
        return -1

        
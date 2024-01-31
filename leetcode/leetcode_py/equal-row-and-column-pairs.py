'''
https://leetcode.com/problems/equal-row-and-column-pairs

1. string lists (row, col) and map (col)
time: o(n^2) n^2 + n + n
space: o(n) 2n + n

2. map with vector
time: o(n^2) n + n(n*logn)
space: o(n) n
'''
class Solution:
    def equalPairs_1(self, grid: List[List[int]]) -> int:
        n = len(grid)
        l1 = [""] * n
        l2 = [""] * n
        for r in range(n):
            for c in range(n):
                s = str(grid[r][c]) + " "
                l1[r] += s
                l2[c] += s
        m = defaultdict(int)
        for v in l1:
            m[v] += 1
        res = 0
        for v in l2:
            res += m[v]
        return res

    def equalPairs_2(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = defaultdict(int)
        for r in range(n):
            m[str(grid[r])] += 1
        
        res = 0
        for c in range(n):
            col = []
            for r in range(n):
                col.append(grid[r][c])
            res += m[str(col)]
        return res        

    def equalPairs(self, grid: List[List[int]]) -> int:
        return self.equalPairs_2(grid)
        
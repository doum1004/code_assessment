'''
https://leetcode.com/problems/number-of-provinces

1. DFS
time: o(n)
space: o(n)

2. UnionFind
https://www.youtube.com/watch?v=ayW5B2W9hfo
time: o(logn)
space: o(b)
'''
class Solution:
    def findCircleNum_1(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        seen = set()
        def dfs(i):
            if i in seen:
                return False
            seen.add(i)
            for j in range(len(isConnected[i])):
                if isConnected[i][j] == 1:
                    dfs(j)
            return True
        res = 0
        for i in range(n):
            if dfs(i):
                res += 1
        return res

    def findCircleNum_2(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        g = []
        for i in range(n):
            g.append(i)

        def find(i):
            if g[i] == i: return i
            g[i] = find(g[i])
            return g[i]
                    
        def join(i, j):
            i = find(i)
            j = find(j)
            if i != j:
                g[j] = i

        for i in range(n):
            for j in range(n):
                if isConnected[i][j]:
                    join(i, j)

        res = 0
        for i in range(n):
            if g[i] == i:
                res += 1
        return res


    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        return self.findCircleNum_2(isConnected)
        
        
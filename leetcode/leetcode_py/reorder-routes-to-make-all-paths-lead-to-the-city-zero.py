'''
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

1. DFS (add count it passes exist connection)
- Make bi-dirational (correct: +, added: -)
- DFS visit node to count all positive adj node. Skip visited node not to visit again
time: o(n)
space: o(n)
'''
class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        g = defaultdict(list)
        for c in connections:
            g[c[0]].append((c[1], 1))
            g[c[1]].append((c[0], 0))
        
        v = [0] * n
        def dfs(i):
            v[i] = 1
            cnt = 0
            for adj in g[i]:
                if v[adj[0]]: continue
                cnt += adj[1] + dfs(adj[0])
            return cnt
        return dfs(0)
            
        
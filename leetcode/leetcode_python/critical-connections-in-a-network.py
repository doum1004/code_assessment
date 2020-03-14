from typing import List

"""
https://leetcode.com/problems/critical-connections-in-a-network/
"""

class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        res = []
        g = [[] for i in range(n)] #collections.defaultdict(list)
        dist = [0 for i in range(n)]
        low = [0] * n
        self.time = 0
        
        def dfs(cur, parent):
            if dist[cur] > 0:
                return
            self.time += 1
            dist[cur] = low[cur] = self.time
            for adj in g[cur]:
                if adj == parent:
                    continue
                    
                dfs(adj, cur)
                low[cur] = min(low[cur], low[adj])
                if dist[cur] < low[adj]:
                    res.append([cur, adj])
            
        for node in connections:
            g[node[0]].append(node[1])
            g[node[1]].append(node[0])
        dfs(0, -1)
        
        return res
        
        
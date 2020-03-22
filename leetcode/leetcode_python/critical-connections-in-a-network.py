from typing import List

"""
https://leetcode.com/problems/critical-connections-in-a-network/
"""

class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        # build graph
        g = collections.defaultdict(list)
        for c in connections:
            g[c[0]].append(c[1])
            g[c[1]].append(c[0])
            
        res = []
        disconvery = [0 for i in range (n)]
        low = [0 for i in range (n)]
        self.time = 0
        def dsf(cur, parent):
            if disconvery[cur] > 0:
                return
            self.time += 1
            disconvery[cur] = low[cur] = self.time
            for adj in g[cur]:
                if parent == adj:
                    continue
                dsf(adj, cur)
                low[cur] = min(low[cur], low[adj])
                if disconvery[cur] < low[adj]:
                    res.append([cur, adj])
            
        dsf(0, -1)
        
        return res
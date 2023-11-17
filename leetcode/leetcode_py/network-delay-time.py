from typing import List
import collections
import heapq

"""
https://leetcode.com/problems/network-delay-time/
"""

class Solution:
    def networkDelayTime_dijkstra(self, times: List[List[int]], N: int, K: int) -> int:
        #build graph
        g = collections.defaultdict(list)
        for u,v,w in times:
            g[u].append([w, v])
        
        #update table
        #t = [float('inf') for i in range(N+1)]
        t, heap = {}, [[0,K]]
        while heap:
            time,node = heapq.heappop(heap)
            if node in t and t[node] <= time:
                continue
            t[node] = time
            
            for adj in g[node]:
                heapq.heappush(heap, [time+adj[0], adj[1]])
        
        return max(t.values()) if len(t) == N else -1 
        
    def networkDelayTime_bellmanford(self, times: List[List[int]], N: int, K: int) -> int:
        t = {K: 0}
        for i in range(N-1):
            changed = False
            for u,v,w in times:
                if u in t and (v not in t or t[v] > t[u] + w):
                    t[v] = t[u] + w
                    changed = True
            if not changed:
                break
                
        return max(t.values()) if len(t) == N else -1
        
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        #return self.networkDelayTime_dijkstra(times, N, K)
        return self.networkDelayTime_bellmanford(times, N, K)
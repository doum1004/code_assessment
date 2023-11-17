
from typing import List
import collections

"""
https://leetcode.com/problems/evaluate-division/
"""

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        g = collections.defaultdict(dict)
        for i in range(len(equations)):
            e = equations[i]
            v = values[i]
            g[e[0]][e[1]] = v
            g[e[1]][e[0]] = 1/v
            
        def DFS(visited, cur,tar,factor):
            if cur == tar: return factor
            if cur in visited: return -1
            visited[cur] = 1
            for key in g[cur]:
                result = DFS(visited, key, tar, factor*g[cur][key])
                if result > -1: return result
            return -1
        
        res = []
        for q in queries:
            n = -1.0
            if q[0] in g and q[1] in g:
                if q[0] in g and q[1] in g[q[0]]:
                    n = g[q[0]][q[1]]
                else:
                    visited = collections.defaultdict(int)
                    n = DFS(visited, q[0], q[1], 1)
            res.append(n)
            
        return res
        
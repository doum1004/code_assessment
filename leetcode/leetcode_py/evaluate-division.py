
from typing import List
import collections

"""
https://leetcode.com/problems/evaluate-division/
Solution1. build graph
time: o(e*q) equation * query graph
space: o(q) query graph
"""

class Solution:
    def calcEquation_1(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
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
        
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(list)
        def dfs(start, end, product, visited):
            if start in visited: return -1
            if not start in graph or not end in graph: return -1
            if start == end: return product
            
            visited.add(start)
            for node in graph[start]:
                ans = dfs(node[0], end, product*node[1], visited)
                if ans != -1:
                    return ans
            visited.remove(start)
            return -1
        
        for i, e in enumerate(equations):
            e1 = e[0]
            e2 = e[1]
            v = values[i]
            graph[e1].append([e2, v])
            graph[e2].append([e1, 1.0/v])

        res = []
        for query in queries:
            visited = set()
            res.append(dfs(query[0], query[1], 1, visited))

        return res
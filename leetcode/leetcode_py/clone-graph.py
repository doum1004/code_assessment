"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

'''
https://leetcode.com/problems/clone-graph

Solution1. DFS
time: o(n)
space: o(n)

Solution2. BFS
time: o(n)
space: o(n)
'''
from typing import Optional
class Solution:
    def cloneGraph_1(self, node: Optional['Node']) -> Optional['Node']:
        hm = {}
        def dfs(n):
            if not n: return None
            if n in hm: return hm[n]
            cloned = Node(n.val)
            hm[n] = cloned
            for neighbor in n.neighbors:
                cloned.neighbors.append(dfs(neighbor))
            return cloned

        return dfs(node)
    def cloneGraph_2(self, node: Optional['Node']) -> Optional['Node']:
        if not node: return None

        q = []
        q.append([None, node])

        hm = {}
        while q:
            qSize = len(q)
            for i in range(qSize):
                parent, child = q.pop(0)
                if child in hm:
                    parent.neighbors.append(hm[child])
                else:
                    clonedChild = Node(child.val)
                    hm[child] = clonedChild
                    if parent:
                        parent.neighbors.append(clonedChild)

                    for neighbor in child.neighbors:
                        q.append([clonedChild, neighbor])
        return hm[node]

        
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        return self.cloneGraph_2(node)

        
        
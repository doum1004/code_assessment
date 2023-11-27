"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

'''
https://leetcode.com/problems/construct-quad-tree

Solution1. Divide and Conquer (recursion)
time: o(n^2logn)
space: o(logn)
'''

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def isAllSame(x, y, n):
            val = grid[x][y]
            for i in range(x, x+n):
                for j in range(y, y+n):
                    if val != grid[i][j]:
                        return False
            return True
        def build(x, y, n):
            if isAllSame(x, y, n):
                return Node(grid[x][y], True)
            n //= 2
            node = Node(True, False)
            node.topLeft = build(x, y, n)
            node.topRight = build(x, y+n, n)
            node.bottomLeft = build(x+n, y, n)
            node.bottomRight = build(x+n, y+n, n)
            return node
        return build(0, 0, len(grid))

        
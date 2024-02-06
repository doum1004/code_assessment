# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

1. DFS (passing level)
time: o(n)
space: o(n)

2. BFS
time: o(n)
space: o(n)
'''
class Solution:
    def maxLevelSum_1(self, root: Optional[TreeNode]) -> int:
        m = []
        def dfs(node, level):
            if not node:
                return
            if len(m) < level: m.append(0)
            m[level-1] += node.val
            dfs(node.left, level + 1)
            dfs(node.right, level + 1)
        dfs(root, 1)
        res = 0
        res_val = float(-inf)
        for i, val in enumerate(m):
            if res_val < val:
                res = i+1
                res_val = val
        return res

    def maxLevelSum_2(self, root: Optional[TreeNode]) -> int:
        q = [(root, 1)]
        res = 0
        res_val = float(-inf)
        while q:
            qSize = len(q)
            level = 0
            val = 0
            for i in range(qSize):
                node, level = q[0][0], q[0][1]
                q.pop(0)
                val += node.val
                if node.left: q.append((node.left, level+1))
                if node.right: q.append((node.right, level+1))
            if res_val < val:
                res_val = val
                res = level
        return res
        
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        return self.maxLevelSum_2(root)

        
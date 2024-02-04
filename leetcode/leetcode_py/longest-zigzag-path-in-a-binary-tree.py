# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

1. DFS (passing left, right count)
time: o(n)
space: o(n)
'''
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        def dfs(node, l, r):
            if not node: return 0
            return max(l, r, dfs(node.left, r+1, 0), dfs(node.right, 0, l+1))
        
        return dfs(root, 0, 0)
        
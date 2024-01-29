# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
https://leetcode.com/problems/count-good-nodes-in-binary-tree
 
1. DFS preorder
time: o(n)
space: o(n)
'''
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        def dfs(node, val):
            if not node:
                return 0
            cnt = 0
            if node.val >= val:
                cnt = 1
                val = node.val
            cnt += dfs(node.left, val)
            cnt += dfs(node.right, val)
            return cnt
        return dfs(root, root.val)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
 https://leetcode.com/problems/leaf-similar-trees
 
 1. DFS and store leaf node in vector. And compare later
 time: o(n)
 space: o(n)
 '''
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:

        def dfs(node, store):
            if not node:
                return
            if not node.left and not node.right:
                store.append(node.val)
            dfs(node.left, store)
            dfs(node.right, store)
        store1, store2 = [], []
        dfs(root1, store1)
        dfs(root2, store2)
        return store1 == store2
        
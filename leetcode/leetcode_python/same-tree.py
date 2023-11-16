'''
https://leetcode.com/problems/same-tree
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def dfs(node1, node2) -> bool:
            if not node1 or not node2:
                return node1 == node2
            if node1.val != node2.val:
                return False
            l = dfs(node1.left, node2.left)
            r = dfs(node1.right, node2.right)
            return l and r

        return dfs(p, q)
        
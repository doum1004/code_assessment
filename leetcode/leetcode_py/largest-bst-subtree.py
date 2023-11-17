"""
https://leetcode.com/problems/largest-bst-subtree/submissions/
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def largestBSTSubtree_BSF(self, root: TreeNode) -> int:
        def countBSTSubTree(node):
            if not node:
                return [float('inf'), float('-inf'), 0]
            l = countBSTSubTree(node.left)
            r = countBSTSubTree(node.right)
            v = node.val
            if l[1] < v and r[0] > v:
                return [min(v,l[0]), max(v,r[1]), l[2]+r[2]+1]
            return [float('-inf'), float('inf'), max(l[2],r[2])]
            
        return countBSTSubTree(root)[2]
        
    def largestBSTSubtree(self, root: TreeNode) -> int:
        return self.largestBSTSubtree_BSF(root)
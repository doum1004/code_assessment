"""
https://leetcode.com/problems/count-univalue-subtrees/
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def countUnivalSubtrees_dsf_recursion(self, root: TreeNode) -> int:
        self.res = 0
        def dsf(node):
            if not node:
                return True
                
            isuni = True
            if node.left:
                isuni &= dsf(node.left) and node.val == node.left.val
            if node.right:
                isuni &= dsf(node.right) and node.val == node.right.val
                
            if isuni:
                self.res += 1
                
            return isuni
        
        dsf(root)
        return self.res
        
    def countUnivalSubtrees(self, root: TreeNode) -> int:
        return self.countUnivalSubtrees_dsf_recursion(root)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
https://leetcode.com/problems/symmetric-tree
 
Solution1. Recursive DSF
time: o(n)
space: o(n)

'''
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def recursion(node1, node2):
            if not node1 or not node2:
                return node1 == node2
            if node1.val != node2.val:
                return False
            return recursion(node1.left, node2.right) and recursion(node1.right, node2.left)
        return recursion(root, root)

        
        
        
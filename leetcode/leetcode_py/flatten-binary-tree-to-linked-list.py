# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
https://leetcode.com/problems/flatten-binary-tree-to-linked-list

1. dfs (post order)
2. no recursion and stack(queue)
 
'''
class Solution:
    def flatten_1(self, root: Optional[TreeNode]) -> None:
        if not root: return
        self.flatten_1(root.left)
        self.flatten_1(root.right)
        if root.left:
            cur = root.left
            while cur.right: cur = cur.right
            cur.right = root.right
            root.right = root.left
            root.left = None

    def flatten_2(self, root: Optional[TreeNode]) -> None:
        if not root: return
        while root:
            if root.left and root.right:
                cur = root.left
                while cur.right: cur = cur.right
                cur.right = root.right
                
            if root.left:
                root.right = root.left
            root.left = None
            root = root.right
        
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.flatten_2(root) 
        
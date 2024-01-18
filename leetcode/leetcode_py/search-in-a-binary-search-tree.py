# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
 https://leetcode.com/problems/search-in-a-binary-search-tree
 
 1. DFS preorder
 time: o(n)
 space: o(n)

 2. Iteration
 time: o(n)
 space: o(1)
 '''
class Solution:
    def searchBST_1(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root or root.val == val: return root
        if root.val < val: return self.searchBST_1(root.right, val)
        return self.searchBST(root.left, val)

    def searchBST_2(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        while root and root.val != val:
            root = root.right if root.val < val else root.left
        return root
        
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        return self.searchBST_2(root, val)
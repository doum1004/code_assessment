# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
https://leetcode.com/problems/binary-tree-right-side-view

Solution1. Recursion (DSF, middle, right, left)
time: o(n)
space: o(n)

1. dsf. preorder and add value
'''

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        def dsf(node, level):
            if not node:
                return
            if len(res) == level:
                res.append(node.val)
            dsf(node.right, level+1)
            dsf(node.left, level+1)
            
        dsf(root, 0)
        return res
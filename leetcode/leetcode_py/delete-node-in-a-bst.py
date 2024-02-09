# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
https://leetcode.com/problems/delete-node-in-a-bst

1. DFS recursion to find node and delete (replace node or value)
time: o(n)
space: o(n)
'''
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root: return root

        if root.val < key: root.right = self.deleteNode(root.right, key)
        elif root.val > key: root.left = self.deleteNode(root.left, key)
        else:
            if not root.left: root = root.right
            elif not root.right: root = root.left
            else:
                next = root.right
                while next.left: next = next.left
                root.val = next.val
                root.right = self.deleteNode(root.right, root.val)

        return root
        
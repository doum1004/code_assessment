# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

'''
 https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

 Solution1. Build ChildParent map (child: parent, level) and find common parent
 time: o(n) n + n + n
 space: o(n);

 Solution2-3. DFS return pointer if it hits p or q (or null)
 time: o(n)
 space: o(n) height
 '''

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root or root == p or root == q: return root
        l = self.lowestCommonAncestor(root.left, p, q)
        r = self.lowestCommonAncestor(root.right, p, q)
        if l and r: return root
        return l if l else r

        
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
https://leetcode.com/problems/binary-tree-level-order-traversal

 Solution1. DSF (in order, pass level)
 time: o(n)
 space: o(n)

 Solution2. BSF 
 time: o(n)
 space: o(n)

'''
class Solution:
    def levelOrder_1(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        def dsf(node, level):
            if not node:
                return
            if len(res) <= level:
                res.append([])
            res[level].append(node.val)
            dsf(node.left, level+1)
            dsf(node.right, level+1)
        dsf(root, 0)
        return res

    def levelOrder_2(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        q = []
        q.append(root)

        res = []        
        while q:
            n = len(q)
            vals = []
            for i in range(n):
                node = q.pop(0)
                vals.append(node.val)
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)

            res.append(vals)

        return res
        
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        return self.levelOrder_2(root)
        
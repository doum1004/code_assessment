# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
https://leetcode.com/problems/binary-tree-maximum-path-sum

Solution. DFS postorder
time: o(n)
space: o(n)
'''
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = float(-inf)
        def dfs(node):
            if not node: return 0
            l = dfs(node.left)
            r = dfs(node.right)
            self.res = max(self.res, node.val + l + r)
            return max(0, node.val + max(l, r))
        dfs(root)
        return self.res
        
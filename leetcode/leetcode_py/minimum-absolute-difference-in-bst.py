'''
https://leetcode.com/problems/minimum-absolute-difference-in-bst
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        values = []
        def dfs(node):
            if not node: return
            dfs(node.left)
            values.append(node.val)
            dfs(node.right)
        dfs(root)
        m = float(inf)
        for i in range(1,len(values)):
            m = min(m, abs(values[i] - values[i-1]))
        return m
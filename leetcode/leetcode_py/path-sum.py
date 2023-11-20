# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def recursion(node, sum):
            if node is None:
                return False
            sum += node.val
            if node.left is None and node.right is None:
                return sum == targetSum
            return recursion(node.left, sum) or recursion(node.right, sum)

        return recursion(root, 0)

        
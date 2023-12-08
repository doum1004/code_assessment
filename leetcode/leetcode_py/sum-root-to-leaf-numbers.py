# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
https://leetcode.com/problems/sum-root-to-leaf-numbers
 
Solution1-2. DFS / BFS
time: o(n)
space: o(n)
'''
class Solution:
    def sumNumbers_1(self, root: Optional[TreeNode]) -> int:
        def dfs(node, cur):
            if not node: return 0
            if not node.left and not node.right: return cur + node.val

            cur = (cur + node.val) * 10
            val = dfs(node.left, cur)
            val += dfs(node.right, cur)
            return val
        return dfs(root, 0)

    def sumNumbers_2(self, root: Optional[TreeNode]) -> int:
        q = []
        q.append((root, 0))

        ans = 0
        while q:
            node, val = q.pop(0)
            if not node: continue
            if not node.left and not node.right:
                ans += val + node.val
                continue
            val = (val + node.val) * 10
            if node.left:
                q.append((node.left, val))
            if node.right:
                q.append((node.right, val))

        return ans
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.sumNumbers_2(root)
        
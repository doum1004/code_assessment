# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
 https://leetcode.com/problems/path-sum-iii
 
 1. DFS
 time: o(n^2)
 space: o(n)

 2. DFS with map. store sum of all path of parent. And find parent sum equal to cursum - target
 time: o(n)
 space: o(n)
 '''
class Solution:
    def pathSum_1(self, root: Optional[TreeNode], targetSum: int) -> int:
        if not root:
            return 0
        def dfs(node, sum):
            if not node:
                return 0
            sum += node.val
            cnt = 0
            if sum == targetSum:
                cnt = 1
            cnt += dfs(node.left, sum)
            cnt += dfs(node.right, sum)
            return cnt
        return dfs(root, 0) + self.pathSum_1(root.left, targetSum) + self.pathSum_1(root.right, targetSum)

    def pathSum_2(self, root: Optional[TreeNode], targetSum: int) -> int:
        m = defaultdict(int)
        def dfs(node, sum):
            if not node: return 0
            sum += node.val
            cnt = 0
            if sum == targetSum:
                cnt = 1
            cnt += m[sum-targetSum]
            m[sum] += 1
            cnt += dfs(node.left, sum)
            cnt += dfs(node.right, sum)
            m[sum] -= 1
            return cnt
        return dfs(root, 0)

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        return self.pathSum_2(root, targetSum)
        
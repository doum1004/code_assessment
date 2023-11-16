'''
https://leetcode.com/problems/average-of-levels-in-binary-tree
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels_dfs(self, root: Optional[TreeNode]) -> List[float]:
        sums = []        
        def dfs(node, level):
            if not node:
                return
            if len(sums) <= level:
                sums.append([node.val, 1])
            else:
                sums[level][0] += node.val
                sums[level][1] += 1
            dfs(node.left, level+1)
            dfs(node.right, level+1)

        dfs(root, 0)
        res = []
        for v in sums:
            res.append(v[0] / v[1])

        return res

    def averageOfLevels_bfs(self, root: Optional[TreeNode]) -> List[float]:
        q = deque()
        q.append(root)

        res = []
        while q:
            sum = 0
            qSize = len(q)
            for _ in range(qSize):
                node = q.popleft()
                sum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            res.append(sum/qSize)
        return res

    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        return self.averageOfLevels_bfs(root)
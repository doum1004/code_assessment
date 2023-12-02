# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

Solution1. DFS
time: o(n)
space: o(n)

Solution2. BFS + reverse every iteration (reverse->nomal->reverse). using deque
time: o(n)
space: o(n)
'''
class Solution:
    def zigzagLevelOrder_1(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        def dfs(node, level):
            if not node: return
            
            if len(res) < level + 1: res.append([])
            if level % 2 == 0: res[level].append(node.val)
            else: res[level].insert(0, node.val)

            dfs(node.left, level+1)
            dfs(node.right, level+1)
            
        dfs(root, 0)
        return res

    def zigzagLevelOrder_2(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return []
        q = []
        q.append(root)
        
        res = []
        level = 0
        while q:
            qSize = len(q)            
            values = [-1] * qSize
            for i in range(qSize):
                node = q.pop(0)
                if not node: continue

                p = i
                if level % 2 == 1: p = qSize - i - 1
                values[p] = node.val

                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            if values:
                res.append(values)
            level += 1
        return res

    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        return self.zigzagLevelOrder_2(root)
        
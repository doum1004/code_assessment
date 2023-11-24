# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
https://leetcode.com/problems/validate-binary-search-tree

 Solution1. DSF inorder (passing min, max nodes)
 time: o(n)
 space: o(n)

 1. build dfs to compare min, max node on current node
 - inorder traversal
 - compare min max nodes
 - iterate left(min, node), right(node, max)

 Solution2. BSF inorder
 time: o(n)
 space: o(n)
'''

class Solution:
    def isValidBST_1(self, root: Optional[TreeNode]) -> bool:
        def dfs(node, min, max):
            if not node:
                return True
            if min and node.val <= min.val:
                return False
            if max and node.val >= max.val:
                return False
            return dfs(node.left, min, node) and dfs(node.right, node, max)
        return dfs(root, None, None)
        
    def isValidBST_2(self, root: Optional[TreeNode]) -> bool:
        if not root: return True
        q = []
        q.append([root, None, None])
        while q:
            n = len(q)
            for i in range(n):
                nodes = q.pop(0)        
                node = nodes[0]
                minNode = nodes[1]
                maxNode = nodes[2]
                
                if minNode and minNode.val >= node.val:
                    return False
                if maxNode and maxNode.val <= node.val:
                    return False
                if node.left: q.append([node.left, minNode, node])
                if node.right: q.append([node.right, node, maxNode])
        return True


    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.isValidBST_2(root)
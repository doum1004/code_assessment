# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

Solution1. divide and conquer(recursion)
time: o(n^2) visit node(n) * find inroder pivot(n)
space: o(n)

Solution2. divide and conquer + map (find pivot index quick)
time: o(n)
space: o(n) recursion + map
'''

class Solution:
    def buildTree_1(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def build(l, r):
            if l > r:
                return None
            val = preorder[self.idx]
            pivot = l
            while inorder[pivot] != val:
                pivot += 1

            self.idx += 1
            node = TreeNode(val)
            node.left = build(l, pivot-1)
            node.right = build(pivot+1, r)
            return node
        self.idx = 0
        return build(0, len(inorder) - 1)

    def buildTree_2(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def build(l, r):
            if l > r:
                return None
            val = preorder[self.idx]
            pivot = m[val]

            self.idx += 1
            node = TreeNode(val)
            node.left = build(l, pivot-1)
            node.right = build(pivot+1, r)
            return node
        self.idx = 0
        m = {}
        for i, v in enumerate(inorder):
            m[v] = i
        return build(0, len(inorder) - 1)

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        return self.buildTree_2(preorder, inorder)
            
        
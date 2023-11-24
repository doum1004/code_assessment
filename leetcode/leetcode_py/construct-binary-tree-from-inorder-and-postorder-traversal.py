# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

Solution1. Divide and conquer (recursion). Find root from postorder and build tree from inorder
time: o(n^2)
space: o(n)

Solution2. Solution1 + map to store inorder index
time: o(n)
space: o(n)
'''
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        self.idx = len(inorder) - 1
        m = {}
        for i, v in enumerate(inorder):
            m[v] = i

        def build(l, r):
            if l > r:
                return None
            val = postorder[self.idx]
            i_inorder = m[val]
            # while val != inorder[i_inorder]:
            #     i_inorder += 1

            self.idx -= 1
            node = TreeNode(val)
            node.right = build(i_inorder + 1, r)
            node.left = build(l, i_inorder - 1)
            return node            

        return build(0, len(postorder) - 1)
        
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
 https://leetcode.com/problems/invert-binary-tree/
 
 Solution1. recursion. DSF
 time: o(n)
 space: o(n)
 
 Solution2. iteration. BSF
 time: o(n)
 space: o(n)
 '''
 
class Solution:
    def invertTree_1(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root: return None
        l = self.invertTree_1(root.left)
        r = self.invertTree_1(root.right)
        root.left = r
        root.right = l
        return root

    def invertTree_2(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root: return None
        q = deque()
        q.append(root)        
        while len(q):
            n = len(q)
            for i in range(n):
                node = q.popleft()
                
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)

                temp = node.left
                node.left = node.right
                node.right = temp              

        return root

    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.invertTree_2(root)
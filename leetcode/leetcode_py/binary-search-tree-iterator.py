# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
https://leetcode.com/problems/binary-search-tree-iterator

 Solution1. partial preorder with queue
 time
 - constructor: o(n)
 - next: o(1)
 - hasNext: o(1)
space: o(n)

 Solution2. partial inorder with stack
 time
 - constructor: o(h)
 - next: o(1)
 - hasNext: o(1)
 space: o(h)
 '''
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.stack = []
        self.partialInorder(root)
        
    def partialInorder(self, node):
        while node:
            self.stack.append(node)
            node = node.left            

    def next(self) -> int:
        node = self.stack.pop()
        self.partialInorder(node.right)
        return node.val
        
    def hasNext(self) -> bool:
        return self.stack
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
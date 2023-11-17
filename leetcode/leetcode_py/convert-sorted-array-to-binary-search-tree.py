'''
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:        
        def buildNode(l, r):
            if r < l or l > r:
                return None
            m = int((l+r)/2)
            node = TreeNode(nums[m])
            node.left = buildNode(l, m-1)
            node.right = buildNode(m+1, r)
            return node
        return buildNode(0, len(nums) - 1)
        
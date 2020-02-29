"""
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        def dfs(node) -> str:
            if not node:
                return '*'
            return str(node.val) + "," + dfs(node.left) + "," + dfs(node.right)
        return dfs(root)
        
    def deserialize(self, data):
        print(data)
        def dfs(data_list) -> TreeNode:
            val = next(data_list)
            if val == '*':
                return None
            
            node = TreeNode(int(val))
            node.left = dfs(data_list)
            node.right = dfs(data_list)
            return node
        
        data_list = iter(data.split(','))
        return dfs(data_list)
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
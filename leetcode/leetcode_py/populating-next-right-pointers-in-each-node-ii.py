"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
'''
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii
Solution1. BSF
time: o(n)
space: o(n)

Solution2. DSF
time: o(n)
space: o(n)
'''
class Solution:
    def connect_1(self, root: 'Node') -> 'Node':
        nodes = {}
        def dfs(node, level):
            if not node: return 
            if level in nodes:
                nodes[level].next = node
            nodes[level] = node
            dfs(node.left, level+1)a
            dfs(node.right, level+1)
        dfs(root, 0)
        return root
        
    def connect_2(self, root: 'Node') -> 'Node':
        q = []
        q.append(root)
        
        while q:
            qSize = len(q)
            previous = None
            for i in range(qSize):
                node = q.pop(0)
                if not node: continue
                if previous:
                    previous.next = node
                previous = node
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)

        return root

    def connect(self, root: 'Node') -> 'Node':
        return self.connect_2(root)
        
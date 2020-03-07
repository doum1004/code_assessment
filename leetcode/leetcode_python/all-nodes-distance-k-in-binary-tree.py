from typing import List
import collections

"""
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

solution1. Get target distance and path to target (DSF). DSF to get distnace from target (if node is in path, -1. else +1)

solution2. Save parent info(DSF). Iterate from target with parent as child as well (BSF)

"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def distanceK_saveParent(self, root: TreeNode, target: TreeNode, K: int) -> List[int]:
        self.parentInfo = {}
        def storeParentInfo_DSF(node, parent):
            if not node:
                return
            self.parentInfo[node] = parent
            storeParentInfo_DSF(node.left, node);
            storeParentInfo_DSF(node.right, node);
            
        storeParentInfo_DSF(root, None)
        
        q = collections.deque()
        q.append((target, 0));
        
        res = []
        visited = {}
        while (q):
            node, dist = q.popleft()
            if not node or node in visited:
                continue
            visited[node] = True
            
            if (dist == K):
                res.append(node.val)
                continue
            
            for adj in (node.left, node.right, self.parentInfo[node]):
                q.append((adj,dist+1))
        
        return res
        
        
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) -> List[int]:
        return self.distanceK_saveParent(root, target, K)
        
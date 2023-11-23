"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

'''
https://leetcode.com/problems/copy-list-with-random-pointer

Solution1. Using Map. (Save copied pointer in map)
time: o(n) n + n
space: o(n) store hash map

1. Create dummy
2. Iterate head and create copy and save it into map for random pointer

Solution2. Without map. origin node points new copied
time: o(n)
space: o(1)

1. Iterate origin and copy for the new. And Make origin node->next points copy and copy points node->next
- node1 -> node1-copy -> node2 -> node2-copy
2. Iterate to set random
- node1-copy->random-> ...
3. separate cloned
- node1 -> node2
- node1 copy -> node2 copy

'''

class Solution:
    def copyRandomList_1(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head: return None

        m = {}

        node = head
        dummy = Node(-1)
        cloned = dummy
        while node:
            copy = Node(node.val)
            m[node] = copy
            cloned.next = copy

            node = node.next
            cloned = cloned.next

        node = head
        cloned = dummy.next
        while node:
            if node.random:
                cloned.random = m[node.random]

            node = node.next
            cloned = cloned.next
        
        return dummy.next
        
    def copyRandomList_2(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head: return None

        origin = head
        # set copy as next
        while origin:
            next = origin.next
            origin.next = Node(origin.val)
            origin.next.next = next
            origin = next

        # set random on clone
        origin = head
        while origin:
            # clone
            clone = origin.next
            next = clone.next

            if origin.random:
                clone.random = origin.random.next
            else:
                clone.random = None
            origin = next

        # separate clone
        origin = head
        res = origin.next
        while origin:
            cloned = origin.next
            origin.next = cloned.next
            origin = cloned.next

            if origin:
                cloned.next = origin.next
            else:
                cloned.next = None

        return res

    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        return self.copyRandomList_2(head)
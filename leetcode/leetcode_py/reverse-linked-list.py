# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
 https://leetcode.com/problems/reverse-linked-list
 
 1. Recursive
 time: o(n)
 space: o(n)

 2. Itearte using Stack
 time: o(n)
 space: o(n)

 3. Iterate in space
 time: o(n)
 space: o(1)
 '''
class Solution:
    def reverseList_1(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def recursive(node):
            if not node or not node.next:
                return node
            tail = recursive(node.next)
            node.next.next = node
            node.next = None
            return tail
        return recursive(head)

    def reverseList_2(self, head: Optional[ListNode]) -> Optional[ListNode]:
        s = []
        cur = head
        while cur:
            s.append(cur.val)
            cur = cur.next
        dummy = ListNode(0)
        cur = dummy
        while s:
            cur.next = ListNode(s[-1])
            cur = cur.next
            s.pop(-1)
        return dummy.next
        
    def reverseList_3(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre = None
        cur = head
        while cur:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        return pre

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.reverseList_3(head)
        
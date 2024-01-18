# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
 https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
 
 1. Add them into list or Iterate twice to get total numbers
 time: o(n) 2n
 space: o(n or 1)

 2. Two pointers to place middle of node
 time: o(n)
 space: o(1)
 '''
class Solution:
    def deleteMiddle_1(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None

        l = []
        cur = head
        while cur:
            l.append(cur)
            cur = cur.next
        cur = l[len(l)//2-1]
        cur.next = cur.next.next
        return head           

    def deleteMiddle_2(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None
        slow, fast = head, head.next
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        slow.next = slow.next.next
        return head
        
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.deleteMiddle_2(head)
        
        
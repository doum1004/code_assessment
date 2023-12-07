# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

'''
 https://leetcode.com/problems/rotate-list
 
 Solution1. Store into list and start from n-k-1
 time: o(n)
 space: o(n)

 Solution2. In place
 time: o(n)
 space: o(1)
'''
class Solution:
    def rotateRight_1(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or k == 0: return head
        dummy = ListNode(0)
        dummy.next = head
        l = []
        while head:
            l.append(head)
            head = head.next
        n = len(l)
        k = k % n
        if n == 1 or k == 0: return dummy.next

        cnt = n
        idx = n-k
        head = dummy
        while cnt > 0:
            head.next = l[idx]
            head = head.next
            idx = (idx + 1) % n
            cnt -= 1
        head.next = None
        return dummy.next
        
    def rotateRight_2(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or k == 0: return head
        dummy = ListNode(0)
        dummy.next = head
        n = 0
        while head:
            n += 1
            head = head.next
        k = k % n
        if n == 1 or k == 0: return dummy.next

        head = dummy
        cnt = n - k
        while head and cnt > 0:
            head = head.next
            cnt -= 1
        
        cur = head.next # cur
        head.next = None # set null on last in new loop

        dummyNext = dummy.next # first in previous loop
        dummy.next = cur # first in new loop

        while cur.next: cur = cur.next
        cur.next = dummyNext
        return dummy.next

    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        return self.rotateRight_2(head, k)
        
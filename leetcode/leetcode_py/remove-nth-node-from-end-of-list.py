# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
https://leetcode.com/problems/remove-nth-node-from-end-of-list

Solution1. two paths
time: o(n)
space: o(1)

Solution2. one path
time: o(n)
space: o(1)
'''
class Solution:
    def removeNthFromEnd_1(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        slow, fast = dummy, dummy
        while n:
            n -= 1
            fast = fast.next
        while fast.next:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return dummy.next

    def removeNthFromEnd_2(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        cnt = 0
        while head:
            head = head.next
            cnt += 1
        
        head = dummy
        for i in range(0, cnt-n):
            head = head.next
        head.next = head.next.next
        return dummy.next

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        return self.removeNthFromEnd_2(head, n)
        
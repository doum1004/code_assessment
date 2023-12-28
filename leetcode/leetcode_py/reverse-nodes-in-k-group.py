# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

'''
https://leetcode.com/problems/reverse-nodes-in-k-group

Iterate and swap
time: o(n)
space: o(1)
'''
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        num = 0
        while head:
            num += 1
            head = head.next
        pre = dummy
        head = dummy.next
        while num >= k:
            for i in range(k-1):
                pre_next = pre.next
                head_next = head.next
                head_next_next = head.next.next
                pre.next = head_next
                head_next.next = pre_next
                head.next = head_next_next
            pre = head
            head = head.next
            num -= k
        return dummy.next
        
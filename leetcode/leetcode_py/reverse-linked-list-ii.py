# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

'''
https://leetcode.com/problems/reverse-linked-list-ii
Solution1. Iteration and swap
'''
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        for i in range(left-1):
            pre = pre.next

        cur = pre.next
        for i in range(right-left):
            t = pre.next
            n = cur.next
            nn = cur.next.next
            pre.next = n
            n.next = t
            cur.next = nn

        return dummy.next
        
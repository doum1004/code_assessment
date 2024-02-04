# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

1. Stack
time: o(n)
space: o(n)

2. Two Pointers (in place)
- Find middle using two pointers
- Reverse nodes after middle
- Find max sum front two pointers
(reverse)
          1 2 3
        p s n nn

        n = s->next
        s->next = pre
        s = n
'''
class Solution:
    def pairSum_1(self, head: Optional[ListNode]) -> int:
        s = []
        node = head
        while node:
            s.append(node.val)
            node = node.next

        res = 0
        while head:
            res = max(res, s[-1] + head.val)
            head = head.next
            s.pop()
        return res
        
    def pairSum_2(self, head: Optional[ListNode]) -> int:
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # reverse
        pre = None
        while slow:
            next = slow.next
            slow.next = pre
            pre = slow
            slow = next

        res = 0
        while pre:
            res = max(res, pre.val + head.val)
            head, pre = head.next, pre.next
        return res

    def pairSum(self, head: Optional[ListNode]) -> int:
        return self.pairSum_2(head)
        
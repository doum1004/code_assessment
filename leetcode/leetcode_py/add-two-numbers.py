"""
https://leetcode.com/problems/add-two-numbers/

2 4 3 1
5 6 4

7 0

c = sum / 10
#time o(max(n,m))
#space o(max(n,m))

"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummyNode = ListNode(-1)
        cur = dummyNode
        c = 0
        while l1 or l2:
            s = c
            if l1:
                s += l1.val
                l1 = l1.next
            if l2:
                s += l2.val
                l2 = l2.next
            
            c = s // 10
            cur.next = ListNode(s % 10)
            cur = cur.next
        if c:
            cur.next = ListNode(c)
                
        return dummyNode.next
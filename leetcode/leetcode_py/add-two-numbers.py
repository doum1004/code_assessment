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
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyNode = ListNode()
        cur = dummyNode
        c = 0
        while l1 or l2 or c:
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
                
        return dummyNode.next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
 https://leetcode.com/problems/partition-list
 
 Solution1. Save it in two list (l1: smaller, l2: same or greater)
 time: o(n)
 space: o(n)
 Solution2. Save it in dummy node
 time: o(n)
 space: o(1) 2 dummy
 '''
class Solution:
    def partition_1(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        small = []
        great = []
        dummy = ListNode(0)
        while head:
            if head.val < x: small.append(head)
            else: great.append(head)
            head = head.next
        head = dummy
        for node in small:
            head.next = node
            head = node
        
        for node in great:
            head.next = node
            head = node
        head.next = None
        return dummy.next
        
    def partition_2(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        small, great = ListNode(0), ListNode(0)
        smallHead, greatHead = small, great
        while head:
            if head.val < x:
                small.next = head
                small = head
            else:
                great.next = head
                great = head
            head = head.next
        small.next = greatHead.next
        great.next = None
        return smallHead.next
        
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        return self.partition_2(head, x)

        
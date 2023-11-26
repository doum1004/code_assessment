# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
Solution1. Sort algo
time: o(nlogn)
space: o(n) vector list
 
Solution2. merge sort
time: o(nlogn)
space: o(1)
'''
class Solution:
    def sortList_1(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        nodes = []
        while head:
            nodes.append(head)
            head = head.next
            
        nodes.sort(key=lambda x: x.val)
        
        for i in range(len(nodes)-1):
            nodes[i].next = nodes[i+1]
        nodes[-1].next = None

        return nodes[0]
        
    def merge(self, l, r):
        dummy = ListNode(0)
        node = dummy
        while l and r:
            if l.val < r.val:
                node.next = l
                l = l.next
            else:
                node.next = r
                r = r.next
            node = node.next
            
        if l:
            node.next = l
        elif r:
            node.next = r
        return dummy.next

    def sortList_2(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        fast = slow.next
        slow.next = None

        return self.merge(self.sortList_2(head), self.sortList_2(fast))

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.sortList_2(head)
        
        
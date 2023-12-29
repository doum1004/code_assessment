# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
 https://leetcode.com/problems/merge-k-sorted-lists
 
solution1. add all node in vector and sort and make list again
time: o(nlogn)
space: o(1) use pointer (no extra mem)

solution2. (reduce space) min-heap
time: o(nlogn) n*logn
space: o(1) use pointer (no extra mem)

Solution3. Divide and Conquer
time: o(nlogn)
space: o(n) recursive call
'''
class Solution:
    def mergeKLists_1(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        v = []
        for node in lists:
            while node:
                v.append(node)
                node = node.next
        v.sort(key=lambda x: x.val)
        dummy = ListNode(0)
        cur = dummy
        for n in v:
            cur.next = n
            cur = cur.next
            cur.next = None
        return dummy.next
        
    def mergeKLists_2(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        h = []
        for node in lists:
            while node:
                heapq.heappush(h, node.val)
                node = node.next

        dummy = ListNode(0)
        cur = dummy
        while h:
            cur.next = ListNode(heapq.heappop(h))
            cur = cur.next
            cur.next = None
        return dummy.next
        
    def mergeKLists_3(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 1: return lists[0]
        if len(lists) == 0: return None

        def merge(l, r):
            if not l: return r
            if not r: return l
            if l.val < r.val:
                l.next = merge(l.next, r)
                return l
            else:
                r.next = merge(l, r.next)
                return r

        def partition(start, end):
            if start == end: return lists[start]
            if start < end:
                mid = (end + start) // 2
                l = partition(start, mid)
                r = partition(mid+1, end)
                return merge(l, r)
            return None

        return partition(0, len(lists)-1)

    
        

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        return self.mergeKLists_3(lists)
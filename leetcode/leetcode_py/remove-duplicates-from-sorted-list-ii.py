# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

 Solution1. map and build nodes
 time: o(n)
 space: o(n)

 Solution2. Two pointers (ref, cur)
 time: o(n)
 space: o(1)
 
 1. set dummy
 2. set pre(dummy), ref(pre->next)
 3. loop ref != null
 3.1 cur(ref) cnt(0)
 3.2 loop ref.val == cur.val: cur = cur.next and cnt+=1
 3.3 cnt == 1: pre->next = ref. and pre = pre->next
 3.4 ref = cur
 4. pre->next = ref
 5. return dummy->next

     1 2 3 3 4 4 5
1) d
   p r
     c

     1 2 3 3 4 4 5 (cnt = 1)
2) d
     p r
         c
3) d
       p r
         c
     1 2 3 3 4 4 5 (cnt = 2)
2) d
       p r
             c
3) d
       p     r
             c
'''
class Solution:
    def deleteDuplicates_1(self, head: Optional[ListNode]) -> Optional[ListNode]:
        hp = defaultdict(int)
        dummy = ListNode(0)
        dummy.next = head
        while head:
            hp[head.val] += 1
            head = head.next
        pre = dummy
        head = dummy.next
        while head:
            if hp[head.val] == 1:
                pre.next = head
                pre = head
            head = head.next
        pre.next = head
        return dummy.next
        
    def deleteDuplicates_2(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        pre, ref = dummy, dummy.next
        while ref:
            cur = ref
            cnt = 0
            while cur and ref.val == cur.val:
                cur = cur.next
                cnt += 1
            if cnt == 1:
                pre.next = ref
                pre = pre.next
            ref = cur
        pre.next = ref
        return dummy.next
        
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.deleteDuplicates_2(head)
        
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /*
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
 3.2 move cur if same as ref and cnt+=1
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
 */
class Solution {
public:
    ListNode* deleteDuplicates_1(ListNode* head) {
        unordered_map<int, int> hm;
        
        auto dummy = new ListNode(0);
        dummy->next = head;
        
        while (head) {
            hm[head->val]++;
            head = head->next;
        }

        head = dummy->next;
        auto pre = dummy;
        while (head) {
            if (hm[head->val] == 1) {
                pre->next = head;
                pre = head;
            }
            head = head->next;
        }
        pre->next = head;

        return dummy->next;
    }

    ListNode* deleteDuplicates_2(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto pre = dummy;
        auto ref = pre->next;
        while (ref) {
            auto cur = ref;
            int cnt = 0;
            while (cur && cur->val == ref->val) {
                cur = cur->next;
                cnt += 1;
            }
            if (cnt == 1) {
                pre->next = ref;
                pre = pre->next;
            }
            ref = cur;
        }
        pre->next = ref;
        return dummy->next;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        return deleteDuplicates_2(head);
    }
};
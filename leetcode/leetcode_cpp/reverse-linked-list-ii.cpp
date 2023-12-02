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
 https://leetcode.com/problems/reverse-linked-list-ii

Solution1. Iteration and swap
   l         r
 1 2    3 4  5 6
 p c(t) n nn
 p->n n->t c->nn

   l     r
 1 3 2 4 5 6
 p t c n nn
 p->n n->t c->nn
    
    l     r
 1 4 3 2 5 6
 p t   c n nn
 p->n n->t c->nn
 1 5 4 3 2 6

 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        auto pre = dummy;
        for (int i=0; i<left-1; ++i)
            pre = pre->next;
        auto cur = pre->next;
        for (int i=0; i<right-left; ++i) {
            auto t = pre->next;
            auto n = cur->next;
            auto nn = cur->next->next;
            pre->next = n;
            n->next = t;
            cur->next = nn;
        }
        return dummy->next;
    }
};
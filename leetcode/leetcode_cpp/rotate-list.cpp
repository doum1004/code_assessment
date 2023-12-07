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
 https://leetcode.com/problems/rotate-list
 
 Solution1. Store into list and start from n-k-1
 time: o(n)
 space: o(n)

 Solution2. In place
 time: o(n)
 space: o(1)
 */
class Solution {
public:
    ListNode* rotateRight_1(ListNode* head, int k) {
        if (!head || k == 0) return head;
        vector<ListNode*> l;
        auto dummy = new ListNode(0);
        dummy->next = head;
        
        while (head) {
            l.push_back(head);
            head = head->next;
        }
        auto n = l.size();
        k = k % n;
        if (n == 1 || k == 0) return dummy->next ;

        int cnt = n;
        int idx = (n-k) % n;
        head = dummy;
        while (cnt > 0) {
            head->next = l[idx];
            head = head->next;            
            idx = (idx + 1) % n;
            cnt -= 1;
        }
        head->next = nullptr;
        return dummy->next;   
    }

    ListNode* rotateRight_2(ListNode* head, int k) {
        if (!head || k == 0) return head;

        auto dummy = new ListNode(0);
        dummy->next = head;
        
        int n = 0;
        while (head) {
            head = head->next;
            n += 1;
        }
        k = k % n;
        if (n == 1 || k == 0) return dummy->next ;
        
        head = dummy;
        int cnt = n - k;
        while (head && cnt > 0) {
            head = head->next;
            cnt -= 1;
        }
        if (!head) return dummy->next;

        auto cur = head->next; // cur
        head->next = nullptr; // last in new loop

        auto dummyNext = dummy->next; // first in previous loop
        dummy->next = cur; // first in new loop

        while (cur->next) cur = cur->next;
        cur->next = dummyNext;
        return dummy->next;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        return rotateRight_2(head, k);
    }
};
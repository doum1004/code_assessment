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
 https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
 
 1. Add them into list or Iterate twice to get total numbers
 time: o(n) 2n
 space: o(n or 1)

 2. Two pointers to place middle of node
 time: o(n)
 space: o(1)
 */
class Solution {
public:
    ListNode* deleteMiddle_1(ListNode* head) {
        if (!head || !head->next) return nullptr;
        auto cur = head;
        int n=0;
        while (cur) {
            n += 1;
            cur = cur->next;
        }
        cur = head;
        int m = n / 2;
        while (m > 1) {
            cur = cur->next;
            m -= 1;
        }
        cur->next = cur->next ? cur->next->next : nullptr;
        return head;
    }
    ListNode* deleteMiddle_2(ListNode* head) {
        if (!head || !head->next) return nullptr;        
        auto slow = head, fast = head->next;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
    ListNode* deleteMiddle(ListNode* head) {
        return deleteMiddle_2(head);
    }
};
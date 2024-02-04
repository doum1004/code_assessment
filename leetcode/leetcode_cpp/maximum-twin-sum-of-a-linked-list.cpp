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
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

1. Stack
time: o(n)
space: o(n)

2. Two Pointers (in place)
- Find middle using two pointers
- Reverse nodes after middle
- Find max sum front two pointers
(reverse)
          1 2 3
        p s n nn

        n = s->next
        s->next = pre
        s = n
*/
class Solution {
public:
    int pairSum_1(ListNode* head) {
        stack<int> s;
        auto node = head;
        while (node) {
            s.push(node->val);
            node = node->next;
        }
      
        int res = 0;
        node = head;
        while (node) {
            res = max(res, s.top() + node->val);
            s.pop();
            node = node->next;
        }
        return res;
    }

    int pairSum_2(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head->val;
        
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* pre = nullptr;
        while (slow) {
            auto next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }

        int res = 0;
        while (head && pre) {
            res = max(res, head->val + pre->val);
            head = head->next;
            pre = pre->next;
        }
        return res;
    }

    int pairSum(ListNode* head) {
        return pairSum_2(head);
    }
};
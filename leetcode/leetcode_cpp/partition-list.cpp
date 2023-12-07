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
 https://leetcode.com/problems/partition-list
 
 Solution1. Save it in two list (l1: smaller, l2: same or greater)
 time: o(n)
 space: o(n)
 Solution2. Save it in dummy node
 time: o(n)
 space: o(1) 2 dummy
 */
class Solution {
public:
    ListNode* partition_1(ListNode* head, int x) {
        auto dummy = new ListNode();
        dummy->next = head;
        vector<ListNode*> small;
        vector<ListNode*> greater;
        while (head) {
            if (head->val < x) small.push_back(head);
            else greater.push_back(head);
            head = head->next;
        }
        
        head = dummy;
        for (auto node : small) {
            head->next = node;
            head = head->next;
        }
        for (auto node : greater) {
            head->next = node;
            head = head->next;
        }
        head->next = nullptr;
        return dummy->next;
    }
    ListNode* partition_2(ListNode* head, int x) {
        auto small = new ListNode();
        auto smallHead = small;
        auto great = new ListNode();
        auto greatHead = great;
        
        auto dummy = small;
        
        while (head) {
            if (head->val < x) {
                small->next = head;
                small = head;
            }
            else {
                great->next = head;
                great = head;
            }
            head = head->next;
        }
        small->next = greatHead->next;
        great->next = nullptr;
        return smallHead->next;
    }
    ListNode* partition(ListNode* head, int x) {
        return partition_2(head, x);
    }
};
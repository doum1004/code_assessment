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
Solution1. Sort algo
time: o(nlogn)
space: o(n) vector list
 
Solution2. merge sort
time: o(nlogn)
space: o(1)

 */

class Solution {
public:
    ListNode* sortList_1(ListNode* head) {
        if (!head) return head;

        vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }

        sort(nodes.begin(), nodes.end(), [](ListNode* left, ListNode* right) {
            return left->val < right->val;
        });

        for (int i=0; i<nodes.size()-1; ++i) {
            nodes[i]->next = nodes[i+1];
        }
        nodes.back()->next = nullptr;
        return nodes[0];
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l && r) {
            if (l->val < r->val) {
                cur->next = l;
                l = l->next;
            }
            else {
                cur->next = r;
                r = r->next;
            }

            cur = cur->next;
        }
        if (l)
            cur->next = l;
        else
            cur->next = r;            
        return dummy.next;
    }

    ListNode* sortList_2(ListNode* head) {
        if (!head || !head->next) return head;

        // find middle element
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;

        return merge(sortList_2(head), sortList_2(fast));
    }

    ListNode* sortList(ListNode* head) {
        return sortList_2(head);
    }
};
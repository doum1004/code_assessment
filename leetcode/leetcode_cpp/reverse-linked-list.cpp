#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include "../listnode.h"

using namespace std;

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
 https://leetcode.com/problems/reverse-linked-list
 
 1. Recursive
 time: o(n)
 space: o(n)

 2. Itearte using Stack
 time: o(n)
 space: o(n)

 3. Iterate in space
 time: o(n)
 space: o(1)
 */
class Solution {
public:
    void recursive(ListNode* head, ListNode** res) {
        if (!head) return;
        
        recursive(head->next, res);
        (*res)->next = new ListNode(head->val);
        *res = (*res)->next;
    }

    ListNode* reverseList_1_2(ListNode* head) {
        // n, n
        ListNode* dummy = new ListNode(0);
        auto result = dummy;
        recursive(head, &result);
        return dummy->next;
    }

    ListNode* reverseList_1(ListNode* head) {
        if (!head || !head->next) return head;
        auto tail = reverseList_1(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }

    ListNode* reverseList_2(ListNode* head) {
        // n, n
        stack<int> v;
        auto cur = head;
        while (cur) {
            v.push(cur->val);
            cur = cur->next;
        }
        ListNode* dummy = new ListNode(0);
        cur = dummy;
        while (!v.empty()) {
            cur->next = new ListNode(v.top());
            cur = cur->next;
            v.pop();
        }
        return dummy->next;
    }

    ListNode* reverseList_3(ListNode* head) {
        ListNode* pre = nullptr;
        auto cur = head;
        while (cur) {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* reverseList(ListNode* head) {
        return reverseList_3(head);
    }
};

int main()
{
    auto input1_1 = new ListNode(1);
    input1_1->next = new ListNode(2);
    input1_1->next->next = new ListNode(3);
    input1_1->next->next->next = new ListNode(4);
    input1_1->next->next->next->next = new ListNode(5);

    auto expect1 = new ListNode(5);
    expect1->next = new ListNode(4);
    expect1->next->next = new ListNode(3);
    expect1->next->next->next = new ListNode(2);
    expect1->next->next->next->next = new ListNode(1);

    assert(isEqual(Solution().reverseList(
        input1_1), expect1));
    return 0;
}
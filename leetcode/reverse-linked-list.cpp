#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/reverse-linked-list/
// Iteration pre, cur cur->pre move to next
// time: o(n)
// space: o(1)
Node* pre = NULL;
while (bead != nullptr)
    auto t = head->next
    head->next = pre
    pre = head
    head = t
return pre

// recursion. node->next->next = node. node->next = null. return last element
// time: o(n)
// space: o(n)
recursion(node)
    if (node == nullptr || node->next == nullptr) return node;
    auto last = recursion(node->next)
    node->next->next = node
    node->next = NULL
    return last;
*/
class Solution {
public:
    ListNode* reverseList_iterative(ListNode* head) {
        ListNode* pre = nullptr;
        auto cur = head;
        while (cur != nullptr) {
            auto t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
    
    ListNode* reverseList_recursion(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return node;
        auto p = reverseList_recursion(node->next);
        node->next->next = node;
        node->next = nullptr;
        return p;
    }
    
    ListNode* reverseList_iterative(ListNode* head) {
        //return reverseList_recursion(head);
        return reverseList_iterative(head);
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

    assert(isEqual(Solution().reverseList_iterative(
        input1_1), expect1));
    return 0;
}
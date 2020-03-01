#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/reverse-linked-list

// Soluiton1. Recursive
// time o(n)
// space o(n)
ListNode* recursive(ListNode* node)
    if (node == nullptr) return nullptr;
    if (node->next == nullptr) return node;
    auto tail = recursive(node->next);
    node->next->next = node;
    node->next = nullptr;
    return tail;
    
// Soluiton2. Iteration with stack
// time o(n)
// space o(n) stack
s 1 2 3 4 5
tail = s.top
pre = nullptr
while (!s.empty())
    auto cur = s.pop();
    if (pre) pre->next = cur;
    pre = cur;
    cur->next = null
return tail

// Solution3. Iteration without stack
// time o(n)
// space o(1)
use two pointers to change next
  1 2 3 4 5
p c n
  p c n
    p c n
      p c n
        p c n
c->p
p = c
c = n
n = n->next

*/

class Solution {
public:
    ListNode* reverseList_recursive(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return node;
        
        auto tail = reverseList_recursive(node->next);
        node->next->next = node;
        node->next = nullptr;
        return tail;
    }
    
    ListNode* reverseList_iteration(ListNode* node) {
        if (node == nullptr || node->next == nullptr) return node;
        
        ListNode* pre = nullptr;
        auto cur = node;
        while (cur) {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        return pre;
    }
    
    ListNode* reverseList(ListNode* head) {
        //return reverseList_recursive(head);
        return reverseList_iteration(head);
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
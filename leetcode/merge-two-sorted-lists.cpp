#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v)
    : val(v), next(NULL) {}
};

bool isEqual(ListNode* l, ListNode* r) {
    if (l != nullptr && r != nullptr) return (l->val == r->val && isEqual(l->next, r->next));
    return (l == nullptr && r == nullptr) ? true : false;
}

/**
https://leetcode.com/problems/merge-two-sorted-lists/

1 2 4
    l
1 3 4
      r
-----
1 1 2 3 4 ... l

Solution1. iterate l1, l2. and compare and add
time: o(max(m, n))
space: o(1)

ansDummy = new listnode;
cur = ansDummy;
while (l1 != NULL && l2 != NULL)
    if (l1->v > l2->v)
        cur->next = l2
        l2 = l2->next
    else
        cur->next = l1
        l1 = l1->next
    cur = cur->next
if (l1 != NULL) cur->next = l1
else cur->next = l2
return cur
**/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto ansDummy = new ListNode(-1);
        auto cur = ansDummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            }
            else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        if (l1 != NULL) cur->next = l1;
        else cur->next = l2;
        
        return ansDummy->next;
    }
};

int main()
{
    auto input1_1 = new ListNode(1);
    input1_1->next = new ListNode(2);
    input1_1->next->next = new ListNode(4);
    auto input1_2 = new ListNode(1);
    input1_2->next = new ListNode(3);
    input1_2->next->next = new ListNode(4);
    auto expected1 = new ListNode(1);
    expected1->next = new ListNode(1);
    expected1->next->next = new ListNode(2);
    expected1->next->next->next = new ListNode(3);
    expected1->next->next->next->next = new ListNode(4);
    expected1->next->next->next->next->next = new ListNode(4);
    assert(isEqual(Solution().mergeTwoLists(input1_1, input1_2), expected1));

    return 0;
}
#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/add-two-numbers/

// (2, 4, 3)
// (5, 6, 4)
// (7, 0, 7+1)
//     c=1
// Recursive(node r, node l, node r, c)
// v = l.v + r.v + c
// c = v > 10 ? 1 : 0;
// v = v % 10;
// Iterative()
// l(0) -> l(end)
// r(0) -> r(end)
// time: o(max(n,m))
// space: o(max(n,m))

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v)
    : val(v), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummyAns = new ListNode(-1);
        auto cur = dummyAns;

        int c = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int v = c;
            if (l1 != nullptr) {
                v += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                v += l2->val;
                l2 = l2->next;
            }

            c = v / 10;
            cur->next = new ListNode(v % 10);
            cur = cur->next;
        }

        if (c != 0)
            cur->next = new ListNode(c);

        return dummyAns->next;
    }
};

bool isEqual(ListNode* l, ListNode* r) {
    if (l != nullptr && r != nullptr) return (l->val == r->val && isEqual(l->next, r->next));
    return (l == nullptr && r == nullptr) ? true : false;
}

int main()
{
    auto input1_1 = new ListNode(2);
    input1_1->next = new ListNode(4);
    input1_1->next->next = new ListNode(3);
    auto input1_2 = new ListNode(5);
    input1_2->next = new ListNode(6);
    input1_2->next->next = new ListNode(4);
    auto expected1 = new ListNode(7);
    expected1->next = new ListNode(0);
    expected1->next->next = new ListNode(8);
    assert(isEqual(Solution().addTwoNumbers(input1_1, input1_2), expected1));

    return 0;
}
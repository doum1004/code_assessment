#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x, ListNode *next = nullptr)
    : val(x)
    , next (next)
    {

    }

    bool operator==(const ListNode& r) const
    {
        auto result = val == r.val;
        if (next != nullptr && r.next != nullptr)
        {
            result &= *next == *r.next;
        }
        else
        {
            result &= (next == nullptr && r.next == nullptr);
        }
        return result;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto dummy = new ListNode(0);
    auto l = l1;
    auto r = l2;
    auto cur = dummy;
    
    auto c = 0;
    while (l != nullptr || r != nullptr)
    {
        auto sum = c;
        if (l != nullptr)
        {
            sum += l->val;
            l = l->next;
        }
        if (r != nullptr)
        {
            sum += r->val;
            r = r->next;
        }

        c = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
    }

    if (c != 0)
        cur->next = new ListNode(c);

    return dummy->next;
}

int main()
{
    assert(*addTwoNumbers(
        new ListNode(2, new ListNode(4, new ListNode(3))),
        new ListNode(5, new ListNode(6, new ListNode(4))))
        == *(new ListNode(7, new ListNode(0, new ListNode(8)))));

    assert(*addTwoNumbers(
        new ListNode(2, new ListNode(4, new ListNode(3))),
        new ListNode(5, new ListNode(6, new ListNode(4))))
        == *(new ListNode(7, new ListNode(0, new ListNode(8)))));
    assert(*addTwoNumbers(
        new ListNode(5),
        new ListNode(5))
        == *(new ListNode(0, new ListNode(1))));
    assert(*addTwoNumbers(
        new ListNode(1, new ListNode(8)),
        new ListNode(0))
        == *(new ListNode(1, new ListNode(8))));
    return 0;
}
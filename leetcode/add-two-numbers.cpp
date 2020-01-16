#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

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
        new ListNode(5),
        new ListNode(5))
        == *(new ListNode(0, new ListNode(1))));
    assert(*addTwoNumbers(
        new ListNode(1, new ListNode(8)),
        new ListNode(0))
        == *(new ListNode(1, new ListNode(8))));
    return 0;
}
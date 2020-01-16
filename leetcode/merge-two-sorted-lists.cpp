#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/

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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // recursion
    if (l1 == nullptr)
    {
        return l2;
    }
    else if (l2 == nullptr)
    {
        return l1;
    }
    else if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode* mergeTwoLists_Iteration(ListNode* l1, ListNode* l2) {
    // iteration
    auto ans_dummy = new ListNode(0);
    auto cur = ans_dummy;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
        {
            cur->next = l1;
            if (l1 != nullptr) l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            if (l2 != nullptr) l2 = l2->next;
        }
        cur = cur->next;
    }
    
    cur->next = l1 == nullptr ? l2 : l1;

    return ans_dummy->next;
}

int main()
{
    assert(*mergeTwoLists(
        new ListNode(1, new ListNode(2, new ListNode(4))),
        new ListNode(1, new ListNode(3, new ListNode(4))))
        == *(new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4))))))));
    return 0;
}
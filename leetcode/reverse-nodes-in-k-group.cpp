#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
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

// iterative
// points and swap
// time: o(n)
// space: o(1)
// dummy   1 2 3 4 5
//  k(3)
//   h     c n t
// hn = h->next
// h->next = n
// n->next = hn
// c->next = t

// dummy   2 1 3 4 5
//   h       c n t
// hn = h->next
// h->next = n
// n->next = hn
// c->next = t

// dummy   3 2 1 4 5 
//   h         c n t
//             h c n t 

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto n = 0;
        auto cur = head;
        while (cur != nullptr) {
            n++;
            cur = cur->next;
        }

        auto dummyHead = new ListNode(-1);
        dummyHead->next = head;

        auto pre = dummyHead;
        while (n >= k) {
            for (int i=1; i<k; ++i) {
                auto n = head->next;
                auto t = n->next;

                auto pre_next = pre->next;
                pre->next = n;
                n->next = pre_next;
                head->next = t;
            }
            n -= k;
            pre = head;
            head = pre->next;
        }

        return dummyHead->next;
    }
};

int main()
{
    auto input1_1 = new ListNode(1);
    input1_1->next = new ListNode(2);
    input1_1->next->next = new ListNode(3);
    input1_1->next->next->next = new ListNode(4);
    input1_1->next->next->next->next = new ListNode(5);
    auto expected1 = new ListNode(2);
    expected1->next = new ListNode(1);
    expected1->next->next = new ListNode(4);
    expected1->next->next->next = new ListNode(3);
    expected1->next->next->next->next = new ListNode(5);
    assert(isEqual(Solution().reverseKGroup(input1_1, 2), expected1));
    return 0;
}
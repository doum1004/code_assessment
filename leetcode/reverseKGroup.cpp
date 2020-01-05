#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
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

// -1                    1     2     3     4    5
// prehead  pre         head
// k(4)
// j(1)
// temp = 1 (pre->next)
// -1(pre)      -> 2 (head->next)
// 2(pre->next) -> temp(1)
// 1(head)      -> 3 (head->next->next)
// -1                    2     1     3     4    5
// prehead  pre               head
// j(2)
// temp = 2 (pre->next)
// -1(pre)      -> 3 (head->next)
// 3(pre->next) -> temp(2)
// 1(head)      -> 4 (head->next->next)
// -1                    3     2     1     4    5
// prehead  pre                     head
// j(3)
// temp = 3 (pre->next)
// -1(pre)      -> 4 (head->next)
// 1(head)      -> 5 (head->next->next)
// 4(pre->next) -> temp(3)
// -1                    4     3     2     1    5
// prehead  pre                           head

// prehead                                 pre  head


ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) return head;

    auto cur = head;
    auto num = 0;
    while (cur != nullptr)
    {
        num++;
        cur = cur->next;
    }

    auto prehead = new ListNode(-1);
    prehead->next = head;

    auto pre = prehead;
    while (num >= k) {
        for (int i=1; i<k; i++) {
            auto a = pre->next;
            auto b = head->next;
            auto c = head->next->next;
            pre->next = b;
            b->next = a;
            head->next = c;
        }
        num -= k;
        pre = head;
        head = head->next;
    }

    return prehead->next;
}

int main()
{
    assert(*reverseKGroup(
        new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))),
        2)
        == *(new ListNode(2, new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(5)))))));
    assert(*reverseKGroup(
        new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))),
        3)
        == *(new ListNode(3, new ListNode(2, new ListNode(1, new ListNode(4, new ListNode(5)))))));
    return 0;
}
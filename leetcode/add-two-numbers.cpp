#include <iostream>
#include <vector>
#include <cassert>
#include "../listnode.h"

using namespace std;

// https://leetcode.com/problems/add-two-numbers/

/**
iterate both LinkedList. Add sum on ans. And carry if sum exceed 9
time: o(max(n,m))
space: o(max(n,m))

    2 4 3
    5 6 4
---------
    7 0 8
  c     1

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto ansDummy = new ListNode(-1);
        auto cur = ansDummy;
        auto c = 0;
        while (l1 != nullptr || l2 != nullptr) {
            auto sum = c;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            c = sum >= 10 ? 1 : 0;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        if (c != 0)
            cur->next = new ListNode(c);
        
        return ansDummy->next;
    }
};

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
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

/*
https://leetcode.com/problems/merge-two-sorted-lists

Solution1. iterate with sorted vector
time: o(n)
space: o(n)

solution2. iterate without sorted vector
time: o(n)
space: o(1)

solution3. recursive
time: o(n)
space: o(n)


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists_2(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        if (list1) cur->next = list1;
        else cur->next = list2;

        return dummy->next;        
    }

    ListNode* mergeTwoLists_3(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists_3(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists_3(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return mergeTwoLists_2(list1, list2);
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
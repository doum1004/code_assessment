#include <iostream>
#include <cassert>

#include <vector>
#include <stack>
#include <unordered_set>

#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/intersection-of-two-linked-lists/

// Solution1. set for visited v1, v2
// time: o(n + m)
// space: o(n or m)

// Solution2. two pointers. check total nums of each. and move one till diff and traverse to compare to find same node
// time: o(n + m)
// space: o(1)

*/
class Solution {
public:
    ListNode *getIntersectionNode_hash(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> v;
        
        while (headA != nullptr) {
            v.insert(headA);
            headA = headA->next;
        }
        
        while (headB != nullptr) {
            if (v.find(headB) != v.end()) return headB;
            headB = headB->next;
        }
        
        return nullptr;
    }
    
    ListNode *getIntersectionNode_diff(ListNode *headA, ListNode *headB) {
        auto diffcnt = 0;
        auto curA = headA;
        auto curB = headB;
        while (curA != nullptr || curB != nullptr) {
            if (curA == nullptr || curB == nullptr) {
                if (curA == nullptr) diffcnt--;
                else diffcnt++;
            }
            if (curA != nullptr) curA = curA->next;
            if (curB != nullptr) curB = curB->next;
        }
        
        while (headA != nullptr && headB != nullptr) {
            if (abs(diffcnt) != 0) {
                if (diffcnt < 0) {
                    headB = headB->next;
                    diffcnt++;
                }
                else {
                    headA = headA->next;
                    diffcnt--;
                }
            }
            else {
                if (headA == headB) return headA;
                headA = headA->next;
                headB = headB->next;
            }
        }
        
        return nullptr;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //return getIntersectionNode_hash(headA, headB);
        return getIntersectionNode_diff(headA, headB);
    }
};

int main()
{
    auto input1_1 = new ListNode(4);
    input1_1->next = new ListNode(1);
    input1_1->next->next = new ListNode(8);
    input1_1->next->next->next = new ListNode(4);
    input1_1->next->next->next->next = new ListNode(5);

    auto input1_2 = new ListNode(5);
    input1_2->next = new ListNode(0);
    input1_2->next->next = new ListNode(1);
    input1_2->next->next->next = input1_1->next->next;
    assert(Solution().getIntersectionNode(input1_1, input1_2)
        == (input1_1->next->next));

    return 0;
}
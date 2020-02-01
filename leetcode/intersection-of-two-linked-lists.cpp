#include <iostream>
#include <cassert>

#include <vector>
#include <stack>
#include <unordered_set>

#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/intersection-of-two-linked-lists/

// Solution1. hash for visited (two hash)
// time: o(n + m)
// space: o(n + m)

// Solution2. two pointers. find size diffrence.
// Make a pointer wait till the size diff and traverse to find matched one.
// time: o(n + m)
// space: o(1)

a b c d e : 5
  e c d e : 4
p1(p2 wait for 1 which is diff of 5 and 4)
  p1
  p2

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
        if (headA == headB) return headA;
        
        int na = 0;
        int nb = 0;
        auto curA = headA;
        auto curB = headB;
        while (curA || curB) {
            if (curA) {
                na++;
                curA = curA->next;
            }
            if (curB) {
                nb++;
                curB = curB->next;
            }
        }
        
        curA = headA;
        curB = headB;
        for (int i=0; i<abs(na-nb); ++i) {
            if (na > nb) curA = curA->next;
            else curB = curB->next;
        }
        
        while (curA && curB) {
            if (curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
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
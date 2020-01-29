#include <iostream>
#include <cassert>

#include <vector>
#include <stack>
#include <unordered_set>

#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/linked-list-cycle/

// Solution1. Iteration. Hashmap to check visited
// time: o(n)
// space: o(n)

// how to improve to space: o(1)?
// Soultion2. Iteration. Two points. slow and fast. If there is cycle eventually they will meet in some point.
// time: o(n) : o(n + k) none cyclic length n + cyclic length K (fast will follow up)
// space: o(1)

*/
class Solution {
public:
    bool hasCycle_solution1(ListNode *head) {
        unordered_set<ListNode *> v;
        while (head != nullptr) {
            if (v.find(head) != v.end()) return true;
            v.insert(head);
            head = head->next;
        }
        return false;
    }
    
    bool hasCycle_solution2(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
    
    bool hasCycle(ListNode *head) {
        //return hasCycle_solution1(head);
        return hasCycle_solution2(head);
    }
};

int main()
{
    auto input1 = new ListNode(3);
    input1->next = new ListNode(2);
    input1->next->next = new ListNode(0);
    input1->next->next->next = new ListNode(-4);
    input1->next->next->next->next = input1->next;

    assert(Solution().hasCycle(input1)
        == (true));
    return 0;
}
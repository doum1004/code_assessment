#include <iostream>
#include <cassert>

#include <vector>
#include <stack>
#include <unordered_set>

#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/linked-list-cycle/

// Solution1. hash map to check visited
// time: o(n)
// space: o(n)

// Solution2. two pointer slow, fast
// time: o(n) : n + k (none cyclic length n + cyclic length k)
// space: o(1)
slow -> step 1
fast -> step 2
3 | 2 0 4 2 0 4 2 0 4 2 0 4
s   s s s s(!)
f     f     f   f(!)

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
        if (!head) return false;
        
        auto slow = head;
        auto fast = head;
        while (fast->next && fast->next->next) {
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
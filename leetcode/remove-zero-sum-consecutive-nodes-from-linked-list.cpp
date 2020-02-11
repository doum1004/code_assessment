#include <iostream>
#include <cassert>

#include <unordered_map>

#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
 
// Solution1. One pass
// time: o(n) : n + m(number of sum 0)
// space: o(n) : map

1. add dummy node
2. iterate from dummy to end
3. accumulate val in sum
4. if cur sum isn't in map, add it
5. else erase nodes in between, and relink node

1)
 0 | 1 2 -3 3 1
 0   1 3  0

 0 | 3 1
 0   3 4
2)
 0 | 1,2,3,-3,4
 0   1 3 6  3

 0 | 1 2 4
 0   1 3 7
3)
 0 | 1,2,3,-3,-2
 0   1 3 6  3

 0 | 1 2 -2
 0 | 1 3  1

 0 | 1
 0 | 1
 
// Solution2. Two passes
// time: o(n) : n + n
// space: o(n) : map

1. add dummy node
2. first iteration. put it in map (if the sum exist, it will be replace by new one)
3. second iteration. iterate again and relink

1)
first iteration
 0 | 1 2 -3 3 1
 0   1 3  0 3 4 (map)
second iteration
 0 | 1 2 -3 3 1
 0   1 3  0 3 4
       2------1


 */
class Solution {
public:
    ListNode* removeZeroSumSublists_onepass(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto cur = dummy;

        unordered_map<int, ListNode*> m;
        int sum = 0;
        while (cur) {
            sum += cur->val;
            if (m.count(sum)) {
                cur = m[sum]->next;
                int p = sum + cur->val;
                while (p != sum) {
                    m.erase(p);
                    cur = cur->next;
                    p += cur->val;
                }
                m[sum]->next = cur->next;
            }
            else {
                m[sum] = cur;
            }
            cur = cur->next;
        }

        return dummy->next;
    }
    
    ListNode* removeZeroSumSublists_twopass(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        
        unordered_map<int, ListNode*> m;
        auto cur = dummy;
        int sum = 0;
        while (cur) {
            sum += cur->val;
            m[sum] = cur;
            cur = cur->next;
        }
        
        cur = dummy;
        sum = 0;
        while (cur) {
            sum += cur->val;
            cur->next = m[sum]->next;
            cur = cur->next;
        }
        
        return dummy->next;
    }
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        //return removeZeroSumSublists_onepass(head);
        return removeZeroSumSublists_twopass(head);
    }
};

int main()
{
    auto input1_1 = new ListNode(1);
    input1_1->next = new ListNode(2);
    input1_1->next->next = new ListNode(-3);
    input1_1->next->next->next = new ListNode(3);
    input1_1->next->next->next->next = new ListNode(1);

    auto expect1 = new ListNode(3);
    expect1->next = new ListNode(1);
    assert(isEqual(Solution().removeZeroSumSublists(input1_1), expect1));

    return 0;
}
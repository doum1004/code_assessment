#include <iostream>
#include <cassert>

#include <unordered_map>

#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// Solution1. brute force with two pointers (98%, 100%)
// time: o(n^2)
// space: o(1)
1. itreate two passes. one from head to last. second from head->next to last.
2. if sum of second iteration is zero, relink and reset sum.

    1 2 -3 3 1 (#pre, *cur)
  # * sum=1
  #   * sum=3
  #      * sum=0. relink
    3 1
  # * sum=3
  #   * sum=4
    # * sum=1
      # * 
      
// Solution2. one pass with map
// time: o()
1. add dummy node and unordered_map<int, node*>
2. iterate from dummy to end
3. accumulate sum, if sum not exist, add it in map with cur pointer
4. if exist, erase node and map in between

ex 1)
    dummy 1 2 -3 3 1
map     0 1 3  0    
    dummy 3 1
        0 3 4

ex 2)
    dummy 1,2,3,-3,4
map     0 1 3 6  3    
    dummy 1 3 4
        0 1 3 7
        
// Solution3. two passes with map
1. add dummy node and unordered_map<int, node*>
2. iterate from dummy to store acuumulate sum and node (last node will be stored)
3. iterate from dummy again, if accumulated sum exist in map

ex 1)
    dummy 1 2 -3 3 1
map     0 1 3  0 3 1
    dummy 1 2 -3 3 1
    sum 0 1 3 ---->4




    
*/
class Solution {
public:
    ListNode* removeZeroSumSublists_bruteforce(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        
        auto pre = dummy;
        while (pre) {
            auto cur = pre->next;
            int sum = 0;
            while (cur) {
                sum += cur->val;
                if (sum == 0) {
                    pre->next = cur->next;
                    sum = 0;
                }
                cur = cur->next;
            }
            pre = pre->next;
        }
        
        return dummy->next;
    }
    
    ListNode* removeZeroSumSublists_onepass_map(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        
        unordered_map<int, ListNode*> m;
        auto cur = dummy;
        int sum=0;
        while (cur) {
            sum += cur->val;
            if (!m.count(sum)) {
                m[sum] = cur;
            }
            else {
                auto p = m[sum]->next;
                auto p_val = sum;
                while (p != cur) { //erase map
                    p_val += p->val;
                    m.erase(p_val);
                    p = p->next;
                }
                m[sum]->next = cur->next;
            }
            
            cur = cur->next;
        }
        
        return dummy->next;
    }
    
    ListNode* removeZeroSumSublists_twopass_map(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        
        unordered_map<int, ListNode*> m;
        auto cur = dummy;
        int sum=0;
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
        //return removeZeroSumSublists_bruteforce(head);
        //return removeZeroSumSublists_onepass_map(head);
        return removeZeroSumSublists_twopass_map(head);
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
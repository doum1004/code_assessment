#include <iostream>
#include <vector>
#include <cassert>
#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// solution1. two pointers
// time: o(n)
// space: o(1)
1. two pointers. one for wait n times
2. once fast pointer arrives, relink to remove the target

n=2
  2. 1  0
  1->2->3->4->5
        s
              f

// solution2. one pointers
// time: o(n)
// space: o(1)
1. get total count
2. iterate till total - n
3. relink to remove next cur->next = cur->next->next

d 1 2 3 4 5
      *

*/
class Solution {
public:
    ListNode* removeNthFromEnd_twopointers(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        
        auto slow = dummy;
        head = dummy;
        while (head->next) {
            if (n-- <= 0) slow = slow->next;
            head = head->next;
        }
        
        if (slow && slow->next) {
            auto debedelted = slow->next;
            slow->next = debedelted->next;
            delete debedelted;
        }
        
        return dummy->next;
    }
    
    ListNode* removeNthFromEnd_onepointer(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        
        head = dummy;
        for (int i=1; i<=count-n; ++i) {
            if (!head) break;
            head = head->next;
        }
        
        if (head && head->next){
            auto debedelted = head->next;
            head->next = head->next->next;
            delete debedelted;
        } 
        
        return dummy->next;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //return removeNthFromEnd_twopointers(head, n);
        return removeNthFromEnd_onepointer(head, n);
    }
};

int main()
{
    auto input1_1 = new ListNode(1);
    input1_1->next = new ListNode(2);
    input1_1->next->next = new ListNode(3);
    input1_1->next->next->next = new ListNode(4);
    input1_1->next->next->next->next = new ListNode(5);
    auto expected1 = new ListNode(1);
    expected1->next = new ListNode(2);
    expected1->next->next = new ListNode(3);
    expected1->next->next->next = new ListNode(5);
    //auto ans = Solution().removeNthFromEnd(input1_1, 2);
    assert(isEqual(Solution().removeNthFromEnd(input1_1, 2), expected1));

    return 0;
}
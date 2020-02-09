#include <iostream>
#include <vector>
#include <cassert>
#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Solution1. Two path
// time: o(n)
// space: o(1)
1. one pass goes first and after n the other pass goes
2. when a first pass the end, do remove next of the other pass

  1 2 3 4 5 (n=2)
      s
          f
          
// Solution2. one path
// time: o(n) n+n-t
// space: o(1)
1. count number of node
2. diff count - target
3. travel in diff and remove item

*/
class Solution {
public:
    ListNode* removeNthFromEnd_twopass(ListNode* head, int n) {
        if (n < 0) return head;
        auto prehead = new ListNode(-1);
        prehead->next = head;
        auto fast = prehead;
        auto slow = prehead;
        int i = 0;
        while (fast->next) {
            if (i++ >= n) slow = slow->next;
            fast = fast->next;
        }
        // remove next of slow
        if (head && head->next) {
            auto tobedeleted = head->next;
            head->next = head->next->next;
            delete tobedeleted;
        }
        
        return prehead->next;
    }
    
    ListNode* removeNthFromEnd_onepass(ListNode* head, int n) {
        if (n < 0) return head;
        
        auto prehead = new ListNode(-1);
        prehead->next = head;
        head = prehead;
        
        int count = 0;
        while (head->next) {
            count++;
            head = head->next;
        }
        
        head = prehead;
        int diff = count - n;
        while (--diff >= 0) {
            head = head->next;
        }
        if (head && head->next) {
            auto tobedeleted = head->next;
            head->next = head->next->next;
            delete tobedeleted;
        }
        
        return prehead->next;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //return removeNthFromEnd_twopass(head, n);
        return removeNthFromEnd_onepass(head, n);
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
#include <iostream>
#include <vector>
#include <cassert>
#include "../listnode.h"

using namespace std;

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
 /*
 https://leetcode.com/problems/remove-nth-node-from-end-of-list

 Solution1. iterate once + extra space
 time: o(n)
 space: o(n)

 Solution2. Iterate twice
 time: o(n): n+n
 space: o(1)

 Solution3. Iterate once (two pointers)
 time: o(n)
 space: o(1)

 d   1 2 3 4 5 (1)
 s,f
 s   f
           s f(x)
 
 d   1 2 3 4 5 (3)
 s,f
 s       f
       s x   f

 Solution4. Iterate once (one pointer)
 time: o(n)
 space: o(1)
 */
class Solution {
public:
    ListNode* removeNthFromEnd_1(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        auto cur = dummy;

        vector<ListNode*> list;
        while (cur) {
            list.push_back(cur);
            cur = cur->next;
        }

        int i = list.size() - n;
        if (i >= 1) {
            list[i-1]->next = list[i]->next;
            //delete list[i]; list[i] = nullptr;
        }
        return dummy->next;
    }

    ListNode* removeNthFromEnd_2(ListNode* head, int n) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto pre = dummy;
        int total = 0;
        while (pre->next) {
            total++;
            pre = pre->next;
        }

        pre = dummy;
        while (pre->next) {
            if (--total < n)
                break;
            pre = pre->next;
        }
        //auto tobeDeleted = pre->next;
        pre->next = pre->next->next;
        //delete tobeDeleted; tobeDeleted = nullptr;
        return dummy->next;
    }

    ListNode* removeNthFromEnd_3(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy, *fast = dummy;
        while (n--) fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        //auto tobeDeleted = slow->next;
        slow->next = slow->next->next;
        //delete tobeDeleted; tobeDeleted = nullptr;
        return dummy->next;
    }

    ListNode* removeNthFromEnd_4(ListNode* head, int n) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }

        head = dummy;
        for (int i=1; i<=cnt-n; ++i) {
            if (!head) break;
            head = head->next;
        }

        head->next = head->next->next;
        return dummy->next;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNthFromEnd_4(head, n);
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
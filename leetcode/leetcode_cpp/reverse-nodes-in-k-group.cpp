#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
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

/**
https://leetcode.com/problems/reverse-nodes-in-k-group

Iterate and swap
time: o(n)
space: o(1)

h 1 2 3 4 5
h 2 1 4 3 5 k = 2
h 3 2 1 4 5 k = 3

     1 2 3 4 5
preh c n nn 
1) preh -> 2, 2 -> 1, 1 -> 3
     2 1 3 4 5
preh   c n nn
2) preh -> 3, 3 -> 2, 1 -> 4
     3 2 1 4 5
preh     c n nn

while (num >= k)
    for (int=1; i=k)
        ph 1 2 3 4 5
           c n nn
        1) ph -> n, n -> hn, c -> nn
        ph 2 1 3 4 5
             c n nn
        2) ph -> n, n -> hn, c -> nn
        ph  3 2 1 4 5
                c n nn
    
    3 2 1 4 5
    ph c n nn
    n-=k

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // get nb nodes o(n)
        int num = 0;
        auto cur = head;
        while (cur) {
            num++;
            cur = cur->next;
        }
        
        // iternate and reverse o(n)
        auto ansDummy = new ListNode();
        ansDummy->next = head;
        
        auto pre = ansDummy;
        while (num >= k) {
            for (int i=0; i<k-1; ++i) {
                auto pre_next = pre->next;
                auto head_next = head->next;
                auto head_next_next = head_next->next;
                pre->next = head_next;
                head_next->next = pre_next;
                head->next = head_next_next;
            }
            pre = head;
            head = head->next;
            
            num -= k;
        }
        
        return ansDummy->next;
    }
};

int main()
{
    auto input1_1 = new ListNode(1);
    input1_1->next = new ListNode(2);
    input1_1->next->next = new ListNode(3);
    input1_1->next->next->next = new ListNode(4);
    input1_1->next->next->next->next = new ListNode(5);
    auto expected1 = new ListNode(2);
    expected1->next = new ListNode(1);
    expected1->next->next = new ListNode(4);
    expected1->next->next->next = new ListNode(3);
    expected1->next->next->next->next = new ListNode(5);
    assert(isEqual(Solution().reverseKGroup(input1_1, 2), expected1));
    return 0;
}

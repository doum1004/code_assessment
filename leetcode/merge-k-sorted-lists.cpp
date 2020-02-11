#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/merge-k-sorted-lists/

// solution1. add all node in vector and sort and make list again
// time: o(nlogn)
// space: o(1) use pointer (no extra mem)

// solution2. (reduce space) min-heap
// time: o(nlogn) n*logn
// space: o(1) use pointer (no extra mem)

*/

class Solution {
public:
    ListNode* mergeKLists_sort(vector<ListNode*>& lists) {
        vector<ListNode*> nodes;
        for (auto &node:lists) {
            while (node) {
                nodes.push_back(node);
                node = node->next;
            }
        }
        sort(nodes.begin(), nodes.end(), [&](auto &l, auto &r) {
            return l->val < r->val;
        });
        
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        for (auto &node:nodes) {
            cur->next = node;
            cur = cur->next;
            cur->next = nullptr;
        }
        
        return dummy->next;
    }
    
    struct compare_greater {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
    ListNode* mergeKLists_heap(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare_greater> q;
        for (auto &node:lists) {
            while (node) {
                q.push(node);
                node = node->next;
            }
        }
        
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            cur->next = nullptr;
        }
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists_sort(lists);
        //return mergeKLists_heap(lists);
    }
};

int main()
{
    auto input1_1 = new ListNode(1);
    input1_1->next = new ListNode(4);
    input1_1->next->next = new ListNode(5);
    auto input1_2 = new ListNode(1);
    input1_2->next = new ListNode(3);
    input1_2->next->next = new ListNode(4);
    auto input1_3 = new ListNode(2);
    input1_3->next = new ListNode(6);
    auto input1 = vector<ListNode*> {input1_1, input1_2, input1_3};

    auto ans = Solution().mergeKLists(input1);
    assert(ans->val == 1);
    assert(ans->next->next->val == 2);
    assert(ans->next->next->next->next->val == 4);
    return 0;
}
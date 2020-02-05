#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include "../listnode.h"

using namespace std;

/**
https://leetcode.com/problems/merge-k-sorted-lists/

// Solution1. brute force iterate each one and find the position
// time: o(n^2)
// space: o(1)

// Solution2. brute force. save all val in vector. and sort. and put it in new list
// time: o(nlogn)
// space: o(n)

// Solution3. Put all head in min heap(priority queue) and take the top
// time: o(nlogn) : n * insert/pop(logn)
// space: o(1) : no copy

*/
class Solution {
public:
    ListNode* mergeKLists_bruteforce(vector<ListNode*>& lists) {
        auto ansDummy = new ListNode(-1);
        for (auto &node:lists) {
            if (ansDummy->next == nullptr) {
                ansDummy->next = node;
            }
            else {
                while (node) {
                    auto next = node->next;
                    
                    auto pre = ansDummy;
                    auto ansNode = pre->next;
                    while (ansNode) {
                        if (ansNode->val > node->val) break;
                        pre = ansNode;
                        ansNode = ansNode->next;
                    }
                    auto t = pre->next;
                    pre->next = node;
                    node->next = t;
                    
                    node = next;
                }
            }
        }
        return ansDummy->next;
    }
    
    ListNode* mergeKLists_sort(vector<ListNode*>& lists) {
        vector<int> sorted;
        for (auto &n:lists) {
            while (n) {
                sorted.push_back(n->val);
                n = n->next;
            }
        }
        
        sort(sorted.begin(), sorted.end());
        
        auto ansDummy = new ListNode(-1);
        auto cur = ansDummy;
        for (auto &v:sorted) {
            cur->next = new ListNode(v);
            cur = cur->next;
        }
        
        return ansDummy->next;
    }
    
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
    ListNode* mergeKLists_pointer(vector<ListNode*>& lists) {
        auto ansDummy = new ListNode(-1);
        
        priority_queue<ListNode*, vector<ListNode*>, compare> q; //min-heap
        for (auto &n:lists) {
            while (n) {
                q.push(n);
                n = n->next;
            }
        }
        
        auto cur = ansDummy;
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            cur->next = nullptr;
        }
        
        return ansDummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //return mergeKLists_bruteforce(lists);
        //return mergeKLists_sort(lists);
        return mergeKLists_pointer(lists);
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
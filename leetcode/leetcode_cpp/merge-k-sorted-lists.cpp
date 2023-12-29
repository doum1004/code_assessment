#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
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
 https://leetcode.com/problems/merge-k-sorted-lists
 
solution1. add all node in vector and sort and make list again
time: o(nlogn)
space: o(1) use pointer (no extra mem)

solution2. (reduce space) min-heap
time: o(nlogn) n*logn
space: o(1) use pointer (no extra mem)

Solution3. Divide and Conquer
time: o(nlogn)
space: o(n) recursive call
*/
class Solution {
public:
    ListNode* mergeKLists_1(vector<ListNode*>& lists) {
        vector<ListNode*> v;
        for (auto node : lists) {
            while (node) {
                v.push_back(node);
                node = node->next;
            }
        }

        sort(v.begin(), v.end(), [](ListNode* l, ListNode* r){
            return l->val < r->val;
        });
        auto dummy = new ListNode(0);
        auto cur = dummy;
        for (auto next : v) {
            cur->next = next;
            cur = next;
            cur->next = nullptr;
        }
        return dummy->next;
    }
    
    struct compare_greater {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

    ListNode* mergeKLists_2(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare_greater> q;
        for (auto node : lists) {
            while (node) {
                q.push(node);
                node = node->next;
            }
        }

        auto dummy = new ListNode(0);
        auto cur = dummy;
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            cur->next = nullptr;
        }
        return dummy->next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    
    ListNode* partition(vector<ListNode*>& lists, int start, int end) {
        if (start == end) return lists[start];
        if (start < end) {
            int mid = (end+start) / 2;
            ListNode* l1 = partition(lists, start, mid);
            ListNode* l2 = partition(lists, mid+1, end);
            return merge(l1, l2);
        }
        return nullptr;
    }
    
    ListNode* mergeKLists_3(vector<ListNode*>& lists) {
        if (lists.size() == 1) return lists[0];
        if (lists.size() == 0) return nullptr;
        return partition(lists, 0, lists.size()-1);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists_3(lists);
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
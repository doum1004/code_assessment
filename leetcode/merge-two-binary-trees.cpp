#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/merge-two-binary-trees/
Merge Bin tree

// two ways. create new or use exist t1

// Recursive DSF preorder
// time: o(n)
// space: o(n) : avg(logn)
    if t1 == nullptr return t1
    if t2 == nullptr return t1
    t1->val += t2->val
    t1->left = merge(t1->left, t2->left)
    t1->right = merge(t1->right, t2->right)
    return t1

// Iteration DSF
// time: o(n)
// space: o(n) : avg(logn)
queue: (1 2)
queue: (3,1), (2,3)
queue: null, 7

if (t1 == null) t1 = t2 return t1
if (t2 == null) reutnr t1

q push {t1, t2}
while (q)
l = q.front.frist
r = q.front.second

l->val += r->val

if both left are not empty queue.push
else if l.left empty left = r.left


q({t1, t2})
while (!q.empty())
    auto cur = q.front()
    auto l = cur.first
    auto r = cur.second
    q.pop()
    
    if (l->left && r->left) {
        q.push({l1})
    }
    else 
    
*/

class Solution {
public:
    TreeNode* mergeTrees_recursive(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        
        if (t2 == nullptr) {
            return t1;
        }
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({t1, t2});
        while (!q.empty()) {
            auto l = q.front().first;
            auto r = q.front().second;
            q.pop();
            
            l->val += r->val;
            if (l->left != nullptr && r->left != nullptr) {
                q.push({l->left, r->left});
            }
            else if (l->left == nullptr) {
                l->left = r->left;
            }
            
            if (l->right != nullptr && r->right != nullptr) {
                q.push({l->right, r->right});
            }
            else if (l->right == nullptr) {
                l->right = r->right;
            }
        }
        return t1;
    }
};

int main()
{
    auto input1_1 = new TreeNode(1);
    input1_1->left = new TreeNode(3);
    input1_1->right = new TreeNode(2);
    input1_1->left->left = new TreeNode(5);
    auto input1_2 = new TreeNode(2);
    input1_2->left = new TreeNode(1);
    input1_2->right = new TreeNode(3);
    input1_2->left->right = new TreeNode(4);
    input1_2->right->right = new TreeNode(7);
    auto ans = Solution().mergeTrees(
        input1_1, input1_2);
    assert(ans->val == 3);
    assert(ans->left->right->val == 4);
    return 0;
}
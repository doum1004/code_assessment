#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/binary-tree-inorder-traversal/

// Solution1. Recursion DSF inorder
// time: o(n)
// space: o(n) : recursion, ans
r(node)
    if (!node) return
    r(node->left)
    ans.push_back(node->val)
    r(node->right)

// Solution2. Iteration DSF inorder with stack
// time: o(n)
// space: o(n) : stack, ans
1. traverse by cur and stack
2. put all left in stack from cur. (cur = cur->left)
3. if cur is empty then, take out node from stack. put ans and go right
stack s
cur = root
while (cur || !s.empty())
    if (cur)
        s.push(cur)
        cur = cur->left
    else
        cur = s.pop()
        ans.push(cur->val)
        cur = cur->right


// Solution3. Iteration Morris Treversal (move a tree to the right most of children)
// time: o(n)
// space: o(n) : ans
traverse
1. if there is left node
    1.1. go to left of node
    1.2. find right most node of left node
    1.3. move the node on the right most of right
    1.4. cur = node.left. remove left of node.
2. put val in ans
3. move to right

auto cur = root
while (cur)
    if (cur->left)
        pre = cur->left
        while (pre->right)
            pre = pre->right
        pre->right = cur
        t = cur
        cur = cur->left
        t->left = null
    else
        ans.push(cur->val)
        cur = cur->right
        
**/

class Solution {
public:
    void recursion(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        
        recursion(node->left, ans);
        ans.push_back(node->val);
        recursion(node->right, ans);
    }
    
    vector<int> inorderTraversal_recursion(TreeNode* root) {
        vector<int> ans;
        recursion(root, ans);
        return ans;
    }
    
    vector<int> inorderTraversal_iteration(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        stack<TreeNode*> s;
        auto cur = root;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                cur = s.top();
                s.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        return ans;
    }
    
    vector<int> inorderTraversal_morris(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        auto cur = root;
        while (cur) {
            if (cur->left) {
                auto pre = cur->left;
                while (pre->right)
                    pre = pre->right;
                pre->right = cur;
                auto t = cur;
                cur = cur->left;
                t->left = nullptr;
            }
            else {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        //return inorderTraversal_recursion(root);
        //return inorderTraversal_iteration(root);
        return inorderTraversal_morris(root);
    }
};

int main()
{
    auto input1 = new TreeNode(1);
    input1->right = new TreeNode(2);
    input1->right->left = new TreeNode(3);
    auto expect1 = vector<int> {1,3,2};
    assert(Solution().inorderTraversal(input1)
        == (expect1));

    return 0;
}

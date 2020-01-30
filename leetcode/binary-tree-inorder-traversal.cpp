#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/binary-tree-inorder-traversal/

DSF inorder traversal
// Solution1. recursion
// time: o(n)
// space: o(n)
r(node, &ans)
    if (!node) return
    r(node->left)
    ans.push_back(left->val);
    r(node->right)
    
// Solution2. Iteration
// 2.1  using stack and visited
// time: o(n)
// space: o(n): stack(n) + visited(n)
1. put root in stack
2. iterate stack till empty
    2.1 take stack top as node
    2.2 if node isn't visited and has left node, push left and makr as visited
    2.3 else pop stack. add ans and push right
    
// 2.2 using stack and cur
// time: o(n)
// space: o(n) : stack
1. cur = root
2. while cur || !s.empty()
    2.1 while cur { s.push(cur) cur = cur->left }
    2.2 node = s.pop() ans.push(node->val) cur = cur->right
    
    
// Solution3. Morris Traversal
// time: o(n)
// space: o(1) except ans
1. cur = rot, pre = null
2. while (cur)
  2.1 if !cur.left : add ans; cur = cur.right
  2.2 else
    2.2.1 pre = cur.left
    2.2.2 while pre.right // the most right
        2.2.2.1 pre = pre.right
    2.2.3 pre.right = cur //put cur to right most
    2.2.4 temp = cur // move cur as cur left and remove cur.left
    2.2.5 cur = cur.left
    2.2.6 cur.left = null

*/
class Solution {
public:
    void recursionBSF(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        recursionBSF(node->left, ans);
        ans.push_back(node->val);
        recursionBSF(node->right, ans);
    }
    
    vector<int> inorderTraversal_recursion(TreeNode* root) {
        vector<int> ans;
        recursionBSF(root, ans);
        return ans;
    }
    
    vector<int> inorderTraversal_iteration(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        stack<TreeNode*> s;
        auto cur = root;
        while (cur != nullptr || !s.empty()) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        /**
        unordered_set<TreeNode*> v;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            if (v.find(node) == v.end() && node->left) {
                v.insert(node);
                s.push(node->left);
            }
            else {
                s.pop();
                ans.push_back(node->val);
                if (node->right) s.push(node->right);
            }
        }
        */
        
        return ans;
    }
    
    vector<int> inorderTraversal_morris(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        auto cur = root;
        TreeNode* pre = nullptr;
        while (cur) {
            if (!cur->left) {
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else {
                pre = cur->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = cur;
                pre = cur;
                cur = cur->left;
                pre->left = nullptr;
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

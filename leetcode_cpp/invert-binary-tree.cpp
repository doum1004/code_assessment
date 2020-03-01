#include <iostream>
#include <cassert>

#include <vector>
#include <stack>

#include "../tree.h"

using namespace std;

/**
https://leetcode.com/problems/invert-binary-tree/

// Solution1. Recursion. DSF inorder
// time: o(n)
// space: o(n)
node* recursion(node*)
    if (!node) return nullptr
    auto l = recursion(node->left);
    auto r = recursion(node->right);
    node->left = r;
    node->right = l;
    return node;
    
// Solution2. Iteration BSF with queue
// time: o(n)
// space: o(n)
BSF
q: (4)
swap 4-left, 4-right
q: (2) 7
swap 2-left, 2-right
q: (7) 1 3 6 9


*/
class Solution {
public:
    TreeNode* invertTree_recursion(TreeNode* root) {
        if (!root) return nullptr;
        auto l = invertTree_recursion(root->left);
        auto r = invertTree_recursion(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
    
    TreeNode* invertTree_iteration(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            auto t = node->left;
            node->left = node->right;
            node->right = t;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        //return invertTree_recursion(root);
        return invertTree_iteration(root);
    }
};

int main()
{
    auto input1 = new TreeNode(4);
    input1->left = new TreeNode(2);
    input1->left->left = new TreeNode(1);
    input1->left->right = new TreeNode(3);
    input1->right = new TreeNode(7);
    input1->right->left = new TreeNode(6);
    input1->right->right = new TreeNode(9);
    auto ans = Solution().invertTree(input1);
    assert(ans->left->val == 7 && ans->left->left->val == 9);

    return 0;
}

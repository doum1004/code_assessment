#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

// https://leetcode.com/problems/validate-binary-search-tree/

// [2 1 3]
// recursion (DFS inorder)
// time: o(n)
// space: o(n)

// isValidBST(node, mintree, maxtree)
// if (node == null) return true
// if (!isValidBST(node->left, mintree, node) return false
// if (node->val > min->val && node->val < max->val)
// if (!isValidBST(node->right, node, maxtree)
// isValidBST(root, nullptr, nullptr)

// iterative (BFS inorder)
// time: o(n)
// space: o(n) stack

// min_v = INT64_MIN
// stack<int> s
// while (!s.empty() || r != nullptr)
// if (r != nullptr)
//   s.push(r)
//   r = r->left
// else
//   r = s->top(); s->pop();
// if (min_v <= r->val) return false;
// min_v = r->val
// r = r->right

// stack 2 1
//       r
// min_v = r->val
// r = r->right


class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) return true;

        if (!isValidBST(root->left, min, root)) return false;
        if (min != nullptr && min->val >= root->val) return false;
        if (max != nullptr && max->val <= root->val) return false;
        if (!isValidBST(root->right, root, max)) return false;

        return true;
    }

    bool isValidBST_I(TreeNode* root) {
        auto min_v = INT64_MIN;
        stack<TreeNode*> s;

        while (!s.empty() || root != nullptr) {
            if (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top();
                s.pop();

                if (min_v >= root->val) return false;

                min_v = root->val;
                root = root->right;
            }
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST_I(root);
        //return isValidBST(root, nullptr, nullptr);
    }
};

int main()
{
    auto input1 = vectorToTree(vector<int>{2,1,3});
    assert(Solution().isValidBST(input1)
        == true);

    // assert(isValidBST(
    //     new TreeNode(vector<int>{2,1,3}))
    //     == true);
    // assert(isValidBST(
    //     new TreeNode(vector<int>{5,1,4,-1,-1,3,6}))
    //     == false);
    // assert(isValidBST(
    //     new TreeNode(vector<int>{2147483647}))
    //     == true);
    // assert(isValidBST(
    //     new TreeNode(vector<int>{-2147483648, -1, 2147483647}))
    //     == true);
    return 0;
}
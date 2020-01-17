#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include "../utils.h"
#include "../tree.h"

using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//      3(l, r)
//   5      1
// 6   2   0  8
//   7   4
// p=5, q=1

// DFS (postorder)
// 3(t) 1(t)
// time: o(n)
// space: o(n) recursion

//      3(l, r)
//   5      1
// 6   2   0  8
//   7   4
// p=5, q=4

// DFS
// 3, 5(t) 2, 4(t)

// TreeNode* ans;
// bool lca(root, p, q)
//      if (root == nullptr) return 0;
//      int left = lca(root->left, p, q);
//      int right = lca(root->right, p, q);
//      int mid = (root == p || root == q) ? 1 : 0;
//      if (mid + left + right >= 2)
//          ans = root;
//      return (mid + left + right > 0);
// lca(root, p, q)
// return ans;

class Solution {
private:
    TreeNode* ans;
    bool lca(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr) return false;
        
        auto l = lca(node->left, p, q) ? 1 : 0;
        auto r = lca(node->right, p, q) ? 1 : 0;
        auto mid = (node == p || node == q) ? 1 : 0;
        if (l + r + mid >= 2) {
            this->ans = node;
        }
        
        return l + r + mid > 0;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root, p, q);
        return ans;
    }
};

int main()
{
    return 0;
}
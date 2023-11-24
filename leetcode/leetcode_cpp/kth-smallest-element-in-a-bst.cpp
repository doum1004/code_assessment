/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst

Solution1. DSF with vector (visit left, root, right)
time: o(n)
space: o(n)

Solution2. DSF without extra vector (visit left, root, right)
time: o(n)
space: o(n)

*/

class Solution {
public:
    // solution2
    int dsf(TreeNode* root, int& k) {
        if (!root) return -1;

        int result = dsf(root->left, k);
        if (result < 0 && --k == 0) result = root->val;
        if (result < 0) result = dsf(root->right, k);

        return result;
    }
    int kthSmallest(TreeNode* root, int k) {
        return dsf(root, k);
    }
};
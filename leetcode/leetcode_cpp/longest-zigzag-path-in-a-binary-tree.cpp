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
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

1. DFS (passing left, right count)
time: o(n)
space: o(n)
*/
class Solution {
public:
    void dfs(TreeNode* node, int l, int r, int& res) {
        if (!node) return;
        res = max(res, max(l, r));
        dfs(node->left, r + 1, 0, res);
        dfs(node->right, 0, l + 1, res);
    }
    int longestZigZag(TreeNode* root) {
        int res = 0;
        dfs(root, 0, 0, res);
        return res;
    }
};
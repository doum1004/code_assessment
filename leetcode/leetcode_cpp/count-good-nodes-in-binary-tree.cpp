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
 https://leetcode.com/problems/count-good-nodes-in-binary-tree
 
 1. DFS preorder
 time: o(n)
 space: o(n)
 */
class Solution {
public:
    int res = 0;
    void dfs(const TreeNode* root, int cur) {
        if (!root) return;
        if (root->val >= cur) {
            res += 1;
            cur = root->val;
        }
        dfs(root->left, cur);
        dfs(root->right, cur);
    }
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        dfs(root, root->val);
        return res;
    }
};
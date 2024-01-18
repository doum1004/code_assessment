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
 https://leetcode.com/problems/search-in-a-binary-search-tree
 
 1. DFS preorder
 time: o(n)
 space: o(n)

 2. Iteration
 time: o(n)
 space: o(1)
 */
class Solution {
public:
    TreeNode* searchBST_1(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        if (root->val < val) return searchBST(root->right, val);
        return searchBST(root->left, val);
    }
    TreeNode* searchBST_2(TreeNode* root, int val) {
        while (root && root->val != val) {
            root = root->val < val ? root->right : root->left;
        }
        return root;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return searchBST_2(root, val);
    }
};
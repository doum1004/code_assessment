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
 https://leetcode.com/problems/flatten-binary-tree-to-linked-list

 1. dfs (post order)
 2. no recursion and stack(queue)
 
 */
class Solution {
public:
    void dfs(TreeNode* node) {
        if (!node) return;
        
        // left
        dfs(node->left);
        dfs(node->right);
        
        if (node->left) {
            auto cur = node->left;
            while (cur->right) cur = cur->right;
            cur->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
    }
    
    void flatten_1(TreeNode* root) {
        dfs(root);
    }

    void flatten_2(TreeNode* root) {
        while (root) {
            if (root->left && root->right) {
                auto t = root->left;
                while (t->right)
                    t = t->right;
                t->right = root->right;
            }

            if (root->left) {
                root->right = root->left;
            }
            root->left = nullptr;
            root = root->right;
        }
    }

    void flatten(TreeNode* root) {
        flatten_2(root);
    }
};
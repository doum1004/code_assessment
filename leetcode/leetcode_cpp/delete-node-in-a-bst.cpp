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
https://leetcode.com/problems/delete-node-in-a-bst

1. DFS recursion to find node and delete (replace node or value)
time: o(n)
space: o(n)
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        if (root->val < key) root->right = deleteNode(root->right, key);
        else if (root->val > key) root->left = deleteNode(root->left, key);
        else {
            auto toDelete = root;
            if (!root->right) root = root->left;
            else if (!root->left) root = root->right;
            else {
                auto next = root->right;
                while (next->left) next = next->left;
                root->val = next->val;
                root->right = deleteNode(root->right, root->val);
                toDelete = nullptr;
            }
            delete toDelete;
        }
        return root;
    }
};
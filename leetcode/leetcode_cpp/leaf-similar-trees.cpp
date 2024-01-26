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
 https://leetcode.com/problems/leaf-similar-trees
 
 1. DFS and store leaf node in vector. And compare later
 time: o(n)
 space: o(n)
 */
class Solution {
public:
    void storeLeafNode(TreeNode* node, vector<int>& store) {
        if (!node) return;
        if (!node->left && !node->right)
            store.push_back(node->val);
        storeLeafNode(node->left, store);
        storeLeafNode(node->right, store);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> store1;
        vector<int> store2;
        storeLeafNode(root1, store1);
        storeLeafNode(root2, store2);
        return store1 == store2;
    }
};
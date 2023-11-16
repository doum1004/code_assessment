/*
https://leetcode.com/problems/minimum-absolute-difference-in-bst

Solution1. DFS. get sorted list from DFS
time: o(n)
space: o(n)

*/

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

class Solution {
public:
    void dfs(TreeNode* node, vector<int>& values) {
        if (!node) return;
        if (node->left) a(node->left, values);
        values.push_back(node->val);
        if (node->right) a(node->right, values);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        a(root, values);
        
        int m = INT_MAX;
        for (int i=1; i<values.size(); ++i)
            m = std::min(m, std::abs(values[i-1] - values[i]));
        return m;
    }
};
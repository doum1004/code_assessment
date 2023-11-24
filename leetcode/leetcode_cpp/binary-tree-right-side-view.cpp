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
https://leetcode.com/problems/binary-tree-right-side-view

Solution1. Recursion (DSF, middle, right, left)
time: o(n)
space: o(n)

1. dsf. preorder and add value
 */
class Solution {
public:
    unordered_map<int, int> m;
    void dsf_1(TreeNode* node, int level) {
        if (!node) return;

        dsf_1(node->left, level+1);
        m[level] = node->val;
        dsf_1(node->right, level+1);
    }

    vector<int> rightSideView_1(TreeNode* root) {
        dsf_1(root, 0);
        vector<int> res;
        for (int i=0; i<m.size(); ++i) {
            res.push_back(m[i]);
        }
        return res;
    }

    void dsf_2(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;
        if (res.size() <= level)
            res.push_back(node->val);

        dsf_2(node->right, level+1, res);
        dsf_2(node->left, level+1, res);
    }

    vector<int> rightSideView_2(TreeNode* root) {
        vector<int> res;
        dsf_2(root, 0, res);
        return res;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        return rightSideView_2(root);
    }
};
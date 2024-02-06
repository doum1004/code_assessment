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
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

1. DFS (passing level)
time: o(n)
space: o(n)

2. BFS
time: o(n)
space: o(n)
*/
class Solution {
public:
    void dfs(TreeNode* node, int level, unordered_map<int, int>& m) {
        if (!node) return;
        m[level] += node->val;
        dfs(node->left, level+1, m);
        dfs(node->right, level+1, m);
    }
    int maxLevelSum_1(TreeNode* root) {
        unordered_map<int, int> m;
        dfs(root, 1, m);
        int res = 0;
        int res_val = INT_MIN;
        for (int i=1; i<=m.size(); ++i) {
            if (res_val < m[i]) {
                res = i;
                res_val = m[i];
            }
        }
        return res;
    }
    int maxLevelSum_2(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        vector<int> m;
        int res = 0;
        int res_val = INT_MIN;
        while (!q.empty()) {
            int qSize = q.size();
            m.push_back(0);
            for (int i=0; i<qSize; ++i) {
                auto node = q.front().first;
                auto level = q.front().second;
                q.pop();
                m.back() += node->val;
                if (node->left) q.push({node->left, level+1});
                if (node->right) q.push({node->right, level+1});
            }
            if (res_val < m.back()) {
                res_val = m.back();
                res = m.size();
            }
        }
        return res;
    }
    int maxLevelSum(TreeNode* root) {
        return maxLevelSum_2(root);
    }
};
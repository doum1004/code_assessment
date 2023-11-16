/*
https://leetcode.com/problems/average-of-levels-in-binary-tree

Solution1. DFS with list
time: o(n)
space: o(n)

Solution2. BFS with queue or stack
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
    vector<pair<double,int>> l;
    void dfs(TreeNode* node, int level) {
        if (!node) return;

        if (l.size() <= level) l.push_back({node->val, 1});
        else {
            l[level].first += node->val;
            l[level].second += 1;
        }

        dfs(node->left, level+1);
        dfs(node->right, level+1);
    }

    vector<double> averageOfLevels_dfs(TreeNode* root) {
        if (!root) return {};

        dfs(root, 0);
        vector<double> res(l.size());
        for (int i=0; i<l.size(); ++i) {
            res[i] = (double)l[i].first / l[i].second;
        }

        return res;
    }

    vector<double> averageOfLevels_bfs(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<double> res;
        while (q.size()) {
            int qSize = q.size();
            double sum = 0;
            for (int i=0; i<qSize; ++i) {
                auto node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(sum/qSize);
        }

        return res;
    }

    vector<double> averageOfLevels(TreeNode* root) {
        return averageOfLevels_bfs(root);
    }
};
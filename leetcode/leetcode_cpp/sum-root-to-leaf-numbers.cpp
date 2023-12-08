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
 https://leetcode.com/problems/sum-root-to-leaf-numbers
 
 Solution1-2. DFS / BFS
 time: o(n)
 space: o(n)
 */
class Solution {
public:
    int sumNumbers_DFS(TreeNode* node, int cur) {
        if (!node) return 0;
        if (!node->left && !node->right) return cur + node->val;

        cur = (cur + node->val) * 10;
        int val = sumNumbers_DFS(node->left, cur);
        val += sumNumbers_DFS(node->right, cur);
        return val;
    }

    int sumNumbers_1(TreeNode* root) {
        return sumNumbers_DFS(root, 0);
    }

    int sumNumbers_2(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int ans = 0;
        while (!q.empty()) {            
            auto value = q.front(); q.pop();
            auto node = value.first;
            auto val = value.second;
            if (!node) continue;

            val = (val * 10) + node->val;
            if (!node->left && !node->right) {
                ans += val;
            }
            if (node->left) q.push({node->left, val});
            if (node->right) q.push({node->right, val});
        }
        return ans;
    }

    int sumNumbers(TreeNode* root) {
        return sumNumbers_2(root);
    }
};
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
 Soultion1. Recursion. (DSF, Path sum)
 time: o(n)
 space: o(n)
 
 */
class Solution {
public:
    bool hasPathSum_1(TreeNode* node, int targetSum, int sum) {
        if (!node) return false;
        sum += node->val;
        if (!node->left && !node->right) return sum == targetSum;
        return hasPathSum_1(node->left, targetSum, sum) or hasPathSum_1(node->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSum_1(root, targetSum, 0);
    }
};